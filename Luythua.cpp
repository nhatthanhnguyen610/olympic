#include "pch.h"
#include <iostream>
using namespace std;

int lt(int x, int n)
{
	if (n == 0)
		return 1;
	else
		return x * lt(x, n - 1);
}
int main()
{
	int x, n;
	cout << "Nhap co so: ";
	cin >> x;
	cout << "Nhap so mu: ";
	cin >> n;

	cout << x << " mu " << n << " = " << lt(x, n)%lt(10,4) << endl;

	return 0;
}