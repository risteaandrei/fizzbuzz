MOUNT_PATH="/src"
BUILD_DIR="build"
BUILD_PATH="$MOUNT_PATH/$BUILD_DIR"
DOCKER_IMAGE="risteaandrei/ubuntu_cpp_gtest"
RUN="docker run -i --rm -v $(PWD)/..:$MOUNT_PATH $DOCKER_IMAGE bash -c "