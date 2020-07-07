#include <iostream>
using namespace std;
int W[] = {0,4,1,3,4,6};
int V[] = {0,20,60,10,50,40};
int T[6][11] = {0};
int m = 10, n = 5;

void Show()
{
	int i=n;
	int j = m;
	while (T[i][j] == T[i][j-1])
		j--;
	cout << T[i][j] << endl;
	while (i>0)
	{
		if (T[i][j]!=T[i-1][j])
		{
			cout << i << " ";
			j = j-W[i];
		}
		i--;
	}
}

int Max(int a, int b)
{
	return (a>=b)? a: b;
}
void Process()
{
	for (int i=1;i<=n;i++)
		for (int j=1;j<=m;j++)
			if(j<W[i])
				T[i][j] = T[i-1][j];
			else
				T[i][j] = Max(T[i-1][j], T[i-1][j-W[i]] + V[i]);
}

int main()
{
	Process();
	Show();
	return 0;
}