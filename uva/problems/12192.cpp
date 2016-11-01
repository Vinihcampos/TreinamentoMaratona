#include <bits/stdc++.h>

using namespace std;

int n,m,queries;
int l,u;
vector<vector<int>> area(500);

int main(){
	vector<int> v(500);
	for(int i = 0; i < 500; ++i)
		area[i] = v;

	while(scanf("%d %d", &n, &m) != EOF && n != 0 && m != 0){
		for(int i = 0; i < n; ++i){
			for(int j = 0; j < m; ++j){
				scanf("%d", &area[i][j]);
			}
		}

		scanf("%d", &queries);

		for(int i = 0; i < queries; ++i){
			scanf("%d %d", &l, &u);
			int maximum = 0;
			for(int j = 0; j < n; ++j){
				auto low = lower_bound(area[j].begin(), area[j].begin() + m, l);

				if(low == area[j].begin() + m || *low > u) continue;
				int line = j + maximum;
				int column = (low - area[j].begin()) + maximum;
				while(line < n && column < m){
					if(area[line++][column++] <= u){
						maximum++;
					}else
						break;
				}

				if(maximum >= n - j + 1)
					break;
			}
			printf("%d\n", maximum);
		}
		printf("-\n");
	}
	
	return 0;
}