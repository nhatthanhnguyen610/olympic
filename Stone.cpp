#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

ifstream fi("stone.inp");
ofstream fo("stone.out");
vector <int> v;
vector <int> f(8*1000001);
int m, n, k;
int c, p, d, q;


void tinh()
{
	for (int i=0;i<m;i++)
	{
		int tam = v[i];
		for (int j=7;j>=0;j--)
		{
			if (tam & 1)
				f[i*8+j] = 1;
			tam >>= 1;
		}
	}
}

void xoa()
{
	int begin, end;
	begin = (7-p) + 8 * c;
	end = (7-q) + 8 * d;
	for (int i=begin;i<=end;i++)
		f[i] = 0;
}

int main()
{
	fi >> m >> n >> k;
	int x;
	for (int i=0;i<m;i++)
	{
		fi >> x;
		v.push_back(x);
	}

	tinh();

	for (int i=0;i<n;i++)
	{
		fi >> c >> p >> d >> q;
		xoa();
	}

	for (int i=0;i<k;i++)
	{
		fi >> c >> p >> d >> q;
		/*int from, to;
		from = (7-p) + 8 * c;
		to = (7-q) + 8 * d;
		if (max_element(f[from],f[to])==1)
			cout << "YES" << endl;
		else
			cout << "PASS" << endl;*/
	}

	return 0;
}