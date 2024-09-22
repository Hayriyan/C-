#include <iostream>

template <typename T>
class unique_ptr
{
private:
    T *ptr;

public:
    unique_ptr(T *locptr) noexcept
    {
        ptr = locptr https://github.com/Hayriyan/C-.git;
    }
    unique_ptr(unique_ptr &&locptr) noexcept
    {
        this->ptr = locptr.ptr;
        locptr.ptr = nullptr;
    }
    unique_ptr& operator=(unique_ptr &&locptr)
    {
        delete this->ptr;
        this->ptr = locptr.ptr;
        locptr.ptr = nullptr;
    }

    void reset(T *ptr = nullptr)
    {
        delete this->ptr;
        this->ptr = ptr;
    }

    T *release() noexcept
    {
        T *tmp = this->ptr;
        this->ptr = nullptr;
        return tmp;
    }
    void swap(unique_ptr &other) noexcept
    {
        T *tmp = this->ptr;
        this->ptr = other.ptr;
        other.ptr = tmp;
    }
    T* get(){
        return this->ptr;
    }
    T& operator*() const{
        return *this->ptr;
    }
    T* operator->() const noexcept{
        return this->ptr;
    }
};

int main(){

    unique_ptr<int> a = new int;
    *a = 5;
    std::cout << *a << std::endl;
    return 0;
}