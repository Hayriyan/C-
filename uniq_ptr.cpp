#include "include.hpp"

template <typename T>
unique_ptr<T>::unique_ptr(T *locptr) noexcept
    : ptr(locptr) {}

template <typename T>
unique_ptr<T>::unique_ptr(unique_ptr &&locptr) noexcept
    : ptr(locptr.ptr) {
    locptr.ptr = nullptr;
}

template <typename T>
unique_ptr<T>& unique_ptr<T>::operator=(unique_ptr &&locptr) noexcept {
    if (this != &locptr) {
        delete this->ptr;
        this->ptr = locptr.ptr;
        locptr.ptr = nullptr;
    }
    return *this;
}

template <typename T>
void unique_ptr<T>::reset(T *ptr) {
    delete this->ptr;
    this->ptr = ptr;
}

template <typename T>
T* unique_ptr<T>::release() noexcept {
    T *tmp = this->ptr;
    this->ptr = nullptr;
    return tmp;
}

/* be cautoius using this */
template <typename T>
void unique_ptr<T>::swap(unique_ptr &other) noexcept {
    T *tmp = this->ptr;
    this->ptr = other.ptr;
    other.ptr = tmp;
}

template <typename T>
T* unique_ptr<T>::get() const {
    return this->ptr;
}

template <typename T>
T& unique_ptr<T>::operator*() const {
    return *this->ptr;
}

template <typename T>
T* unique_ptr<T>::operator->() const noexcept {
    return this->ptr;
}

template <typename T>
unique_ptr<T>::~unique_ptr() {
    delete this->ptr;
}

template class unique_ptr<int>;