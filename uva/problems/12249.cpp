#include <bits/stdc++.h>

using namespace std;

int t, n;
string input;
vector<string> scenes;
int minimum;

void backtracking(vector<string> curr, vector<string> scene){
	if(curr.size() == n){
		string answer = curr[0];
		for(int i = 1; i < curr.size(); ++i){
			bool found = false;
			for(int j = curr[i].size() - 1; j >= 0; --j){
				if(answer.size() >= j+1){
					if(curr[i].substr(0, j+1).compare(answer.substr(answer.size() - j - 1,j+1)) == 0){						
						answer += curr[i].substr( j+1, curr[i].size() - j + 1 );
						found = true;
						break;
					}
				}
			}

			if(!found){
				answer += curr[i];
			}
		}
		minimum = min((int)answer.size(), minimum);
	}else{
		vector<string> remain;
		for(int i = 0; i < scene.size(); ++i){
			curr.push_back(scene[i]);
			remain = scene;
			remain.erase(remain.begin() + i);
			backtracking(curr, remain);
			curr.pop_back();	
		}
	}

	
}

int main(){

	getline(cin, input);
	t = stoi(input);
	for(int i = 0; i < t; ++i){
		printf("Case %d: ", i+1);

		getline(cin, input);
		n = stoi(input);
		for(int j = 0; j < n; ++j){
			getline(cin, input);
			scenes.push_back(input);
		}

		minimum = INT_MAX;
		vector<string> curr;
		vector<string> remain;
		for(int j = 0; j < scenes.size(); ++j){
			curr.push_back(scenes[j]);
			remain = scenes;
			remain.erase(remain.begin() + j);
			backtracking(curr, remain);
			curr.pop_back();
		}

		printf("%d\n", minimum);
		scenes.clear();
	}
	
	return 0;
}