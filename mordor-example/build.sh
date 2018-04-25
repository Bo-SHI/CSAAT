#!/bin/sh
set -e

SCRIPT_PATH=$(dirname $0)
SOURCE_DIR=`pwd`
BUILD_DIR=${BUILD_DIR:-build}
BUILD_TYPE=${BUILD_TYPE:-debug}
SCRIPT_NAME=`basename $0`

# get proper job num based on hardware stats
maxJobs=4

memGbMin=2
memKb=$(grep MemTotal /proc/meminfo | awk '{ print $2 }')
if [ $memKb -lt $(($memGbMin*1024*1024)) ]; then
    echo "[$SCRIPT_NAME] Total memory less than $memGbMin GB, set max jobs to 2"
    maxJobs=2
fi

jobNum=$(grep processor /proc/cpuinfo | wc -l)
if [ $jobNum -gt $maxJobs ]; then
    jobNum=$maxJobs
fi
echo "[$SCRIPT_NAME] Total compiling job num is : $jobNum"

# start compilation
mkdir -p $BUILD_DIR/$BUILD_TYPE \
  && cd $BUILD_DIR/$BUILD_TYPE \
  && cmake -DCMAKE_BUILD_TYPE=$BUILD_TYPE $SOURCE_DIR -DBoost_NO_BOOST_CMAKE=ON\
  && make -j${jobNum} \
  && cp bin/* $SOURCE_DIR -f
