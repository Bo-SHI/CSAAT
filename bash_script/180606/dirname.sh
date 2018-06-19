#! /bin/bash
set -e

SCRIPT_PATH=`dirname $0`
echo ${SCRIPT_PATH}

GOCMD="go"
if ! which go; then
    GOCMD="/usr/local/go/bin/go"
fi
$GOCMD version >/dev/null
