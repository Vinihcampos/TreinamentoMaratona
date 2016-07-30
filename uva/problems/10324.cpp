#include <bits/stdc++.h>

using namespace std;

int main(){
	
	string zeros_ones;
	int queries, x, y;
	int count = 0;
	bool problem;
	while(cin>>zeros_ones){
		cout<<"Case "<<++count<<":\n";
		cin>>queries;
		for(int i = 0; i < queries; ++i){
			cin>>x>>y;
			if(x == y)
				cout<<"Yes\n";
			else{
				if(y < x)
					swap(x,y);
				problem = false;
				for(int j = x; j < y; ++j){
					if(zeros_ones[j] != zeros_ones[y]){
						problem = true;
					}
				}
				if(problem) cout<<"No\n";
				else cout<<"Yes\n";
			}
		}
	}

	return 0;
}