#include <bits/stdc++.h>

using namespace std;

int pegs[50];
int t, p;

int calcBalls(){
	fill(begin(pegs), end(pegs), 0);
	int start = 1;
	int id = 0;
	int qntd = 0;
	while(id < p){
		if(pegs[id] == 0){
			qntd++;
			pegs[id] = start++;
			id = 0;
		}else{
			if(sqrt(pegs[id] + start) == floor(sqrt(pegs[id] + start))){
				qntd++;
				pegs[id] = start++;
				id = 0;	
			}else{
				++id;
			}
		}
	}

	return qntd; 
}

int main(){
	cin>>t;
	while(t--){
		cin>>p;
		cout<<calcBalls()<<endl;
	}

	return 0;
}