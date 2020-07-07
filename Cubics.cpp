#include <iostream>
#include <algorithm>
#include <fstream>
using namespace std;

int n,k;
int a[100001];
pair<int,int> f[100001];
int len = 0;
int vt = 0;
ifstream fi("cubics.inp");
ofstream fo("cubics.out");

int main()
{
	fi >> n >> k;
	for (int i=1;i<=n;i++)
	{
		fi >> a[i];
		a[i]-=k;
		f[i].first = f[i-1].first + a[i];
		f[i].second = i;
	}
	
	sort(f+1,f+n+1);

   
	int i=1;

	while (i<=n)
	{
		int j = i+1;
		while (f[i].first==f[j].first)
			j++;
		int t = f[j-1].second - f[i].second;
		if (t>len)
		{
			len = t;
			vt = f[i].second;
		}
		i++;
	}
	
	fo << len << " " << a[vt+1]+k << endl;
	fi.close();
	fo.close();
	return 0;
}