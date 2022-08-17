#pragma once

template <typename T>
Vector<T>::Vector() :m_size(0), m_cap(1), m_ptr(nullptr) {}

template <typename T>
Vector<T>::Vector(int count) : m_size(0), m_cap(count), m_ptr(new T[m_cap]) {}

template <typename T>
Vector<T>::Vector(int count,const T& val):m_cap(count)
{
	m_ptr = new T[m_cap];
	m_size = m_cap;
	for (int i = 0;i < m_size;++i)
	{
		ptr[i] = val;
	}
}

template <typename T>
Vector<T>::Vector(std::initializer_list<T> val)
{
	for (auto i = val.begin();i != val.end();++i)
	{
		push_back(*i);
	}
}

template <typename T>
Vector<T>::Vector(const Vector& ob) :m_size(ob.m_size), m_cap(ob.m_cap), m_ptr{}
{
	if (!ob.empty())
	{
		m_ptr = new T[m_cap];
		for (int i = 0;i < m_size;++i)
		{
			m_ptr[i] = ob.m_ptr[i];
		}
	}
}

template <typename T>
Vector<T>::Vector(Vector&& ob)
{
	m_size = ob.m_size;
	m_cap = ob.m_cap;
	m_ptr = ob.m_ptr;
	ob.m_ptr = nullptr;
}

template <typename T>
Vector<T>::~Vector()
{
	if (!empty())
	{
		delete[] m_ptr;
	}
}

template <typename T>
Vector<T>& Vector<T>::operator=(const Vector& rgs)
{
	if (this == &rgs)
	{
		return *this;
	}
	m_size = rgs.m_size;
	m_cap = rgs.m_cap;
	if (!empty())
	{
		delete[] m_ptr;
	}
	m_ptr = new T[m_cap];
	for (int i = 0;i < m_size;++i)
	{
		m_ptr[i] = rgs.m_ptr[i];
	}
	return *this;
}

template <typename T>
Vector<T>& Vector<T>::operator=(Vector&& src)
{
	if (!empty())
	{
		delete[] m_ptr;
	}
	m_size = src.m_size;
	m_cap = src.m_cap;
	m_ptr = src.m_ptr;
	src.m_ptr = nullptr;
	return *this;
}

template <typename T>
T& Vector<T>::operator[](size_t index)
{
	return m_ptr[index];
}

template <typename T>
const T& Vector<T>::operator[](size_t index) const
{
	return m_ptr[index];
}

template <typename T>
void Vector<T>::insert(size_t pos, const T& val)
{
	if (this->empty())
	{
		m_ptr = new T[m_cap];
		m_ptr[0] = val;
	}
	else if (m_size != m_cap)
	{
		for (int i = m_size - 1;i >= pos;--i)
		{
			m_ptr[i + 1] = m_ptr[i];
		}
		m_ptr[pos] = val;
		++m_size;
	}
	else
	{
		m_cap *= 2;
		T* tmp = new T[m_cap];
		for (int i = 0;i < m_size;++i)
		{
			tmp[i] = m_ptr[i];
		}
		tmp[pos] = val;
		for (int i = m_size - 1;i >= pos;--i)
		{
			tmp[i + 1] = m_ptr[i];
		}
		delete[] m_ptr;
		m_ptr = tmp;
		tmp = nullptr;
		++m_size;
	}
}

template <typename T>
void Vector<T>::insert(size_t pos,T&& val)
{
		if (this->empty())
		{
			m_ptr = new T[m_cap];
			m_ptr[0] = std::move(val);
		}
		else if (m_size != m_cap)
		{
			for (int i = m_size - 1;i >= pos;--i)
			{
				m_ptr[i + 1] = m_ptr[i];
			}
			m_ptr[pos] = std::move(val);
			++m_size;
		}
		else
		{
			m_cap *= 2;
			T* tmp = new T[m_cap];
			for (int i = 0;i < m_size;++i)
			{
				tmp[i] = m_ptr[i];
			}
			tmp[pos] = std::move(val);
			for (int i = m_size - 1;i >= pos;--i)
			{
				tmp[i + 1] = m_ptr[i];
			}
			delete[] m_ptr;
			m_ptr = tmp;
			tmp = nullptr;
			++m_size;
		}
}

template <typename T>
void Vector<T>::push_back(const T& val)
{
	if (m_size == m_cap)
	{
		m_cap *= 2;

		T* tmp = new T[m_cap];
		for (int i = 0;i < m_size;++i)
		{
			tmp[i] = m_ptr[i];
		}
		delete m_ptr;
		m_ptr = tmp;
		tmp = nullptr;
	}
		m_ptr[m_size] = val;
		++m_size;
	
}

template <typename T>
void Vector<T>::pop_back()
{
	if (!this->empty())
	{
		--m_size;
	}
}

template <typename T>
void Vector<T>::erase(size_t pos)
{
	if (!this->empty())
	{
		for (int i = pos;i < m_size;++i)
		{
			m_ptr[i] = m_ptr[i+1];
		}
		--m_size;
	}
}

template <typename T>
bool Vector<T>::empty() const
{
	if (m_ptr == nullptr)
	{
		return true;
	}
	return false;
}

template <typename T>
size_t Vector<T>::size() const
{
	return m_size;
}

template <typename T>
size_t Vector<T>::capacity() const
{
	return m_capacity;
}

template <typename T>
void Vector<T>::resize(size_t new_cap)
{
	if (m_cap < new_cap)
	{
		m_cap = new_cap;
		if (this->empty())
		{
			m_ptr = new T[m_cap];
		}
		else
		{
			T* tmp = new T[m_cap];
			{
				tmp[i] = m_ptr[i];
			}
			delete[] m_ptr;
			m_ptr = tmp;
			tmp = nullptr;
		}
		m_size = m_cap;
	}
}

template <typename T>
T& Vector<T>::at(size_t index)
{
	if (index >= m_size)
	{
		throw std::out_of_range("");
	}
	if (!this->empty())
	{
		return m_ptr[index];
	}
}

template <typename T>
const T& Vector<T>::at(size_t index) const
{
	if (index >= m_size)
	{
		throw std::out_of_range("");
	}
	if (!this->empty())
	{
		return m_ptr[index];
	}
}

template <typename T>
void Vector<T>::shrink_to_fit()
{
	if (!this->empty())
	{
		if (m_size != m_cap)
		{
			m_cap = m_size;


			T* tmp = new T[m_cap];
			for (int i = 0;i < m_size;++i)
			{
				tmp[i] = m_ptr[i];
			}
			delete[] m_ptr;
			m_ptr = tmp;
			tmp = nullptr;
		}
	}
}

template <typename T>
void Vector<T>::clear()
{
	if (!this->empty())
	{
		delete[] m_ptr;
		m_cap = 1;
		m_size = 0;
	}
}