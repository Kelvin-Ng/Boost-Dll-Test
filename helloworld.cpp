#include <boost/dll.hpp>

#include <iostream>
#include <vector>
#include <functional>

class HelloWorldHandlers {
public:
    HelloWorldHandlers() : i(0) {}

    ~HelloWorldHandlers() {
        std::cout << "~HelloWorldHandlers()" << std::endl;
    }
    
    void handler_0() {
        std::cout << i << " Hello world handler 0" << std::endl;
        ++i;
    }

    void handler_1() {
        std::cout << i << " Hello world handler 1" << std::endl;
        ++i;
    }

protected:
    int i;
};

extern "C" std::vector<std::pair<int, std::function<void()>>> get_helloworld_handler() {
    HelloWorldHandlers* helloworld_handlers = new HelloWorldHandlers;
    std::vector<std::pair<int, std::function<void()>>> handlers;
    handlers.emplace_back(0, std::bind(&HelloWorldHandlers::handler_0, helloworld_handlers));
    handlers.emplace_back(1, std::bind(&HelloWorldHandlers::handler_1, helloworld_handlers));
    return handlers;
}

