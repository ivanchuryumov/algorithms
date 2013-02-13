#include "uf.h"
#include <iostream>
#include <iomanip>
#include <cstring>

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
		cout << setw(2) << i;
	}
	cout << endl;
	PrintData();
}

void DynamicConnectivity::PrintData() const {
	cout << left << setw(10) << "Data:" << right;;
	for (int i = 0; i < arraySize; ++i)	{
		cout << setw(2) << array[i];
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

QuickUnion::QuickUnion(const int size)
: DynamicConnectivity(size) {
}

void QuickUnion::Union(int p, int q) {
	array[Root(p)] = Root(q);
}

const bool QuickUnion::Connected(int p, int q) const{
	return Root(p) == Root(q);
}

int QuickUnion::Root(int i) const{
	while(i != array[i]) {
		i = array[i];
	}
	return i;
}

QuickUnionWeighted::QuickUnionWeighted(const int size)
: QuickUnion(size) {
	weights = new int[arraySize];
	memset(weights, 0, arraySize*sizeof(int));
}

QuickUnionWeighted::~QuickUnionWeighted() {
	if(weights) {
		delete[] weights;
		weights = 0;
	}
}

void QuickUnionWeighted::Union(int p, int q) {
	int i = Root(p); //TODO: need to check the algorithm
	int j = Root(q);
	if(weights[i] < weights[j]) {
		array[i] = j;
		weights[j] += weights[i];
	} else {
		array[j] = i;
		weights[i] += weights[j];
	}
}
