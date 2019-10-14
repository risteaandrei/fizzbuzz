#!/bin/sh
source common/init.sh

if [ "$#" -ne 0 ]; then
    ARGS="--gtest_filter=$1"
fi

$RUN "$BUILD_PATH/runTests $ARGS"
