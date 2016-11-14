#include <bits/stdc++.h>

using namespace std;

int divisor[10001];

int pd(int n){
	if(divisor[n] == -1){
		int r = sqrt(n);
		int min_ = INT_MAX;
		for(int i = r; i > 0; --i){
			min_ = min(min_, 1 + pd(n - i*i));
		}
		divisor[n] = min_;
	}

	return divisor[n];
}

int main(){
	
	fill(divisor, divisor + 10001, -1);
	divisor[0] = 0;
	divisor[1] = 1;

	int n, number;
	while(cin>>n){
		for(int i = 0; i < n; ++i){
			cin>>number;
			pd(number);
			cout<<divisor[number]<<endl;
		}
	}

	return 0;
}