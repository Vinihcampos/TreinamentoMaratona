#include <bits/stdc++.h>

using namespace std;

int sum, n, input;
vector<int> values;
set<vector<int>> vector_sums;

void backtracking(vector<int> curr, int index, int currSum){
	for(int i = index + 1; i < values.size(); ++i){
		if(currSum + values[i] <= sum){
			curr.push_back(values[i]);

			if(currSum + values[i] == sum) vector_sums.insert(curr);
			else backtracking(curr, i, currSum + values[i]);
			
			curr.pop_back();
		}else if(currSum > sum) return;
	}
}

int main(){
	
	while(cin>>sum>>n && n != 0){
		cout<<"Sums of "<<sum<<":\n";
		for(int i = 0; i < n; ++i){
			cin>>input;
			values.push_back(input);
		}

		for(int i = 0; i < n; ++i){
			if(values[i] <= sum){
				vector<int> curr;
				curr.push_back(values[i]);
				if(values[i] == sum) vector_sums.insert(curr);
				else backtracking(curr, i, values[i]);
			}
		}
		if(vector_sums.empty()) cout<<"NONE\n";
		else 
			for(auto i = vector_sums.rbegin(); i != vector_sums.rend(); i++){
				for(int j = 0; j < i->size(); ++j){
					if(j == 0) cout<<i->at(j);
					else cout<<"+"<<i->at(j);
				}cout<<endl;
			}

		vector_sums.clear();
		values.clear();
	}

	return 0;
}