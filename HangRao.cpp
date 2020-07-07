#include "pch.h"
#include <iostream>
using namespace std;
int n, res = 0;
int a[10000];

void danhangrao(int x, int y, int min)
{
	
	if (x <= y)
	{
		int iMin = x;
		for (int i = x + 1; i <= y; i++)
			if (a[i] < a[iMin])
				iMin = i;
		if (a[iMin] > min)
			res += 1;
		danhangrao(x, iMin - 1, a[iMin]);
		danhangrao(iMin + 1, y, a[iMin]);
	}
	
			
}

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	danhangrao(0, n - 1, 0);
	cout << res << endl;
	return 0;
}
    