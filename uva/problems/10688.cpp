#include <bits/stdc++.h>

using namespace std;

int memo[501][501];

int pd(int n, int k){

	if(memo[n][k] != -1) return memo[n][k];
	if(n <= 1) return 0;

	memo[n][k] = INT_MAX;
	for(int i = 1; i <= n; ++i){
		memo[n][k] = min(pd(i-1, k) + pd(n-i, k+i) + n*(k+i), memo[n][k]);
	}
	return memo[n][k];
}

int main(){
	
	memset(memo, -1, sizeof memo);
	int t, n, k;
	cin>>t;
	for(int i = 1; i <= t; ++i){
		cin>>n>>k;
		cout<<"Case "<<i<<": ";
		cout<<pd(n, k)<<endl;
	}

	return 0; 
}