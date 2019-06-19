#include<iostream>
using namespace std;
template<class T>
class SeqList
{
public:
	SeqList(size_t capacity=3)
		:_array(new T[capacity])
		,_size(0)
		,_capacity(capacity)
	{}

	~SeqList()
	{
		if (_array)
		{
			delete[] _array;
			_array = nullptr;
			_size = 0;
			_capacity = 0;
		}
	}

	void _CheckCapacity()
	{
		if (_size == _capacity)
		{
			size_t newCapacity = 2 * _capacity;
			T* temp = new T[newCapacity];
			for (size_t i = 0; i < _size; ++i)
			{
				temp[i] = _array[i];
			}
			delete[] _array;
			_array = temp;
			_capacity = newCapacity;
		}
	}
	void PushBack(const T& data)
	{
		_CheckCapacity();
		_array[_size++] = data;
	}
	void PopBack()
	{
		if (Empty())
			return;
		--_size;
	}
	void PushFront(const T& data)
	{
		_CheckCapacity();
		for (size_t i = _size; i > 0; --i)
		{
			_array[i] = _array[i-1];
		}
		_array[0] = data;
		_size++;
	}

	void PopFront()
	{
		if (Empty())
			return;
		for (size_t i = 1; i < _size; ++i)
			_array[i-1] = _array[i];
		--_size;
	}

	void Insert(size_t pos, const T& data)
	{
		if (pos<0 || pos>_size)
			return;
		_CheckCapacity();
		for (size_t i = _size; i > pos; --i)
			_array[i] = _array[i - 1];
		_array[pos] = data;
		++_size;
	}
	//‘ÀÀ„∑˚÷ÿ‘ÿ
	T& operator[](size_t index)
	{
		return _array[index];
	}

	T& Front()
	{
		return _array[0];
	}
	size_t Size()const
	{
		return _size;
	}
	size_t Capacity()const
	{
		return _capacity;
	}

	bool Empty()const
	{
		return _size == 0;
	}

private:
	T* _array;
	size_t _size;
	size_t _capacity;
};
int main()
{
	SeqList<int> s1;
	s1.PushBack(1);
	s1.PushBack(2);
	s1.PushBack(3);
	s1.PopFront();
	s1.PushBack(4);
	s1.PopBack();
	s1.PushFront(5);
	s1.Insert(2, 7);
	
	cout << s1.Size() << endl;
	cout << s1.Capacity() << endl;
	cout << s1.Front() << endl;

	SeqList<double> s2;
	s2.PushBack(1.2);
	s2.PushBack(2.0);
	s2.PushBack(3.0);
	s2.Insert(1, 5.0);
	cout << s2.Front() << endl;

	return 0;
}