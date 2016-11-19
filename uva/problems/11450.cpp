#include <bits/stdc++.h>

using namespace std;

int t,m,c;
int garment[21][21];
int memo[201][21];

int pd(int v, int g){

	if(v < 0) return -1;
	if(c == g) return m - v;
	if(memo[v][g] != -1) return memo[v][g];

	for(int i = 1; i <= garment[g][0]; ++i){
		memo[v][g] = max(memo[v][g], pd(v - garment[g][i], g + 1 ));
	}

	return memo[v][g];
}

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d %d", &m, &c);

		for(int i = 0; i < c; ++i){
			scanf("%d", &garment[i][0]);
			for(int j = 1; j <= garment[i][0]; ++j){
				scanf("%d", &garment[i][j]);
			}
		}

		memset(memo, -1, sizeof memo);

		int result = pd(m, 0);
		if(result > 0) printf("%d\n", result);
		else printf("no solution\n");
	}
	
	return 0;
}