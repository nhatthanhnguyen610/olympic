#include "pch.h"
#include <iostream>
#include <fstream>	
using namespace std;
ifstream fi("basket_b.inp");
ofstream fo("basket_b.out");

int n;
pair<int, int> f[10001];
int d1 = 0, d2 = 0;
int t1 = 0, t2 = 0;
int result[5] = { 0 };

int main()
{
	fi >> n;
	for (int i = 1;i <= n;i++)
	{
		char ch;
		int tam;
		fi >> f[i].first;
		fi >> f[i].second;
		fi >> ch;
		fi >> tam;
		f[i].second = f[i].second * 60 + tam;
	}

	n++;
	f[n].second = 2880;

	for (int i = 1;i < n;i++)
	{
		if (f[i].first == 1)
			d1++;
		if (f[i].first == 2)
			d2++;
		if (d1 > d2)
			t1 = t1 + (f[i+1].second - f[i].second);
		if (d2 > d1)
			t2 = t2 + (f[i+1].second - f[i].second);
	}

	result[1] = t1 / 60;
	result[2] = t1 % 60;
	result[3] = t2 / 60;
	result[4] = t2 % 60;

	for (int i = 1;i <= 4;i++)
	{
		int tam = result[i];
		if (tam < 10)
			fo << 0;
		fo << tam;
		if (i % 2 != 0)
			fo << ":";
		else
			fo << endl;
	}

	fi.close();
	fo.close();

	return 0;
}