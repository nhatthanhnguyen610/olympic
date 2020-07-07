#include <iostream>
using namespace std;
int dau,cuoi;
int maxsum = 0;
int max(int a, int b)
{
	if (a>=b)
		return a;
	return b;
}
void largestSum(int a[], int n)
{
	int sum = 0;
	dau = 0;
	for (int i=0;i<n;i++)
	{
		sum = max(0,sum+a[i]);
		if (sum<=0)
			dau = i+1;
		if (sum>maxsum)
		{
			maxsum = max(sum,maxsum);
			cuoi = i;
		}	
	}
}
int main()
{
	int a[30];
	int n;
	cout << "Nhap so phan tu: ";
	cin >> n;
	for (int i=0;i<n;i++)
		cin >> a[i];
	largestSum(a,n);
	cout << maxsum << endl;
	cout << dau << " " << cuoi << endl;
	return 0;
}