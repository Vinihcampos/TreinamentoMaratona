#include <bits/stdc++.h>

using namespace std;

string inputs;
int tests;
int passwords_;
set<char> words[5];
set<char> input_char[5];

void passwords(){
	for(auto i = words[0].begin(); i != words[0].end(); i++)
	for(auto j = words[1].begin(); j != words[1].end(); j++)
	for(auto k = words[2].begin(); k != words[2].end(); k++)
	for(auto l = words[3].begin(); l != words[3].end(); l++)
	for(auto m = words[4].begin(); m != words[4].end(); m++){
		--passwords_;
		if(passwords_ <= 0){
			cout<<*i<<*j<<*k<<*l<<*m<<endl; return;
		}
	}
}

int main(){
	
	cin>>tests;
	for(int i = 0; i < tests; ++i){
		cin>>passwords_;
		for(int j = 0; j < 12; ++j){
			cin>>inputs;
			if(j < 6)
				for(int k = 0; k < 5; ++k){
					input_char[k].insert(inputs[k]);
				}
			else
				for(int k = 0; k < 5; ++k){
					if(input_char[k].find(inputs[k]) != input_char[k].end()){
						words[k].insert(inputs[k]);
					}
				}
		}

		int size = 1;
		for(int j = 0; j < 5; ++j){
			size *= words[j].size();
		}

		if(size < passwords_) cout<<"NO\n";
		else{
			passwords();
		}
		for(int j = 0; j < 5; ++j){
			words[j].clear();
			input_char[j].clear();
		}
	}

	return 0;
}