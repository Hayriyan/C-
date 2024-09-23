#include "include.hpp"

int main() {
    unique_ptr<int> a(new int);
    *a = 5;
    std::cout << *a << std::endl;
    return 0;
}