#include "include.hpp"

int main() {
    block<int>* blk = new block<int>(new int(10));
    Intrusive_ptr<int> p1(blk);
    Intrusive_ptr<int> p2(p1);  
    Intrusive_ptr<int> p3(std::move(p1));  

    std::cout << p2.use_count() << std::endl;
    std::cout << *p2 << std::endl;

    return 0;
}