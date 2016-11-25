#include <bits/stdc++.h>

using namespace std;

int main(){
	
	int t, n, max_;
	int inputs[100011] = {0};
	scanf("%d", &t);
	for(int i = 1; i <= t; ++i){
		printf("Case %d: ", i);
		scanf("%d", &n);
		max_ = INT_MIN;
		for(int j = 1; j <= n; ++j){
			scanf("%d", &inputs[j]);
			max_ = max(max_, inputs[j] - inputs[j-1]);
		}
		int ans = max_;
		for(int j = 1; j <= n; ++j){
			if(inputs[j] - inputs[j-1] == max_){
				max_--;
			}else if(inputs[j] - inputs[j-1] > max_){
				ans++;
				break;
			}
		}

		printf("%d\n", ans);
	}

	return 0;
}