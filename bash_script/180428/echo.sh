#! /bin/sh

BASE_NAME=`basename $0`
echo ${BASE_NAME}

DIR_PATH=$(dirname $0)
echo ${DIR_PATH}

BUILD_DIR=${BUILD_DIR:-build}
BUILD_TYPE=${BUILD_TYPE:-debug}

echo ${BUILD_DIR}
echo ${BUILD_TYPE}

PQ_INCLUDE_PATH=$(dirname $(dpkg-query -L libpq-dev | grep libpq-fe.h))
echo ${PQ_INCLUDE_PATH}
