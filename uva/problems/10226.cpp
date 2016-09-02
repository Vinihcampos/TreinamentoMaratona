#include <bits/stdc++.h>

using namespace std;

int main(){
	
	int tests; 
	float count;
	string tree;
	map<string, int> trees;
	
	getline(cin, tree);
	tests = stoi(tree);
	getline(cin, tree);
	
	for(int i = 0; i < tests; ++i){
		count = 0;
		while(getline(cin, tree) && tree != ""){
			if(trees.find(tree) != trees.end()){
				trees.find(tree)->second++;
			}else{
				trees.insert(make_pair(tree, 1));
			}
			count += 1;
		}

		for(auto it = trees.begin(); it != trees.end(); ++it){
			cout<<it->first;
			printf(" %.4f\n", (it->second/count)*100);
		}
		if(i < tests - 1) cout<<endl;
		trees.clear();
	}

	return 0;
}