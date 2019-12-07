// CPPTemplatesPointers.cpp - By Michael G. Workman
//
// This example application displays usage of VOID pointers and generic templates in C++
//
// This example application is freely distributable under terms of MIT open source license

#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>

using namespace std;

// class template for generic programming
template <class T>
class ElementList {
private:
	vector<T> elements;

public:
	void addElement(T const&); 
	T getLastElement() const;
	void outputList();
};

// addElement method
template <class T>
void ElementList<T>::addElement(T const& element) {
	elements.push_back(element);
}

// getLastElement method
template <class T>
T ElementList<T>::getLastElement() const {

	// return last element
	return elements.back();
}

// output ElementList elements
template <class T>
void ElementList<T>::outputList() {

	cout << "ElementList elements: ";
	for (typename vector<T>::iterator it = elements.begin(); it < elements.end(); it++) {
		cout << (*it) << " ";
	}
	cout << endl << endl;

}

// we use a function template for generic programming
template <typename T>
T const& Maximum(T const& a, T const& b)
{
	if (a > b) return a;
	if (b > a) return b;
}

int main()
{
	// declare vars
	int nNumber = 10;
	float fNumber = 10.01;
	char cCharArray[] = "This is an example C++ application.";

	// void pointer
	void* ptrVoid;

	// set void pointer to address of integer number, then cast to integer so it can be dereferenced
	ptrVoid = &nNumber;
	cout << endl << "Void pointer to integer address: " << ptrVoid << "\n"
		<< "dereferenced value after static cast: " << *static_cast<int*> (ptrVoid) << endl
		<< "dereferenced value after C-style cast: " << *((int*)ptrVoid) << endl << endl;

	// set void pointer to address of float number, then cast to float so it can be dereferenced
	ptrVoid = &fNumber;
	cout << "Void pointer to float address: " << ptrVoid << endl
	<< "dereferenced value after static cast: " << *static_cast<float*> (ptrVoid) << endl
	<< "dereferenced value after C-style cast: " << *((float*)ptrVoid) << endl << endl;

	// set void pointer to address of char array string, then cast to dereference
	// note with char arrays we do not dereference the pointer, but the non-pointer name of the array
	ptrVoid = &cCharArray;
	cout << "Void pointer to char array address: " << ptrVoid << endl
		<< "dereferenced value after static cast: " << static_cast<char*> (ptrVoid) << endl 
		<< "dereferenced value after C-style cast: " << (char*)ptrVoid << endl << endl;

	// after the advent of generics in C++
	// void pointers, a holdover from C programming, were no longer needed

	// vars to use with function template
	int x = 11;
	int y = 13;
	
	float i = 10.56;
	float j = 14.32;

	string k1 = "C++";
	string k2 = "Application";

	// output the results
	cout << "Maximum integer x or y: " << Maximum(x, y) << endl << endl;
	cout << "Maximum float i or j: " << Maximum(i, j) << endl << endl;
	cout << "Maximum string k1 or k2: " << Maximum(k1, k2) << endl << endl;

	// vars to use with class template
	ElementList<string> strList;
	ElementList<float> fList;
	ElementList<int> nList;

	// add string values to ElementList string object
	strList.addElement("C++");
	strList.addElement("Object Oriented");
	strList.addElement("Application");

	// add float value to ElementList float object
	fList.addElement(3.14);
	fList.addElement(13.1);
	fList.addElement(26.2);

	// add integer values to ElementList int object
	nList.addElement(3);
	nList.addElement(11);
	nList.addElement(27);

	// get the most recent string added to list
	cout << "String List last element: " << strList.getLastElement() << endl << endl;

	// get the most recent float element
	cout << "Float List last element: " << fList.getLastElement() << endl << endl;

	// get the most recent integer element
	cout << "Integer List last element: " << nList.getLastElement() << endl << endl;

	// output the string list
	strList.outputList();

	// output the integer list
	nList.outputList();

	// output the float list
	fList.outputList();

	return 0;
}


