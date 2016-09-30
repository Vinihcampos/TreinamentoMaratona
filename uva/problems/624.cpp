#include <bits/stdc++.h>

using namespace std;

int size, n, input, maxsum = 0;
int tracks[20];
vector<int> path;
vector<int> currPath;

void backtracking(std::vector<int> curr, int index, int currSum){
	if(currSum > maxsum || (currSum == maxsum && curr.size() > path.size())){
		maxsum = currSum;
		path = curr;
	}

	for(int i = index + 1; i < n; ++i){
		if(currSum + tracks[i] <= size){
			curr.push_back(tracks[i]);
			backtracking(curr, i, currSum + tracks[i]);
			curr.pop_back();
		}
	}
}

int main(){

	while(scanf("%d %d", &size, &n) != EOF){
				
		for(int i = 0; i < n; ++i){
			scanf("%d", &input);
			tracks[i] = input;
		}
		
		for(int i = 0; i < n; ++i){			
			currPath.push_back(tracks[i]);
			backtracking(currPath, i, tracks[i]);
			currPath.pop_back();
		}

		for(int i = 0; i < path.size(); ++i)
			printf("%d ", path[i]);		
		printf("sum:%d\n", maxsum);

		maxsum = 0;
		currPath.clear();

	}
	
	return 0;
}

