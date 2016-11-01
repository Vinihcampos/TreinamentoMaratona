#include <bits/stdc++.h>

using namespace std;

int counter,c,s,aux;
double imbalance,mean;
vector<int> specimens;
vector<pair<int,int>> pairs;
vector<int> specimens_fixed;
int main(){
	
	counter = 0;

	while(scanf("%d %d", &c, &s) != EOF){
		mean = 0;
		for(int i = 0; i < s; ++i){
			scanf("%d", &aux); specimens.push_back(aux); mean += aux;
		}

		mean = mean / (c * 1.0);

		while(specimens.size() < 2*c)
			specimens.push_back(0);

		specimens_fixed = specimens;
		sort(specimens.begin(), specimens.end());

		
		imbalance = 0;
		float local_imbalance = 0;
		for(int i = 0; i < c; ++i){
			pairs.push_back(make_pair(specimens[i], specimens[specimens.size() - 1 - i]));
			imbalance += abs(specimens[i] + specimens[specimens.size() - 1 - i] - mean);
		}

		printf("Set #%d\n", ++counter);
		int cont = 0;
		for(int i = 0; i < s; ++i){
			for(int j = 0; j < pairs.size(); ++j){
				if(specimens_fixed[i] == pairs[j].first){
					printf(" %d: %d", cont++, pairs[j].first);
					if(pairs[j].second != 0) printf(" %d\n", pairs[j].second);
					else printf("\n");
					pairs.erase(pairs.begin() + j);
					break;
				}else if(specimens_fixed[i] == pairs[j].second){
					printf(" %d: %d", cont++, pairs[j].second);
					if(pairs[j].first != 0) printf(" %d\n", pairs[j].first);
					else printf("\n");
					pairs.erase(pairs.begin() + j);
					break;
				}
			}
		}

		for(int i = 0; i < pairs.size(); ++i){
			printf(" %d:\n", cont++);
		}

		printf("IMBALANCE = %.5lf\n\n", imbalance);

		specimens.clear();
		pairs.clear();
		specimens_fixed.clear();
	}

	return 0;
}