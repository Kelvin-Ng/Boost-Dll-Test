#include "foo.hpp"

#include <iostream>
#include <vector>
#include <string>

#include <boost/dll.hpp>

int main() {
    Foo& foo = Foo::get_instance();

    boost::dll::shared_library hello_world_lib("libhelloworld.so");

    std::function<std::vector<std::pair<int, std::function<void()>>>()> get_helloworld_handler = hello_world_lib.get<std::vector<std::pair<int, std::function<void()>>>()>("get_helloworld_handler");

    for (auto& hello_world_handler : get_helloworld_handler()) {
        foo.add_handler(hello_world_handler.first, hello_world_handler.second);
    }

    foo.call_handler(0);
    foo.call_handler(1);
}

