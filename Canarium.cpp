#include <iostream>
#include <fstream>

using namespace std;

ifstream fi("Canarium.inp");
ofstream fo("Canarium.out");

int t;
long long k,m,n, resM, resN, tam;

void process()
{
	
	bool kt=false;
	tam = INT_MAX;
	for (m = sqrt(k*1.0);m>=1;m--)
	{
		n = (2*k - m - 1)/(1 + 2 * m);
		if ((m + 1) * (n + 1) + m * n == 2 * k)
		{
			if (n-m<tam )
			{
				resN = n;
				resM = m;
				tam = n - m;
			}
			kt = true;
		}
	}
	if (!kt)
	{
		resN = -1;
		resM = -1;
	}
}

int main()
{
	fi >> t;
	for (int i=0;i<t;i++)
	{
		fi >> k;
		process();
		cout << resM << " " << resN << endl;
	}
	fi.close();
	fo.close();
	return 0;
}