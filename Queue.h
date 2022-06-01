#include <iostream>
template <class T>
class Queue
{
public:
/**
 * @brief Construct a new Queue object
 * 
 * @param size - the size of the Queue it constructs,
 * if it doesnt recieve any, the deafult value-(0) will be assigned to the Queue's size. 
 */
	Queue(int size = 0);

	/**
	 * @brief Destroy the Queue object
	 * 
	 */
	~Queue();

	/**
	 * @brief copy constructor-Construct a new Queue object,
	 * as a copy of an existing one
	 * 
	 */
	Queue(const Queue &);

	/**
	 * @brief adds an element to the last of the queue
	 * 
	 */
	void pushBack(const T &);

	/**
	 * @brief returns the first element of the queue 
	 * 
	 * @return T&- the first elemetn of thequeue
	 */
	T &front();
	const T &front() const;

	/**
	 * @brief removes the first element from the queue
	 * 
	 */
	void popFront();

	/**
	 * @brief returns the size of the queue
	 * 
	 * @return int- the size of the queue
	 */
	int size() const;

	/**
	 * @brief assignment operator- assigns an object to an existing one 
	 * @param Queue&- the object we want to assing
	 * @return Queue& - the object after assigning.
	 */
	Queue &operator=(const Queue &);
    
	/**
	 * @brief contains the functions that let us itarate on a queue elements
	 * 
	 */
	class Iterator;

	/**
	 * @brief contains the functions that let us itarate on a const queue elements
	 * 
	 */
	class ConstIterator;

	/**
	 * @brief returns an iterator to the first element of the queue
	 *
	 * @return Iterator- a pointer to first element of the queue
	 */
	Iterator begin()
	{
		return Iterator(this, 0);
	}

    /**
	 * @brief returns an iterator to the last element of the queue
	 *
	 * @return Iterator- a pointer to last element of the queue
	 */
	Iterator end()
	{
		return Iterator(this, size());
	}

    /**
	 * @brief returns an iterator to the first element of the const queue
	 *
	 * @return Iterator- a pointer to first element of the const queue
	 */
	ConstIterator begin() const
	{
		return ConstIterator(this, 0);
	}

    /**
	 * @brief returns an iterator to the last element of the const queue
	 *
	 * @return Iterator- a pointer to last element of the const queue
	 */
	ConstIterator end() const
	{
		return ConstIterator(this, size());
	}

	class EmptyQueue
	{
	};

private:
	T *m_arr;
	int m_size;
};

template <class T>
class Queue<T>::Iterator
{
public:
/**
 * @brief Construct a new Iterator object as a copy of an existing one
 * 
 */
	Iterator(const Iterator &) = default;

	/**
	 * @brief assigns an iterator to an existing one 
	 * @param Iterator&- the iterator we want to assign.
	 * @return Iterator& - the iterator after assigning.
	 */
	Iterator &operator=(const Iterator &) = default;

    /**
     * @brief returns the object currently pointed on.
     * 
     * @return T& - the object currently pointed on.
     */
	T &operator*();

	/**
	 * @brief- prefix ++ operator-to advance the iterator
	 * 
	 * @return Iterator& - the iterator after advancing it.
	 */
	Iterator &operator++();

		/**
	 * @brief- postfix ++ operator-to advance the operator
	 * 
	 * @return Iterator& - the iterator before advancing it.
	 */
	Iterator operator++(int);

	/**
	 * @brief compares iterators
	 * 
	 * @param it- the iterator we want to compare with 
	 * @return true - if the iterators are equal
	 * @return false - if the iterators are'nt equal
	 */
	bool operator==(const Iterator &it) const;

	/**
	 * @brief compares iterators
	 * 
	 * @param it- the iterator we want to compare with 
	 * @return true - if the iterators are'nt equal
	 * @return false - if the iterators are equal
	 */
	bool operator!=(const Iterator &it) const;

	class InvalidOperation
	{
	};

private:
	Queue<T> *queue;
	int index;
	Iterator(Queue<T> *queue, int index) : queue(queue), index(index)
	{
	}
	friend class Queue<T>;
};

template <class T>
class Queue<T>::ConstIterator
{
public:
/**
 * @brief Construct a new const Iterator object as a copy of an existing one,
 * 
 * 
 */
	ConstIterator(const ConstIterator &) = default;

	/**
	 * @brief assigns a const iterator to an existing const one -not the value of the iterator!
	 * @param Iterator&- the iterator we want to assign.
	 * @return Iterator& - the const iterator after assigning.
	 */
	ConstIterator &operator=(const ConstIterator &) = default;

    /**
     * @brief returns the const object currently pointed on.
     * 
     * @return T& - the const object currently pointed on.
     */
	const T &operator*() const;

	/**
	 * @brief- prefix ++ operator-to advance the iterator-to a const object
	 * 
	 * @return Iterator& - the iterator that points to a const object after advancing it.
	 */
	ConstIterator &operator++();

	/**
	 * @brief- postfix ++ operator-to advance the iterator-to a const object
	 * 
	 * @return Iterator& - the iterator that points to a const object before advancing it.
	 */
	ConstIterator operator++(int);
	/**
	 * @brief compares const iterators
	 * 
	 * @param it - the const iteartor we want to compare with
	 * @return true - if the iterators are equal
	 * @return false - if the iterators are'nt equal
	 */
	bool operator==(const ConstIterator &it) const;

