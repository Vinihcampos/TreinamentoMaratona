#include <bits/stdc++.h>

using namespace std;

int lis(vector<int> & v, int sz){
	if(sz == 0) return 0;
	
	vector<int> direct(sz), reverse(sz);

	for(int i = sz - 1; i >= 0; i--) {
		direct[i] = 1;
		for(int j = i + 1; j < sz; j++) {
			if(v[i] < v[j]) {
				direct[i] = max(direct[j] + 1, direct[i]);
			}
		}
	}
	
	for(int i = sz - 1; i >= 0; i--) {
		reverse[i] = 1;
		for(int j = i + 1; j < sz; j++) {
			if(v[i] > v[j]) {
				reverse[i] = max(reverse[j] + 1, reverse[i]);
			}
		}
	}

	int max_ = 0;

	for(int i = 0; i < sz; ++i){
		max_ = max(direct[i] + reverse[i] - 1, max_);
	}

	return max_;
}

int main(){
	
	int t,n;
	vector<int> direct(2001);
	cin>>t;
	while(t--){
		cin>>n;
		for(int i = 0, j = n - 1; i < n; ++i, --j){
			cin>>direct[i];
		}
		cout<<lis(direct, n)<<endl;
	}

	return 0;
}