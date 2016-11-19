#include <bits/stdc++.h>

using namespace std;

long long memo[101][101];

long long pd(long long n, long long k){
	if(n < 0 || k < 1) return 0;
	if(memo[n][k] != -1){
		return memo[n][k]%1000000;
	}
	memo[n][k] = 0;
	for(long long i = 0; i <= n; ++i){
		memo[n][k] += pd(n-i, k-1);
	}
	return memo[n][k] = memo[n][k]%1000000;
}

int main(){
	
	memset(memo, -1, sizeof memo);
	for(long long i = 0; i <= 100; ++i) 
		memo[i][1] = 1;

	long long n, k;
	while(cin>>n>>k){
		if(n == 0 && k == 0) break;
		cout<<pd(n,k)%1000000<<endl;
	}

	return 0;
}