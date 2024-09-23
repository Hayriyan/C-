#include "include.hpp"

int main(void) {
    shared_ptr<int> a(new int);
    *a = 5;
    std::cout << *a << std::endl;
    return 0;
}