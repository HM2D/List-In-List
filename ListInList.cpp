#include "stdafx.h"
#include <iostream>

using namespace std;

template<class t>
class List
{
protected:
	int count;
	int size;
	t* numbers;
	void extend()
	{
		 t* numbers = new t[2 * size];
		for (int i = 0; i<count; i++)
			numbers[i] = this->numbers[i];
		delete[] this->numbers;
		this->numbers = numbers;
		size *= 2;
	}
public:

	operator t()
	{
		return count;
	}
	t& operator [](int index)
	{
		return numbers[index];
	}
	void operator() (t x, int index)
	{
		insert(x, index);
	}
	t operator ++()
	{
		int sum = 0;
		for (int i = 0; i<count; i++)
			sum += (numbers[i]++);
		return sum;
	}


	int operator!()
	{
		return count;
	}
	t operator %(int num)
	{
		return find(num);
	}
	void operator +(t x)
	{
		add(x);
	}

	int getCount()
	{
		return count;
	}

	List(int n = 10)
	{
		count = 0;
		numbers = new t[n];
		size = n;
	}
	~List()
	{
		delete[] numbers;
	}

	void operator= (List& l)
	{
		count = l.count;
		delete[] numbers;
		numbers = new t[count];
		memcpy(numbers, l.numbers, count*sizeof(t));
	}

	void add(int num)
	{
		if (size == count)
			extend();
		numbers[count++] = num;
	}

	int find(t num)
	{
		for (int i = 0; i<count; i++)
		if (numbers[i] == num)
			return i;
		return -1;
	}

	t getitem(int index)
	{
		return numbers[index];
	}
	void insert(t num, int index)
	{
		if (count == size)
		{
			extend();
		}
		if (index <= -1)
		{
			cout << "Index should be non-negative." << endl;
			return;
		}
		if (index>count)
			index = count;
		for (int i = count - 1; i >= index; i--)
			numbers[i + 1] = numbers[i];
		numbers[index] = num;
		count++;
	}


};
template<class f>
class matrix:public List<f>
{
	List* matrice;
	int index;
	int size;
	void extend()
	{
		List* numbers = new List[2 * size];
		for (int i = 0; i<count; i++)
			numbers[i] = this->numbers[i];
		delete[] this->numbers;
		this->numbers = numbers;
		size *= 2;
	}
public:
	matrix<f>(int n=10)
	{
		index = 0;
		matrice = new List[n];
			size = n;
	};
	void init(List<f>&  l)
	{
		matrice[index] = l;
		index++;
	}
	void print(int n)
	{
		for (int j = 0; j < index; j++)
		{
			for (int i = 0; i < matrice[n].getCount(); i++)
				cout << matrice[j].getitem(i) << "\t";
			cout << endl;
		}
	}
	void insert(f num, int index)
	{
		if (index == size)
		{
			extend();
		}
		if (index <= -1)
		{
			cout << "Index should be non-negative." << endl;
			return;
		}
		if (index>count)
			index = count;
		for (int i = count - 1; i >= index; i--)
			numbers[i + 1] = numbers[i];
		numbers[index] = num;
		count++;
	}
	void find(f n)
	{
		int flag = false;
		for (int j = 0; j < index; j++)
		{
			for (int i = 0; i < matrice[j].getCount(); i++)
			if (matrice[j].getitem(i) == n)
				cout << "Found in row " << j << "Column " << i << endl,
			flag = true;
		}
		if (flag == false)
			cout << "Not found " << endl;

	}
	int getsizerow(int n)
	{
		return matrice[n].getCount();
	}
	int getsizecolumn()
	{
		return index;
	}
};


int main()
{
	List<double> h;
	h.add(3);
	h.add(5);
	h.add(3);
	h.add(5);
	h.add(3);
	h.add(5);
	List<double> l;
	l.add(3);
	l.add(4);
	l.add(5);
	l.add(3);
	l.add(3);
	matrix<double> j;
	j.init(l);
	j.init(h);
	j.print(0);
	j.find(10);
	cout << j.getsizerow(0) << endl;
	cout << j.getsizecolumn() << endl;
}