#!/bin/sh
source common/init.sh
$RUN "mkdir -p $BUILD_PATH && cd $BUILD_PATH && cmake .. && make"
