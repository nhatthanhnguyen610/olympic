#include <iostream>
using namespace std;

void chuyen(int n,char A,char B,char C)
{
	if (n==1)
	 cout << "Chuyen 1 dia tu " << A << " sang " << C << endl;
	else
	{
		chuyen(n-1,A,C,B);
		chuyen(1,A,' ',C);
		chuyen(n-1,B,A,C);
	}
}
int main()
{
	int n;
	cout << "Nhap so dia: ";
	cin >> n;
	chuyen(n,'A','B','C');
	return 0;
}