#include<iostream>
template<class T>
class Queue
{
public:
	Queue(int size=0);
	~Queue();
	Queue(const Queue&);
	void pushBack(const T&);
	T& front();
	const T& front() const;
	void popFront();
	int size() const;
	template<class Operation> void transform(Queue,Operation op);

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
		try
		{
			m_arr = new T[m_size];
		}
	    catch (const std::bad_alloc& e) 
		{
			std::cerr << e.what() << std::endl;
	    }
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
    m_arr = new T[m_size];
	for (int i = 0; i < m_size; i++)
	{
		m_arr[i] = q1.m_arr[i];
	}
}
template<class T>
void Queue<T>::pushBack(const T& t)
{
	if (m_arr != nullptr)
	{
	    T* temp = new T[m_size];
		for (int i = 0; i < m_size; i++)
			temp[i] = m_arr[i];
		m_size++;
		delete[] m_arr;
		try
		{
			m_arr = new T[m_size];
		}
		catch (const std::bad_alloc& e)
		{
			std::cerr << e.what() << std::endl;
			delete[] temp;
			throw;
		}
		for (int i = 0; i < m_size - 1; i++)
			m_arr[i] = temp[i];
		m_arr[m_size - 1] = t;
		delete[] temp;
	}
	else
	{
		m_size++;
		m_arr = new T[m_size];
		m_arr[m_size - 1] = t;
	}
}

template<class T>
T& Queue<T>::front()
{
	return m_arr[0];
}

template<class T>
const T& Queue<T>::front() const
{
	return m_arr[0];
}

template<class T>
void Queue<T>::popFront()
{
	if (m_size > 1)
	{
		m_size = m_size - 1;
		T* temp = new T[m_size];
		for (int i = 1; i <= m_size; i++)
		{
			temp[i - 1] = m_arr[i];
		}
		delete[] m_arr;
		try
		{
			m_arr = new T[m_size];
		}
		catch (const std::bad_alloc& e)
		{
			std::cerr << e.what() << std::endl;
			delete[] temp;
		}
		for (int i = 0; i < m_size; i++)
		{
			m_arr[i] = temp[i];
		}
		delete[] temp;
	}
	else
	{
		delete[] m_arr;
		m_size = 0;
	}
}

template<class T>
int Queue<T>::size()const
{
	return m_size;
}

template<class T, class Condition>
Queue<T> filter(const Queue<T>& q1,Condition c)
{
	Queue<T> temp(q1);
	Queue<T> result;
	while (temp.size() > 0)
	{
		if (c(temp.front()))
			result.pushBack(temp.front());
		temp.popFront();
	}
	return result;
}

/*template<class T> 
template<class Operation>
void Queue<T>::transform(Queue queue,Operation op)const
{
  for(T& element:queue)
  {
	  op(element);
  }
}*/

template<class T> 
template<class Operation>
void Queue<T>::transform(Queue queue,Operation op)
{
	Queue<T> temp(queue);
  while(temp.size()>0)
  {
	  op(temp.front());
	  temp.popFront();
  }
  delete [] queue;
  queue =new T[temp.size()];
  for(int i=0;i<queue.size();i++)
  {
	  queue[i]=temp[i];
  }
  delete [] temp;
}
