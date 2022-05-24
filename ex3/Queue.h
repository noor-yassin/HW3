#include<iostream>
#define ZERO 0
template<class T>
class Queue
{
public:
	Queue(int size=ZERO);
	~Queue();
	Queue(const Queue&);
	void pushBack(const T&);
	T& front();
	const T& front() const;
	void popFront();
	int size() const;

private:
	T* m_arr;
	int m_size;
};
template<class T>
Queue<T>::Queue(int size)
{
	m_size = size;
	if (m_size == 0)
	{
		m_arr = nullptr;
	}
	else
	{
		m_arr = new T[m_size];
	}
}
template<class T>
Queue<T>::~Queue()
{
	delete[] m_arr;
}

template<class T>
Queue<T>::Queue(const Queue& q1)
{
	m_size = q1.m_size;
	for (int i = 0; i < m_size; i++)
	{
		m_arr[i] = q1.m_arr[i];
	}
}
template<class T>
void Queue<T>::pushBack(const T&)
{
	int new
}
