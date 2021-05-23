#include <iostream>
#include <utility>
#include <cstdlib>
#pragma once

template<class T>
class UniquePtr {
public:
	UniquePtr();
	explicit UniquePtr(T* ptr);
	UniquePtr(const T& other) = delete;
	UniquePtr(const UniquePtr<T>& other) = delete;
	UniquePtr(UniquePtr<T>&& other) noexcept;
	~UniquePtr();

	UniquePtr<T>& operator=(const UniquePtr<T>& other) = delete;
	UniquePtr<T>& operator=(T* ptr);
	UniquePtr<T>& operator=(UniquePtr<T>&& other) noexcept;

	T& operator*() const;
	T* operator->() const;
	T* get() const;
	operator bool() const;

	// сбрасывает _ptr в nullptr
	void reset();
	// reset + присвоение нового указателя
	void reset(T* ptr);
	// "Освобождение" указателя без удаления памяти
	void release();
private:
	T* _ptr;
};
