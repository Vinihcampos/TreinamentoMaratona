#include <bits/stdc++.h>

using namespace std;

int main(){
	
	set<int> box;
	int tests, index, value, last_value;
	int add, get;
	string input;
	int aux_add;

	getline(cin, input);
	
	tests = stoi(input);
	getline(cin, input);

	for(int i = 0; i < tests; ++i){
		cin>>add>>get;
		stringstream ss;
		getline(cin, input);
		ss << input;
		index = 0;
		for(int j = 0; j < get; ++j){
			cin>>aux_add;
			value = INT_MIN;
			for(int k = 0; k < aux_add - index; ++k){
				value << input;
				box.insert(value);
				index++;
			}
			if(value != INT_MIN)
				last_value = value;

			auto it = box.find(last_value);
			if(box.end() - it >= aux_add)
				it = begin.end() - 1;
			else
				it = it + aux_add;

			cout<<*it<<endl;
		}

		box.clear();
		getline(cin, input);
	}

	return 0;
}