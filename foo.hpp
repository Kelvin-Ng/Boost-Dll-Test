#include <iostream>
#include <functional>
#include <unordered_map>
#include <string>

class Foo {
public:
    void add_handler(int id, const std::function<void()>& func);
    void call_handler(int id);

    static Foo& get_instance() {
        if (foo == nullptr) {
            foo = new Foo;
        }
        return *foo;
    }

    ~Foo() {
        std::cout << "~Foo()" << std::endl;
    }

protected:
    Foo() = default;
    static Foo* foo;

    std::unordered_map<int, std::function<void()>> handlers;
};

