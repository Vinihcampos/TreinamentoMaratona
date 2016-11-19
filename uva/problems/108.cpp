#include <bits/stdc++.h>

using namespace std;

int m[100][100];
int n;

int max_sum_2d(){
	int max_ = 	INT_MIN;
	pair<int,int> s, f;
	for(int i = 0; i < n; ++i)
	for(int j = 0; j < n; ++j)
	for(int k = i; k < n; ++k)
	for(int l = j; l < n; ++l){
		int curr = m[k][l];
		if(i > 0) curr -= m[i-1][l];
		if(j > 0) curr -= m[k][j-1];
		if(i > 0 && j > 0) curr += m[i-1][j-1];		
		max_ = max(curr, max_);
	}
	return max_;
}

int main(){
	
	while(scanf("%d", &n) != EOF){
		for(int i = 0; i < n; ++i)
		for(int j = 0; j < n; ++j){
			scanf("%d", &m[i][j]);
			if(i > 0) m[i][j] += m[i-1][j];
			if(j > 0) m[i][j] += m[i][j-1];
			if(i > 0 && j > 0) m[i][j] -= m[i-1][j-1];
		}
		printf("%d\n", max_sum_2d());
	}	

	return 0;
}