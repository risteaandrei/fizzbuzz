#!/bin/sh
source common/init.sh
docker run -i -t  -v $(PWD)/..:$MOUNT_PATH $DOCKER_IMAGE /bin/bash
