#include <bits/stdc++.h>

using namespace std;

#define SOMA 0
#define SUB 1
#define MUL 2

vector<vector<int>> sets;

int calc(int a, int b, int op){
	if(op == SOMA)
		return a + b;
	else if(op == SUB)
		return a - b;
	else
		return a * b;
}

bool percorre(vector<int> & v){
	for(int i = 0; i < 3; ++i){
		for(int j = 0; j < 3; ++j){
			for(int k = 0; k < 3; ++k){
				for(int l = 0; l < 3; ++l){
					int c = calc(v[0],v[1],i);
					c = calc(c,v[2],j);
					c = calc(c,v[3],k);
					c = calc(c,v[4],l);
					if(c == 23) return true;
				}
			}			
		}		
	}
	return false;
}

int main(){
	
	vector<int> values(5);
	while(cin>>values[0]>>values[1]>>values[2]>>values[3]>>values[4]){
		if(values[0] != 0 && values[1] != 0 && values[2] != 0 && values[3] != 0 && values[4] != 0){
			sort(values.begin(), values.end());
			sets.push_back(values);
			while(next_permutation(values.begin(), values.end())){
				sets.push_back(values);
			}
			bool found = false;	
			for(int i = 0; i < sets.size(); ++i){
				if(percorre(sets[i])){
					found = true;
					break;
				}
			}

			if(found) cout<<"Possible\n";
			else cout<<"Impossible\n";

			sets.clear();
		}
	}

	return 0;
}