#ifndef UP_HPP
#define UP_HPP

#include <iostream>

template <typename T>
class unique_ptr
{
private:
    T *ptr;
public:
    explicit unique_ptr(T *locptr = nullptr) noexcept;
    unique_ptr(unique_ptr &&locptr) noexcept;
    unique_ptr& operator=(unique_ptr &&locptr) noexcept;
    void reset(T *ptr = nullptr);
    T *release() noexcept;
    void swap(unique_ptr &other) noexcept;
    T* get() const;
    T& operator*() const;
    T* operator->() const noexcept;
    ~unique_ptr();
};

#endif