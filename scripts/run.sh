#!/bin/sh
source common/init.sh

if [ "$1" = "server" ]; then
    $RUN $MOUNT_PATH/build/server
elif [ "$1" = "client" ]; then
    $RUN $MOUNT_PATH/build/client
fi
