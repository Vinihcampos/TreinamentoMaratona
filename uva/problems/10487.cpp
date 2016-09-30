#include <bits/stdc++.h>

using namespace std;

int main(){
	
	int n,m;
	int aux;
	int count = 1;

	while(scanf("%d", &n) && n != 0){
		printf("Case %d:\n", count++);
		
		vector<int> numbers;

		for(int i = 0; i < n; ++i){
			scanf("%d", &aux);
			numbers.push_back(aux);
		}
		
		scanf("%d", &m);

		for(int i = 0; i < m; ++i){
			scanf("%d", &aux);
			int max_ = INT_MAX;

			for(int j = 0; j < n; ++j){
				for(int k = j + 1; k < n; ++k){
					if(sqrt(pow(numbers[j] + numbers[k] - aux, 2)) < sqrt(pow(aux - max_,2))){
						max_ = numbers[j] + numbers[k];
					} 
				}
			}
			printf("Closest sum to %d is %d.\n", aux, max_);
		}


	}
	

	return 0;
}