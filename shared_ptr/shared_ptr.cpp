#include "include.hpp"
template<typename T>
void shared_ptr<T>::ptr_delete(){
    _control->count--;
    if(_control->count == 0){
        delete _ptr;
    }
}
template<typename T>
shared_ptr<T>:: shared_ptr(T * locptr) noexcept : _ptr(locptr){
    _control = new control_ptr{1};
}
template<typename T>
shared_ptr<T>::shared_ptr(const &shared_ptr locobj )_ptr(locobj._ptr){
    _control = &locobj._control;
    _control->int++;
}
template<typename T>
shared_ptr<T>::shared_ptr(&&shared_ptr locobj)_ptr(locobj._ptr){
     _control = &locobj._control;
     locobj._control = nullptr;
}
template<typename T>
shared_ptr<T>::shared_ptr operator=(const &shared_ptr locobj){
    ptr_delete();
    _ptr = locobj.ptr;
    _control = &locobj._control;
    _control->int++;
}
template<typename T>
shared_ptr<T>::shared_ptr operator=(&&shared_ptr locobj){
    ptr_delete();
    _ptr = locobj.ptr;
    _control = &locobj._control;
    _control->count++;
    locobj.ptr_delete();
}

int shared_ptr:: use_count(){
    return _control->count;
}

template<typename T>
shared_ptr<T>::T* get() const noexcept{
    return _ptr;
}
template<typename T>
shared_ptr<T>::T& operator*() const noexcept{
    return *_ptr;
}
template<typename T>
shared_ptr<T>::T& operator->() const noexcept{
    return _ptr;
}
shared_ptr::~shared_ptr(){

}