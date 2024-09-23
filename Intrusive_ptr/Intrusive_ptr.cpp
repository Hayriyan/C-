#include "include.hpp"

template<typename T>
void Intrusive_ptr<T>::ptr_delete() {
    if (_ptr) {
        _ptr->_count--;
        if (_ptr->_count == 0) {
            delete _ptr->_data;
            delete _ptr;
        }
    }
}

template<typename T>
Intrusive_ptr<T>::Intrusive_ptr(block<T>* locptr) noexcept : _ptr(locptr) {}

template<typename T>
Intrusive_ptr<T>::Intrusive_ptr(const Intrusive_ptr<T>& other) : _ptr(other._ptr) {
    if (_ptr) {
        _ptr->_count++;
    }
}

template<typename T>
Intrusive_ptr<T>::Intrusive_ptr(Intrusive_ptr<T>&& other) noexcept : _ptr(other._ptr) {
    other._ptr = nullptr;
}

template<typename T>
Intrusive_ptr<T>& Intrusive_ptr<T>::operator=(const Intrusive_ptr<T>& other) {
    if (this != &other) {
        ptr_delete();
        _ptr = other._ptr;
        if (_ptr) {
            _ptr->_count++;
        }
    }
    return *this;
}

template<typename T>
Intrusive_ptr<T>& Intrusive_ptr<T>::operator=(Intrusive_ptr<T>&& other) noexcept {
    if (this != &other) {
        ptr_delete();
        _ptr = other._ptr;
        other._ptr = nullptr;
    }
    return *this;
}

template<typename T>
int Intrusive_ptr<T>::use_count() const {
    return _ptr ? _ptr->_count : 0;
}

template<typename T>
T* Intrusive_ptr<T>::get() const noexcept {
    return _ptr ? _ptr->_data : nullptr;
}

template<typename T>
T& Intrusive_ptr<T>::operator*() const noexcept {
    return *(_ptr->_data);
}

template<typename T>
T* Intrusive_ptr<T>::operator->() const noexcept {
    return _ptr->_data;
}

template<typename T>
void Intrusive_ptr<T>::reset(block<T>* locptr) {
    ptr_delete();
    _ptr = locptr;
}

template<typename T>
Intrusive_ptr<T>::~Intrusive_ptr() {
    ptr_delete();
}