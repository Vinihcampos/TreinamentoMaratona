#include <bits/stdc++.h>

using namespace std;

int main(){	
	
	int tests, index, value;
	int add, get;
	int aux_add;

	scanf("%d", &tests);	
	for(int i = 0; i < tests; ++i){

		vector<int> box;
		queue<int> addQ;
		queue<int> getQ;

		scanf("%d %d", &add, &get);

		for(int j = 0; j < add; ++j){
			scanf("%d", &value);
			addQ.push(value);
		}

		index = 0;
		add = 0;
		aux_add = 0;

		for(int j = 0; j < get; ++j){
			scanf("%d", &value);
			getQ.push(value);
		}

		for(int j = 0; j < get; ++j){
			aux_add = getQ.front();
			getQ.pop();

			auto it = box.begin();

			for(int k = 0; k < aux_add - add; ++k){				
				it = lower_bound(box.begin(), box.end(), addQ.front());
				box.insert(it, addQ.front());
				addQ.pop();
			}
			add = aux_add;

			it = box.begin();
			for(int k = 0; k < index && it != box.end(); ++k) {
				it++;
			}

			if(it == box.end()){
				it--;
			}

			printf("%d\n", *it);
			++index;
		}

		if(i != tests - 1) printf("\n");
	}

	return 0;
}