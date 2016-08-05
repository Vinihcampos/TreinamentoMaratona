#include <bits/stdc++.h>

using namespace std;

int main(){
	
	string zeros_ones;
	int lista[1000000];
	int queries, x, y;
	bool problem;
	int count = 0;
	while(cin>>zeros_ones){
		for(int i = 0; i < zeros_ones.length(); ++i){
			if(i == 0) 
				lista[i] = 1;
			else	
				if(zeros_ones[i] == zeros_ones[i-1])
					lista[i] = lista[i-1];
				else
					lista[i] = lista[i-1] + 1;
		}
		cout<<"Case "<<++count<<":\n";
		cin>>queries;
		for(int i = 0; i < queries; ++i){
			cin>>x>>y;
			if(lista[x] == lista[y])
				cout<<"Yes\n";
			else
				cout<<"No\n";
		}
	}

	return 0;
}
