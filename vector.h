#pragma once


template <typename T>
class Vector
{
public:
	Vector();
	Vector(int);
	Vector(int,const T&);
	Vector(std::initializer_list<T>);
	Vector(const Vector&);
	Vector(Vector&&);
	~Vector();
public:
	Vector& operator=(const Vector&);
	Vector& operator=(Vector&&);
	T& operator[](size_t);
	const T& operator[](size_t) const;
public:
	void insert(size_t,const T&);
	void insert(size_t, T&&);
	void push_back(const T&);
	void pop_back();
	void erase(size_t);
	T& at(size_t);
	const T& at(size_t) const;
	bool empty() const;
	size_t size() const;
	size_t capacity() const;
	void resize(size_t);
	void clear();
	void shrink_to_fit();
private:
	size_t m_size;
	size_t m_cap;
	T* m_ptr;
};
#include "vector.hpp"