	/**
	 * @brief -compares const iterators
	 * 
	 * @param it - the const iterator we want to compare with
	 * @return true - if the iterators are'nt equal
	 * @return false - if the iterators are equal
	 */
	bool operator!=(const ConstIterator &it) const;

	class InvalidOperation
	{
	};

private:
	const Queue<T> *queue;
	int index;
	ConstIterator(const Queue<T> *queue, int index) : queue(queue), index(index)
	{
	}
	friend class Queue<T>;
};

template <class T>
Queue<T>::Queue(int size)
{
	m_size = 0;
	m_arr = nullptr;
}
template <class T>
Queue<T>::~Queue()
{
	delete[] m_arr;
}

template <class T>
Queue<T>::Queue(const Queue &q1)
{
	m_size = q1.m_size;
	if (m_size == 0)
	{
		m_arr = nullptr;
	}
	else
	{
		m_arr = new T[m_size];
		for (int i = 0; i < m_size; i++)
		{
			m_arr[i] = q1.m_arr[i];
		}
	}
}
template <class T>
void Queue<T>::pushBack(const T &t)
{
	T add = t;
	if (m_arr != nullptr)
	{
		T *temp = new T[m_size + 1];
		for (int i = 0; i < m_size; i++)
			temp[i] = m_arr[i];
		m_size++;
		delete[] m_arr;
		m_arr = temp;
		m_arr[m_size - 1] = add;
	}
	else
	{
		m_size++;
		m_arr = new T[m_size];
		m_arr[m_size - 1] = t;
	}
}

template <class T>
T &Queue<T>::front()
{
	if (m_arr == nullptr)
		throw EmptyQueue();
	return *m_arr;
}

template <class T>
const T &Queue<T>::front() const
{
	return m_arr[0];
}

template <class T>
void Queue<T>::popFront()
{
	if (m_size > 1)
	{
		m_size = m_size - 1;
		T *temp = new T[m_size];
		for (int i = 1; i <= m_size; i++)
		{
			temp[i - 1] = m_arr[i];
		}
		delete[] m_arr;
		m_arr = temp;
	}
	else
	{
		if (m_size == 1)
		{
			delete[] m_arr;
			m_arr = nullptr;
			m_size = 0;
		}
		else
		{
			throw EmptyQueue();
		}
	}
}

template <class T>
int Queue<T>::size() const
{
	return m_size;
}

template <class T>
Queue<T> &Queue<T>::operator=(const Queue<T> &q1)
{
	m_size = q1.m_size;
	if (m_size == 0)
	{
		m_arr = nullptr;
	}
	else
	{
		delete[] m_arr;
		m_arr = new T[m_size];
		for (int i = 0; i < m_size; i++)
		{
			m_arr[i] = q1.m_arr[i];
		}
	}
	return *this;
}

template <class T, class Condition>
Queue<T> filter(const Queue<T> &q1, Condition c)
{
	Queue<T> temp = q1;
	Queue<T> result;
	while (temp.size() > 0)
	{
		if (c(temp.front()))
			result.pushBack(temp.front());
		temp.popFront();
	}
	return result;
}
template <class T, class Operation>
void transform(Queue<T> &queue, Operation op)
{
	Queue<T> temp;
	while (queue.size() > 0)
	{
		op(queue.front());
		temp.pushBack(queue.front());
		queue.popFront();
	}
	queue = temp;
}
// Iterator functions
template <class T>
T &Queue<T>::Iterator::operator*()
{
	return this->queue->m_arr[this->index];
}

template <class T>
typename Queue<T>::Iterator &Queue<T>::Iterator::operator++()
{
	if (this->queue->end() == *this)
	{
		throw InvalidOperation();
	}
	this->index++;
	return *this;
}

template <class T>
typename Queue<T>::Iterator Queue<T>::Iterator::operator++(int)
{
	Iterator temp = *this;
	++*this;
	return temp;
}

template <class T>
bool Queue<T>::Iterator::operator==(const Iterator &it) const
{
	if (queue == it.queue)
		return index == it.index;
	return false;
}

template <class T>
bool Queue<T>::Iterator::operator!=(const Iterator &it) const
{
	return !(*this == it);
}

// ConstIterator functions
template <class T>
const T &Queue<T>::ConstIterator::operator*() const
{
	return this->queue->m_arr[this->index];
}

template <class T>
typename Queue<T>::ConstIterator &Queue<T>::ConstIterator::operator++()
{
	if (this->queue->end() == *this)
	{
		throw InvalidOperation();
	}
	this->index++;
	return *this;
}

template <class T>
typename Queue<T>::ConstIterator Queue<T>::ConstIterator::operator++(int)
{
	ConstIterator temp = *this;
	++*this;
	return temp;
}

template <class T>
bool Queue<T>::ConstIterator::operator==(const ConstIterator &it) const
{
	if (queue == it.queue)
		return index == it.index;
	return false;
}

template <class T>
bool Queue<T>::ConstIterator::operator!=(const ConstIterator &it) const
{
	return !(*this == it);
}
