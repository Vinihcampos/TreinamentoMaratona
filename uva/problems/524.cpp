#include <bits/stdc++.h>

using namespace std;

bool primes[32];

vector<string> solutions;

bool comparator(string a, string b){
	stringstream ss1;
	stringstream ss2;

	ss1 << a;
	ss2 << b;

	int x,y;

	while(ss1 >> x && ss2 >> y){
		if(x < y) return true;
		else if(x > y) return false;
	}

	return true;
}

void backtracking(int n, string v, int c, int lastV, vector<int> remain){
	for(int i = 0; i < remain.size(); ++i){
		if(c < n - 1){
			if(primes[ lastV + remain[i] ]){
				vector<int> remain_aux = remain;
				remain_aux.erase(remain_aux.begin() + i);
				backtracking(n, v + " " + to_string(remain[i]), c + 1, remain[i], remain_aux);
			}
		}else{
			if(primes[ lastV + remain[i] ] && primes[ remain[i]  + 1]){
				v += " " + to_string(remain[i]);
				solutions.push_back(v);
			}
		}
	}
}

int main(){
	
	primes[3] = true;
	primes[5] = true;
	primes[7] = true;
	primes[11] = true;
	primes[13] = true;
	primes[17] = true;
	primes[19] = true;
	primes[23] = true;
	primes[29] = true;
	primes[31] = true;

	int input;
	int counter = 0;
	while(scanf("%d", &input) != EOF){
		if(counter != 0) printf("\n");
		
		printf("Case %d:\n", ++counter);
		
		if(input%2 == 0){
			
			std::vector<int> v;
			for(int i = 2; i <= input; ++i){
				v.push_back(i);
			}

			backtracking(input, "1", 1, 1, v);
			for(int i = 0; i < solutions.size(); ++i){
				cout<<solutions[i]<<endl;
			}

			solutions.clear();
		}
		
	}

	return 0;
}