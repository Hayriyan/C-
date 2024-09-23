#ifndef HPP
#define HPP

#include <iostream>

template<typename T>
struct block {
    size_t _count;
    T* _data;

    block(T* data) : _data(data), _count(1) {}
};

template<typename T>
class Intrusive_ptr {
private:
    block<T>* _ptr;
    void ptr_delete();

public:
    explicit Intrusive_ptr(block<T>* locptr = nullptr) noexcept;
    Intrusive_ptr(const Intrusive_ptr& other);
    Intrusive_ptr(Intrusive_ptr&& other) noexcept;
    Intrusive_ptr& operator=(Intrusive_ptr&& other) noexcept;
    Intrusive_ptr& operator=(const Intrusive_ptr& other);
    int use_count() const;
    void reset(block<T>* locptr = nullptr);
    T* get() const noexcept;
    T& operator*() const noexcept;
    T* operator->() const noexcept;
    ~Intrusive_ptr();
};

#include "Intrusive_ptr.cpp"

#endif /* HPP */