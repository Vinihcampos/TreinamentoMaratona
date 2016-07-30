#include <bits/stdc++.h>

using namespace std;

int main(){
	int tests;
	int n, m;
	cin>>tests;
	for(int i = 0; i < tests; ++i){
		cin>>n>>m;
		n = ceil((n-2)/3.f);
		m = ceil((m-2)/3.f);
		cout<< n*m<<endl;
	}
	return 0;
}