#ifndef ARRAY
#define ARRAY

class Array
{
	int* pArr;
	int size;
	int capacity;
public:
	Array();
	Array(const Array&);
	Array& operator=(const Array&);
	~Array();

	int getSize() const;
	void push_back(int);
	void pop(int);
	int getAt(int) const;
	void setAt(int, int);
private:
	void copyElements(const Array&);
	void setSize(int);
};

#endif // !ARRAY
