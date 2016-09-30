#include <bits/stdc++.h>

using namespace std;

int spaces, pieces;
int x,y;
pair<int,int> initial;
pair<int,int> final;
pair<int,int> f_initial;
vector<pair<int,int>> f_pairs;

bool backtracking(vector<pair<int,int>> curr, vector<pair<int,int>> pairs){
	if(curr.size() == spaces){
		if(curr.back().second == final.first) return true;
		else return false;
	}else{
		for(int i = 0; i < pairs.size(); ++i){
			if(pairs[i].first == curr.back().second){
				curr.push_back(pairs[i]);
				vector<pair<int,int>> np = pairs;
				np.erase(np.begin() + i);
				if(backtracking(curr, np)) return true;
				curr.pop_back();
			}else if(pairs[i].second == curr.back().second){
				curr.push_back(make_pair(pairs[i].second, pairs[i].first));
				vector<pair<int,int>> np = pairs;
				np.erase(np.begin() + i);
				if(backtracking(curr, np)) return true;
				curr.pop_back();
			}	
		}

		return false;
	}
}

int main(){

	while(scanf("%d", &spaces) != EOF && spaces != 0){
		scanf("%d", &pieces);
		scanf("%d %d", &x, &y); f_initial = make_pair(x,y);
		scanf("%d %d", &x, &y); final = make_pair(x,y);

		for(int i = 0; i < pieces; ++i){
			scanf("%d %d", &x, &y); f_pairs.push_back(make_pair(x,y));
		}

		bool found = false;
		bool control = false;
		vector<pair<int,int>> curr;
		vector<pair<int,int>> np;

		for(int i = 0; i < pieces; ++i){
			if(f_pairs[i].first == f_initial.second){
				initial = f_initial;
				curr.push_back(f_pairs[i]);
				np = f_pairs;
				np.erase(np.begin() + i); 
				control = true;
			}else if(f_pairs[i].second == f_initial.second){
				initial = f_initial;
				curr.push_back(make_pair(f_pairs[i].second, f_pairs[i].first)); 
				np = f_pairs;
				np.erase(np.begin() + i);
				control = true;
			}

			if(control){
				control = false;
				if(backtracking(curr, np)){
					found = true;
					break;
				}
				curr.pop_back();
			}
			
		}

		if(found) printf("YES\n");
		else printf("NO\n");

		f_pairs.clear();
	}
	
	return 0;
}