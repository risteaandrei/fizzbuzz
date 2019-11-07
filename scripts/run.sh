#!/bin/sh

if [ "$2" = "piped" ]; then
    PORT_MAP="-p 50505:50505"
    PIPE="ncat -l -k -p 50505 | "
fi

source common.sh

if [ "$1" = "server" ]; then
    $RUN_CMD $MOUNT_PATH/build/server
elif [ "$1" = "client" ]; then
    $RUN_CMD "$PIPE $MOUNT_PATH/build/client"
elif [ "$1" = "container" ]; then
    $RUN
fi
