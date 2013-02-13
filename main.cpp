#include "uf.h"
#include <iostream>
#include <iomanip>

using namespace drc;
using namespace std;

void PrintSplitter() {
	cout << setfill('=') << setw(40) << '=' << endl << setfill(' ');
}

int main(int argc, char const *argv[])
{
	QuickUnionWeighted qf(10);
	qf.Print();
	//1-5 2-4 7-9 0-3 1-9 4-6 3-2 1-0 2-8
	qf.Union(1, 5);
	qf.PrintData();
	qf.Union(2, 4);
	qf.PrintData();
	qf.Union(7, 9);
	qf.PrintData();
	qf.Union(0, 3);
	qf.PrintData();
	qf.Union(1, 9);
	qf.PrintData();
	qf.Union(4, 6);
	qf.PrintData();
	qf.Union(3, 2);
	qf.PrintData();
	qf.Union(1, 0);
	qf.PrintData();
	qf.Union(2, 8);
	qf.PrintData();
	return 0;
}