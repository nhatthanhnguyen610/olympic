#include "pch.h"
#include <iostream>
using namespace std;

// var
int x, y;
int u, v;
int dx[8] = { -1,-2,-2,-1,1,2,2,1 };
int dy[8] = { 2,1,-1,-2,-2,-1,1,2 };
int kt[5][5] = { 0 };
int dem = 0;

void Try(int i)
{
	for (int j = 0;j < 8;j++)
	{
		u = x + dx[j];
		v = y + dy[j];
		if (u>=0 && u<5 && v>=0 && v<5 && kt[u][v] == 0)
		{
			x = u;
			y = v;
			kt[x][y] = i;
			if (i == 25)
				dem++;
			else
				Try(i + 1);
				kt[x][y] = 0;
				x -= dx[j];
				y -= dy[j];
		}
	}
}
int main()
{
	cin >> x >> y;
	kt[x][y] = 1;
	Try(2);
	cout << dem << endl;
	return 0;
}