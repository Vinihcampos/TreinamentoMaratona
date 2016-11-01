#include <bits/stdc++.h>

using namespace std;

string input;
int queries;

vector<vector<int>> query(52);

int main(){
	
	getline(cin, input);
	for(int i = 0; i < input.size(); ++i){
		if(input[i] >= 'a'){
			query[ 26 + input[i]  - 'a' ].push_back(i);
		}else{
			query[ input[i] - 'A' ].push_back(i);
		}
	}
	getline(cin,input);
	queries = atoi( input.c_str() );
	
	for(int i = 0; i < queries; ++i){
		getline(cin,input);
		int id = -1;
		int start = 0;
		for(int j = 0; j < input.size(); ++j){
			if(input[j] >= 'a'){
				if(query[ 26 + input[j]  - 'a' ].empty()){
					id = -1;
					break;
				}else{
					if(id == -1){
						id = query[ 26 + input[j]  - 'a' ][0];
						start = id;					
					}else{
						auto it = lower_bound(query[ 26 + input[j]  - 'a' ].begin(), query[ 26 + input[j]  - 'a' ].end(), id+1);
						if(it != query[ 26 + input[j]  - 'a' ].end()){
							id = (*it);
						}else{
							id = -1;
							break;
						}
					}
				}
			}else{
				if(query[ input[j] - 'A' ].empty()){
					id = -1;
					break;
				}else{
					if(id == -1){
						id = query[ input[j] - 'A' ][0];
						start = id;
					}else{
						auto it = lower_bound(query[ input[j] - 'A' ].begin(), query[ input[j] - 'A' ].end(), id+1);
						if(it != query[ input[j] - 'A' ].end()){
							id = (*it);
						}else{
							id = -1;
							break;
						}
					}
				}
			}
		}

		if(id == -1){
			printf("Not matched\n");
		}else{
			printf("Matched %d %d\n", start, id);
		}
	}

	return 0;
}