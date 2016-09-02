#include <bits/stdc++.h>

using namespace std;

int main(){
	
	int n,m,input, count = 0;
	set<int> cds;
	
	while(scanf("%d %d", &n, &m) != EOF && n != 0 && m != 0){
		count = 0;
		cds.clear();
		
		for(int i = 0; i < n; ++i){
			cin>>input;
			cds.insert(input);
		}

		for(int i = 0; i < m; ++i){
			cin>>input;
			if(cds.find(input) != cds.end()) ++count;
		}

		cout<<count<<endl;
	}
	

}