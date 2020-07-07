#include <iostream>
#include <fstream>
using namespace std;
int n, result=0;
int s[500001], a[500001];
ifstream fi("inverse.inp");
ofstream fo("inverse.out");

void increase (int x)
{
	while (x<=n)
	{
		s[x]++;
		x = x + (x & -x);
	}
}

int sum (int x)
{
	int res = 0;
	while (x>0)
	{
		res += s[x];
		x = x & (x-1);
	}
	return res;
}
int main()
{
	fi >> n;
	for (int i=1;i<=n;i++)
		fi >> a[i];
	increase(a[n]);
	int tmp;
	for (int i=n-1;i>=1;i--)
	{
		increase(a[i]);
		tmp = sum(a[i]-1);
		result += tmp;
	}

	fo << result;
	fo.close();
	return 0;
}