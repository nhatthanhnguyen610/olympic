#include <iostream>
using namespace std;
int INF = 20;
int A[] = {0,2,3,5};
int T[4][12] = {0};
int m = 11;
int n = 3;


void Show()
{
	int i = n;
	int j = m;
	cout << T[i][j] << endl;
	while (j>0)
	{
		if (T[i][j]!=T[i-1][j])
		{
			cout << A[i] << " ";
			j = j - A[i];
		}
		else
		i--;
	}
}

int Min(int a, int b)
{
	return (a<=b) ? a : b;
}

void Process()
{
	for (int i=1;i<=n;i++)
		for (int j=1;j<=m;j++)
			if(j<A[i])
				T[i][j] = T[i-1][j];
			else
				T[i][j] = Min(T[i-1][j], T[i][j-A[i]] + 1);
}

int main()
{
	int i = 0;
	for (int j=0;j<=m;j++)
		T[i][j] = INF;

	Process();
	Show();
	return 0;
}