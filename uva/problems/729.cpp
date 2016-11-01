#include <bits/stdc++.h>

using namespace std;

set<vector<int>> possible_sets;
vector<int> hamming;

void backtracking(){

}

int main(){
	
	int tests;
	int n,h;

	cin>>tests;
	for(int i = 0; i < tests; ++i){
		cin>>n>>h;

		for(int j = n; j >= 1; --j){
			if(j > h)
				hamming.push_back(0);
			else
				hamming.push_back(1);
		}

		possible_sets.insert(hamming);
		while(next_permutation(hamming.begin(), hamming.end())){
			possible_sets.insert(hamming);
		}

		for(auto it = possible_sets.begin(); it != possible_sets.end(); it++){
			vector<int> teste = (*it);
			for(int j = 0; j < teste.size(); ++j){
				cout<<teste[j];
			}cout<<endl;		
		}
		if(i < tests - 1)
			cout<<endl;

		possible_sets.clear();
		hamming.clear();
	}

	return 0;
}