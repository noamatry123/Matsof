#include <iostream>
#include <vector>
using namespace std;
template <class T>
class parr {
private:
	vector<T> _arr;
public:
	parr()
	{
		_arr = vector<T>();
	}
	void push_back(T item)
	{
		_arr.push_back(item);
	}
	T& operator[] (int x)
	{
		if (x >= _arr.size())
			throw exception("Vector subscript out of range ;(");
		return _arr[x];
	}
};