#include <iostream>
using namespace std;
int n;
int *a;
int *Check;
int *Result;


int Max(int *a)
{
	int mmax = Check[1];
	for (int i = 2;i <= n;i++)
		if (Check[i] > Check[mmax])
			mmax = i;
	return mmax;
}
void Show()
{
	cout << Check[Max(Check)] << endl;
	for (int i = 1;i <= n;i++)
		if (Result[i] != 0)
			cout << Result[i] << " ";
	cout << endl;
}
void Process()
{
	for (int i = 1;i <= n;i++)
	{
		int j = 0;
		for (int h = 1;h < i;h++)
			if (Check[h] > Check[j] && a[h] < a[i])
				j = h;
		Check[i] = Check[j] + 1;
	}
	int max = Check[Max(Check)];
	int tam = a[Max(Check)];
	Result[Max(Check)] = a[Max(Check)];
	for (int i = Max(Check)-1;i >= 1;i--)
		if (Check[i] == max-1 && a[i]<tam)
		{
			Result[i] = a[i];
			max = Check[i];
			tam = a[i];
		}
}
int main()
{
	cin >> n;
	a = new int[n+1];
	for (int i = 1;i <= n;i++)
		cin >> a[i];
	Check = new int[n + 1];
	Result = new int[n + 1];
	for (int i = 0;i <= n;i++)
		Check[i] = Result[i] = 0;
	a[0] = 0;
	Process();
	Show();
	return 0;
}
    