#include <bits/stdc++.h>

using namespace std;

int memo[60][60];
int cuts[60];

int size, n;

int pd(int l, int r){
	if(r < l) return 0;
	if(memo[l][r] != -1) return memo[l][r];
	if(l+1 == r) return memo[l][r] = 0;

	memo[l][r] = INT_MAX;
	
	for(int i = l + 1; i < r; ++i){
		memo[l][r] = min( pd(l, i) + pd(i, r) + cuts[r] - cuts[l], memo[l][r]);
	}

	return memo[l][r];
}

int main(){
	while(scanf("%d", &size) && size != 0){
		scanf("%d", &n);
		for(int i = 1; i <= n; ++i){
			scanf("%d", &cuts[i]);
		}

		cuts[0] = 0;
		cuts[n + 1] = size;

		memset(memo, -1, sizeof memo);
		
		printf("The minimum cutting is %d.\n", pd(0, n + 1));
	}


	return 0;
}