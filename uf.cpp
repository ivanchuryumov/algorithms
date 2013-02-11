#include "uf.h"
#include <iostream>
#include <iomanip>

using namespace drc;
using namespace std;

DynamicConnectivity::DynamicConnectivity(const int size)
: arraySize(size) {
	array = new int[arraySize];
	for(int i = 0; i < arraySize; ++i) {
		array[i] = static_cast<int>(i);
	}
}

DynamicConnectivity::~DynamicConnectivity() {
	if(array) {
		delete[] array;
		array = 0;
	}
}

void DynamicConnectivity::Print() const {
	cout << left << setw(10) << "Indexes:" << right;
	for (int i = 0; i < arraySize; ++i)	{
		cout << setw(3) << i;
	}
	cout << endl << left << setw(10) << "Data:" << right;;
	for (int i = 0; i < arraySize; ++i)	{
		cout << setw(3) << array[i];
	}
	cout << endl;
}

QuickFind::QuickFind(const int size)
: DynamicConnectivity(size) {
}

void QuickFind::Union(int p, int q) {
	for (int i = 0; i < arraySize; ++i) {
		if (array[p] == array[i]) {
			array[i] = array[q];
		}
	}
}

const bool QuickFind::Connected(int p, int q) const{
	return array[p] == array[q];
}
