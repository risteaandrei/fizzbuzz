#!/bin/sh

if [ "$1" = "server" ]; then
    PORT="11234"
    source common/init.sh
    $RUN $MOUNT_PATH/build/server
elif [ "$1" = "client" ]; then
    PORT="11235"
    source common/init.sh
    $RUN $MOUNT_PATH/build/client
fi
