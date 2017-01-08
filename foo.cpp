#include "foo.hpp"

Foo* Foo::foo = nullptr;

void Foo::add_handler(int id, const std::function<void()>& func) {
    handlers.emplace(id, func);
}

void Foo::call_handler(int id) {
    handlers[id]();
}

