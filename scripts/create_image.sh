#!/bin/sh
source common/init.sh
docker build --tag=$DOCKER_IMAGE ..
