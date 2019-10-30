#include "client.h"

#include <iostream>
#include <string>

#include <boost/asio.hpp>

int main() {
    client cl("172.17.0.2", 11234);
    cl.run();
}
