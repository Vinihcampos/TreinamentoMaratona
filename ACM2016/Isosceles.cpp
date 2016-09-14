#include <bits/stdc++.h>

using namespace std;

int col[50002];
int heightL[50002];
int heightR[50002];
int max_;

int main(){
	
	int n;
	scanf("%d", &n);
	max_ = 1;

	for(int i = 0; i <= n + 1; ++i){
		if(i == 0 || i == n + 1){
			col[i] = 0;
			heightL[i] = 0;
			heightR[i] = 0;
		}else{
			cin>>col[i];
			heightL[i] = 1;
			heightR[i] = 1;
		}
	}

	for(int i = 1; i <= n; ++i){
		if(heightL[i-1] <= col[i]){
			if(heightL[i-1] + 1 == col[i]) heightL[i] = col[i];
			else if(heightL[i-1] == col[i]) heightL[i] = heightL[i-1];
			else heightL[i] = heightL[i-1] + 1; 			
		}else{
			heightL[i] = col[i];
		}
	}

	for(int i = n; i > 0; --i){
		if(heightR[i+1] <= col[i]){
			if(heightR[i+1] + 1 == col[i]) heightR[i] = col[i];
			else if(heightR[i+1] == col[i]) heightR[i] = heightR[i+1];
			else heightR[i] = heightR[i+1] + 1; 			
		}else{
			heightR[i] = col[i];
		}

		max_ = max(max_, min(heightR[i], heightL[i]));
	}

	printf("%d\n", max_);	

	return 0;
}