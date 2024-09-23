#ifndef SHARED_HPP
#define SHARED_HPP

#include <iostream>

struct control_ptr{
    int count;
};

template<typename T>
class shared_ptr{
private:
    T* _ptr;
    control_ptr* _control;
    void ptr_delete();
public:
    explicit shared_ptr(T* ) noexcept;
    shared_ptr(const shared_ptr& );
    shared_ptr(shared_ptr&&);
    shared_ptr& operator=(shared_ptr&&);
    shared_ptr& operator=(const shared_ptr&);
    int use_count() const;
    void reset( T* );
    T* get() const noexcept;
    T& operator*() const noexcept;
    T* operator->() const noexcept;
    ~shared_ptr();
};

#include "shared_ptr.cpp"

#endif /* SHARED_PTR_HPP */