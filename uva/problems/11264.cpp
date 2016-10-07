#include <bits/stdc++.h>

using namespace std;

int tests, n_coins;
vector<int> coins;

void count_coins(){
	int qntd = 0;
	int curr = 0;
	for(int i = 0; i < n_coins; ++i){
		curr += coins[i];
		int it = -1;		
		for(int j = n_coins - 1; j >= i; --j){
			if(coins[j] <= curr){
				it = coins[j];
				break;
			}
		}
		//cout<<"Curr, Lower: "<<curr<<","<<it<<endl;
		if(it == coins[i]) 
			qntd++;
		else 
			curr -= coins[i];
	}

	cout<<qntd<<endl;
}

int main(){
	
	cin>>tests;
	for(int i = 0; i < tests; ++i){
		cin>>n_coins;
		coins = vector<int>(n_coins);
		for(int j = 0; j < n_coins; ++j){
			cin>>coins[j];
		}
		count_coins();
	}

	return 0;
}