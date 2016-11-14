#include <bits/stdc++.h>

using namespace std;

int hamburger[10001];
int hamb_times[10001];

int main(){
	
	int m,n,t;
	while(cin>>m>>n>>t){
		int min_ = min(m,n);
		int max_ = max(m,n);
		for(int i = 0; i <= min_; ++i){
			hamburger[i] = 0;
			hamb_times[i] = 0;
			if(i == min_){
				hamburger[i] = 1;
				hamb_times[i] = i;
			}
		}
		for(int i = min_ + 1; i <= max_; ++i){
			hamburger[i] = i/min_;
			hamb_times[i] = i/min_ * min_;
			if(i == max_){
				if(max_ % min_ == 0)
					hamburger[i] = max_ / min_;
				else
					hamburger[i] = 1;

				hamb_times[i] = max_;
			}
		}
		if(max_ < t)
			for(int i = max_ + 1; i <= t; ++i){
				if((t - (hamb_times[i-m] + m)) < (t - (hamb_times[i-n] + n))){
					hamburger[i] = hamburger[i-m] + 1;
					hamb_times[i] = hamb_times[i-m] + m;
				}else if((t - (hamb_times[i-m] + m)) > (t - (hamb_times[i-n] + n))){
					hamburger[i] = hamburger[i-n] + 1;
					hamb_times[i] = hamb_times[i-n] + n;
				}else{
					if(hamburger[i-m] > hamburger[i-n]){
						hamburger[i] = hamburger[i-m] + 1;
						hamb_times[i] = hamb_times[i-m] + m;
					}else{
						hamburger[i] = hamburger[i-n] + 1;
						hamb_times[i] = hamb_times[i-n] + n;
					}
				}
			}

		if(t - hamb_times[t] > 0){
			cout<<hamburger[t]<<" "<<t - hamb_times[t]<<endl;
		}else{
			cout<<hamburger[t]<<endl;
		}
	}

	return 0;
}