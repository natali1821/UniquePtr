#include "UniquePtr.h"

template<class T>
UniquePtr<T>::UniquePtr() {
	_ptr = nullptr;
}

template<class T>
UniquePtr<T>::UniquePtr(T* ptr) {
	_ptr = ptr;
}

template<class T>
UniquePtr<T>::UniquePtr(UniquePtr<T>&& other) noexcept{
	_ptr = std::exchange(other._ptr, nullptr);
}

template<class T>
UniquePtr<T>::~UniquePtr() {
	delete[] _ptr;
	_ptr = nullptr;
}

template<class T>
UniquePtr<T>& UniquePtr<T>::operator=(UniquePtr<T>&& other) noexcept{
	if (this != &other) {
		this->reset();
		_ptr = std::exchange(other._ptr, nullptr);
	}
	return *this;
}

template<class T>
UniquePtr<T>& UniquePtr<T>::operator=(T* ptr) {
	this->reset();
	_ptr = ptr;
	return *this;
}

template<class T>
T& UniquePtr<T>::operator*() const {
	return *_ptr;
}

template<class T>
T* UniquePtr<T>::operator->() const {
	return _ptr;
}

template<class T>
T* UniquePtr<T>::get() const {
	return _ptr;
}

template<class T>
UniquePtr<T>::operator bool() const {
	return _ptr != nullptr;
}

template<class T>
void UniquePtr<T>::reset() {
	delete[] _ptr;
	_ptr = nullptr;
}

template<class T>
void UniquePtr<T>::reset(T* ptr) {
	this->reset();
	_ptr = ptr;
}

template<class T>
void UniquePtr<T>::release() {
	_ptr = nullptr;
}
