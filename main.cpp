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
	QuickFind qf(10);
	qf.Print();
	qf.Union(3, 4);
	PrintSplitter();
	qf.Union(4, 7);
	qf.Print();
	return 0;
}