#!/bin/sh
source common.sh
$RUN_CMD "mkdir -p $BUILD_PATH && cd $BUILD_PATH && cmake .. && make"
