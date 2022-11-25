#include <iostream>
using namespace std;

class mycode {


	char* string = nullptr;

	int gsize(const char* str) {
		int size = 0;
		for (int i = 0; str[i] != '\0'; i++)
		{
			size++;
		}
		return size;
	}


public:


	mycode() = default;

	mycode(const char* str) {
		sstirng(str);
	}



	void sstirng(const char* str) {
		delete[] string;
		int len = strlen(str) + 1;
		string = new char[len];
		strcpy_s(string, len, str);
	}

	const char* GetString() const {
		return string;
	}



	char FirstChar() const {
		return string[0];
	}

	char LastChar() const {
		int size = 0;
		for (int i = 0; string[i] != '\0'; i++)
		{
			size++;
		}
		return string[size - 1];
	}

	void Append(const char* s) {
		if (string != nullptr)
		{
			int size = gsize(string);
			int sizes = gsize(s);
			char* temp = new char[size + sizes];
			for (int i = 0; i < size; i++)
			{
				temp[i] = string[i];
			}
			int j = 0;
			for (int i = size; i < size + sizes; i++)
			{
				temp[i] = s[j];
				j++;
			}
			temp[size + sizes] = '\0';
			sstirng(temp);
		}
		else {
			sstirng(s);
		}
	}

	int find(const char s) {
		int size = gsize(string) - 1;
		int j = 0;
		for (int i = size; i >= 0; i--)
		{
			if (s == string[i]) {
				return j;
			}
			j++;
		}
	}

	int Find(const char s) {
		int size = gsize(string) - 1;
		for (int i = 0; i <= size; i++)
		{
			if (s == string[i]) {
				return i;
			}
		}
	}

	void clear() {
		delete[] string;
	}




};



class iarray {
	int size = 5;
	int* arr = new int[size] {1, 2, 3, 4, 5};
public:



	iarray() = default;

	iarray(int s)
	{
		size = s;
		arr = new int[s] {};
	}

	iarray(const iarray& obj)
	{
		delete[] arr;
		size = obj.size;
		arr = new int[size] {};
		for (int i = 0; i < size; i++) {
			arr[i] = obj.arr[i];
		}
	}





	void AppendBefore(int num) {
		int* temp = new int[size + 1]{};
		temp[0] = num;
		for (int i = 0; i <= size; i++)
		{
			temp[i + 1] = arr[i];
		}
		delete[] arr;
		arr = temp;
		temp = nullptr;
		size++;
	}

	void AppendAfter(int num) {
		int* temp = new int[size + 1]{};
		for (int i = 0; i < size; i++)
		{
			temp[i] = arr[i];
		}
		temp[size] = num;
		delete[] arr;
		arr = temp;
		temp = nullptr;
		size++;
	}

	void Print() {
		for (int i = 0; i < size; i++)
		{
			cout << arr[i] << " ";
		}
	}



};

void main() {
	iarray arr;
	arr.AppendBefore(1);
	arr.AppendBefore(2);
	arr.AppendBefore(3);
	arr.Print();
}