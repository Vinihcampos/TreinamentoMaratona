#include <bits/stdc++.h>	

using namespace std;

int coins[] = {1, 5, 10, 25, 50};
int v[5][7490];

int pd(){
	for(int i = 0; i < 7490; ++i)
		v[0][i] = 1;

	for(int i = 1; i < 5; ++i){
		for(int j = 0; j < 7490; ++j){
			if(j >= coins[i]){
				v[i][j] = v[i-1][j] + v[i][j - coins[i]];
			}else{
				v[i][j] = v[i-1][j];
			}
		}
	}
}


int main(){	

	pd();
	int input;
	while(scanf("%d", &input) != EOF){
		printf("%d\n", v[4][input]);
	}

	return 0;
}