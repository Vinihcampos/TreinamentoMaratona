#include <bits/stdc++.h>

using namespace std;

int values[1000];
int weights[1000];
int pd[1001][31];
int t, n, persons, w, sum;

int knapsack(int itens, int weight){
 	if(itens == n || weight == 0) return 0;
 	if(pd[itens][weight] != -1) return pd[itens][weight];
	if(weights[itens] > weight) return knapsack(itens + 1, weight);
	return pd[itens][weight] = max(knapsack(itens + 1, weight), values[itens] + knapsack(itens + 1, weight - weights[itens]));
}

int main(){

	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		for(int i = 0; i < n; ++i){
			scanf("%d %d", &values[i], &weights[i]);
		}
		memset(pd, -1, sizeof pd);
		scanf("%d", &persons);
		sum = 0;
		for(int i = 0; i < persons; ++i){
			scanf("%d", &w);
			sum += knapsack(0, w);
		}

		printf("%d\n", sum);
	}
	
	return 0;
}