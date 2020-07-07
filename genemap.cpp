#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

ifstream fi("genemap.inp");
ofstream fo("genemap.out");

int n,k;
vector<string> s;
vector<string> smoi;

void bienDoi(string s){
	string t="";
	int len = s.length();
	for (int i=0;i<len;i++){
		t+=s[i];
		t+=s[len-i-1];
	}
	smoi.push_back(t);
}

long long tinh_k (int k){
	int i=0, q=0, r= 0;
	while (i<n-1 && smoi[i].length() >= k && smoi[i+1].length()>= k && smoi[i].substr(0,k) == smoi[i+1].substr(0,k))
		q++;
	
	r = r + (q * (q+1) / 2);

	return k;	
}

int main(){
	fi >> n >> k;
	string tam;
	for (int i=0;i<n;i++){
		fi >> tam;
		s.push_back(tam);
	}

	for (int i=0;i<n;i++)
		bienDoi(s[i]);


	long long r1 = tinh_k(2*k);
	long long r2 = tinh_k(2*k + 2);
	cout << r1- r2 << endl;
	return 0;
}