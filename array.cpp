#include<iostream>
using namespace std;
#include<array>

const int SIZE = 10;
template<class T>
void PrintArray(const array<T, SIZE> arr) {

	for (T m : arr) {
		cout << m << " ";
	}
	cout << endl;
}

void TestOfArray() {

	
	array<int, SIZE> arra;//put data with int type into arra
	arra = { 0,1,2,3,4,5,6,7,8,9 };
	for (int x : arra) {
		cout << x << " ";
	}
	cout << endl;

	array<string, SIZE> arrstring = { "str", "hello", "C++", "array", "vector", "deque", "list", "forward_list", "map", "set" };// store the data with string type into arrstring

	for (string str : arrstring) {
		cout << str << " ";
	}
	cout << endl;

	cout << arrstring.at(3) << endl; //use at to access the element of arrstring

	cout << arrstring[8] << endl;//use [] to access the element of arrstring

	cout << arra.front() << endl;//use front to access the first elemen

	cout << arra.back() << endl;//use back to access the last elemen

	cout << arra.data() << endl;//use data to direct access to the underlying array 

	cout << &arra << endl;

	array<string, SIZE>::iterator it = arrstring.begin();

	cout << *it << endl;// use iterator to access the element of arrstring

	for (; it != arrstring.end(); it++) {
		cout << *it << " ";
	}
	cout << endl;

	array<int, SIZE> arrb;
	if (arra == arrb) {
		cout << "arra is equal to arrb." << endl;
	}
	else {
		arrb.fill(10);// use fill to fill the arrb
	}
	for (int y : arrb) {
		cout << y << " ";
	}
	cout << endl;
	cout << "The max size of arra is: " << arra.max_size() << ". And size of arra is: " << arra.size() << endl;

	cout << "Before swap: " << endl;
	cout << "The arra is: ";
	PrintArray(arra);
	cout << "The arrb is: ";
	PrintArray(arrb);
	cout << "After swap: " << endl;
	arra.swap(arrb);//use swap to exchange arra and arrb
	cout << "The arra is: ";
	PrintArray(arra);
	cout << "The arrb is: ";
	PrintArray(arrb);
}

int main() {

	TestOfArray();

	system("pause");

	return 0;
}