#include <bits/stdc++.h>

using namespace std;

int kadane(int v[], int sz){
	int curr = 0;
	int final_ = 0;

	for(int i = 0; i < sz; ++i){
		curr = max(0, curr + v[i]);
		final_ = max(curr, final_);
	}

	return final_;
}

int main(){
	
	int sz;
	int v[10000];

	while(cin>>sz && sz != 0){
		for(int i = 0; i < sz; ++i) cin>>v[i];
		int r = kadane(v, sz);
		if(r > 0)
			cout<<"The maximum winning streak is "<<r<<".\n";
		else
			cout<<"Losing streak.\n";
	}

	return 0;
}