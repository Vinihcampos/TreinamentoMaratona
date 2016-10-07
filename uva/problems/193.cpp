#include <bits/stdc++.h>

using namespace std;

int m,n,k;
int x,y;

vector<vector<int>> edges;
set<int> best;

void backtracking(int index, set<int> curr, vector<int> colors){
	if(index == n){
		if(curr.size() > best.size()){
			best = curr;
		}
	}else{
		bool found = false;
		for(int i = 0; i < edges[index].size(); ++i){
			if(colors[edges[index][i]] == 1){
				found = true;
				break;
			}
		}

		if(!found){
			colors[index] = 1;
			curr.insert(index);

			backtracking(index + 1, curr, colors);
			
			curr.erase(index);
			colors[index] = 0;
		}

		backtracking(index + 1, curr, colors);
	}
}

vector<int>colors;
set<int> set_;

int main(){
	
	cin>>m;

	for(int i = 0; i < m; ++i){
		cin>>n>>k;
		colors = vector<int>(n);
		for(int j = 0; j < n; ++j){ 
			colors[i] = 0;
			edges.push_back(vector<int>(0));
		}

		for(int j = 0; j < k; ++j){
			cin>>x>>y;

			edges[x-1].push_back(y-1);
			edges[y-1].push_back(x-1);
		}
		
		backtracking(0, set_, colors);

		cout<<best.size()<<endl;
		for(auto j = best.begin(); j != best.end(); j++){
			if(j == best.begin())
				cout<<*j + 1;
			else
				cout<<" "<<*j + 1;
		}cout<<endl;

		best.clear();
		colors.clear();
		edges.clear();
		set_.clear();
	}

	return 0;
}	