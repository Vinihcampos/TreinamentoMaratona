#include <bits/stdc++.h>

using namespace std;

int n,m;
int aux;
vector<int> dragons;
vector<int> knights;

int count_min(){
	int acc = 0;
	int knight = 0;
	for(int i = 0; i < dragons.size(); ++i){
		bool found = false;
		for(; knight < knights.size(); ++knight){
			if(knights[knight] >= dragons[i]){
				acc += knights[knight];
				knight++;
				found = true;
				break;
			}
		}
		if(!found) return -1;
	}
	return acc;
}

int main(){
		
	while(scanf("%d %d", &n, &m) && n != 0 && m != 0){
		for(int i = 0; i < n; ++i){
			scanf("%d", &aux); dragons.push_back(aux);
		}

		for(int i = 0; i < m; ++i){
			scanf("%d", &aux); knights.push_back(aux);	
		}

		sort(knights.begin(), knights.end());
		sort(dragons.begin(), dragons.end());

		int acc = count_min();
		if(acc == -1) printf("Loowater is doomed!\n");
		else printf("%d\n", acc);

		knights.clear();
		dragons.clear();
	}

	return 0;
}