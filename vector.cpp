#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>

template<class T>
void PrintVecotr(vector<T>& v);

void TestOfVector();

class Student;

int main() {

	TestOfVector();

	system("pause");

	return 0;
}

template<class T>
void PrintVecotr(vector<T>& v) {

	for (T x : v) {
		cout << x << " ";
	}

	cout << endl;
}

class Student {
	friend ostream& operator<<(ostream& os, const Student& stu);
private:
	string name;
	int age;
public:
	Student(const string& s = "None", const int n = 0) :
		name(s), age(n) {

	}
	~Student() {

	}

};

ostream& operator<<(ostream& os, const Student& stu) {

	os << "Name: " << stu.name
		<< "\tAge: " << stu.age << endl;
	return os;
}

void TestOfVector() {

	vector<int> v0; //construct an empty vector
	PrintVecotr(v0);

	vector<int> v1(3);// construct an int vector with 3 elements
	PrintVecotr(v1);

	vector<char> v2(10, 'g');//construct an char vector with 10 elements with value g
	PrintVecotr(v2);

	vector<char> v3(v2);//construct an char vector with vector v2;
	PrintVecotr(v3);

	vector<int> v4(v1.begin(), v1.end());//construct an int vector with v1 iterator
	PrintVecotr(v4);

	vector<string> v5 = { "array", "vector", "list", "map" };//construct an string vector with initializer_list
	PrintVecotr(v5);

	vector<string> v6 = v5;// construct an string vector with operator= , same to vector<char> v3(v2)
	PrintVecotr(v6);

	vector<string> v7;
	v7.assign({ "set", "unordered_map", "forward_list", "multimap", "stack" });// construct an string vector with assign
	PrintVecotr(v7);


	//Element access 
	cout << v7.at(3) << endl;//access specified element with bounds checking

	cout << v7[2] << endl;//access specified element 

	cout << v7.front() << endl;//access the first element 

	cout << v7.back() << endl; //access the last element 

	cout << v7.data() << endl; //direct access to the underlying array 

	//Iterators 
	Student s1("Jim", 18);
	Student s2 = { "Alice", 20 };
	Student s3 = { "Bob", 30 };
	Student s4;
	vector<Student> v8 = { s1, s2, s3, s4 };

	PrintVecotr(v8);

	for (vector<Student>::iterator it = v8.begin(); it != v8.end(); it++) {
		cout << *it << ""; // access elements by iterator;
	}
	
	for_each(v8.rbegin(), v8.rend(), [](const Student& s) {cout << s << " "; }); //eaccess revers elements by iterator;

	//Capacity 

	if (v8.empty()) {
		cout << "vector v8 is empty." << endl;
	}
	else {
		cout << "The v8 have " << v8.size() << " elements." << endl; 
		cout << "And the capacity of v8 is " << v8.capacity() << endl;
		cout << "And the max_size of v8 is " << v8.max_size() << endl;
	}

	if (v8.capacity() > v8.size()) {
		cout << "vector v8 have enough capacity." << endl;
	}
	else {
		v8.reserve(v8.size() + 10);
		cout << "The capacity of v8 is " << v8.capacity() << " now." << endl;
	}

	if (v8.capacity() > v8.size()) {
		cout << "The vector v8 have unused memory. Please shrink to fit." << endl;
		v8.shrink_to_fit();
	}
	else {
		cout << "The v8 have no unused memory." << endl;
	}

	cout << "The capacity of v8 is " << v8.capacity() << " now." << endl;

	//Modifiers 
	PrintVecotr(v6);
	v6.clear();
	PrintVecotr(v6);
	//vector<string>::iterator it6 = v6.begin();
	//v6.insert(v6.begin(),"deque");
	//v6.emplace(v6.begin(), "deque");
	v6.push_back("deque");
	PrintVecotr(v6);

	vector<int> v9(10, 8);
	PrintVecotr(v9);
	v9.insert(v9.begin(), 11);
	PrintVecotr(v9);
	v9.emplace(v9.begin() + 2, 12);
	PrintVecotr(v9);
	v9.erase(v9.begin(), v9.begin() + 4);
	PrintVecotr(v9);
	v9.push_back(23);
	PrintVecotr(v9);
	v9.emplace_back(80);
	PrintVecotr(v9);
	v9.pop_back();
	v9.resize(100);
	cout << "The size of v9 is: " << v9.size() << endl;

	cout << "Before swap: " << endl;
	cout << "vector v5 is: ";
	PrintVecotr(v5);
	cout << "vector v7 is: ";
	PrintVecotr(v7);
	cout << "After swap: " << endl;
	v5.swap(v7);
	cout << "vector v5 is: ";
	PrintVecotr(v5);
	cout << "vector v7 is: ";
	PrintVecotr(v7);

	//Non-member functions

	if (v5 == v7) {
		cout << "v5 is equal to v7." << endl;
	}
	else {
		cout << "v5 is not equal to v7." << endl;
	}

	sort(v5.begin(), v5.end());//default sort
	PrintVecotr(v5);
	sort(v5.begin(), v5.end(), [](string& a, string& b) { return a > b; });// sort from greater to smaller
	PrintVecotr(v5);
}