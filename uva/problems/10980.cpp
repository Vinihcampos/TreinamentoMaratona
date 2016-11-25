#include <bits/stdc++.h>

using namespace std;

vector< pair< int, double > > pn;
double prod[101] = {0};
double unidade;
int m;

void pd(){
	for(int i = 0; i <= 100; ++i){
		prod[i] = unidade * i;
	}

	for(int i = 0; i < m; ++i){
		int n_prod = pn[i].first;
		float v_prod = pn[i].second;
		for(int j = 0; j <= 100 - n_prod; ++j){
			for(int k = 1; k <= n_prod; ++k){
				prod[k + j] = min( prod[k + j], prod[j] + v_prod);
			}
		}
	}
}

int main(){
	int t = 1;
	while(cin>>unidade>>m){
		pn = vector< pair< int, double > >(m);
		for(int i = 0; i < m; ++i){
			cin>>pn[i].first>>pn[i].second;
		}
		cin.ignore();
		pd();
		string x;
		int y;
		getline(cin, x);
		stringstream ss;
		ss << x;
		cout<<"Case "<<t++<<":\n";
		while(ss >> y){
			printf("Buy %d for $%.2lf\n", y, prod[y]);
		}
	}

	return 0;
}