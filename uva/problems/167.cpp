#include <bits/stdc++.h>

using namespace std;

int line[8];
int maximum = INT_MIN;
vector<vector<int>> lines;
vector<vector<int>> chessboard;

bool isValid(int * line_){
	int n_line[8] = {0};
	for(int i = 0; i < 8; ++i){
		if(n_line[line_[i]]!= 0) return false;
		n_line[line_[i]] = 1;
	}

	for(int i = 0; i < 8; ++i){
		for(int j = i + 1; j < 8; ++j){
			if(abs(i-j) == abs(line_[i] - line_[j]))
				return false;
		}
	}

	return true;
}

void generate(){
	for(int i = 0; i < 8; ++i)
	for(int j = 0; j < 8; ++j)
	for(int k = 0; k < 8; ++k)
	for(int l = 0; l < 8; ++l)
	for(int m = 0; m < 8; ++m)
	for(int n = 0; n < 8; ++n)
	for(int o = 0; o < 8; ++o)
	for(int p = 0; p < 8; ++p){
		int n_line[] = {i,j,k,l,m,n,o,p};

		if(isValid(n_line)){
			lines.push_back(vector<int>(begin(n_line),end(n_line)));
		}
	}
}

int main(){
	int n;
	generate();
	
	for(int i = 0; i < 8; ++i){
		chessboard.push_back(vector<int>(8));
	}

	scanf("%d", &n);
	for(int i = 0; i < n; ++i){

		for(int j = 0; j < 8; ++j){
			for(int k = 0; k < 8; ++k){
				cin>>chessboard[j][k];
			}
		}

		for(int j = 0; j < lines.size(); ++j){
			int curr = 0;
			for(int k = 0; k < 8; ++k){
				curr += chessboard[ lines[j][k] ][k];
			}

			maximum = max(maximum, curr);
		}
		if(maximum >= 10000)
			cout<<maximum<<endl;
		else if(maximum >= 1000)
			cout<<" "<<maximum<<endl;
		else if(maximum >= 1000)
			cout<<" "<<maximum<<endl;
		else if(maximum >= 100)
			cout<<"  "<<maximum<<endl;
		else if(maximum >= 10)
			cout<<"   "<<maximum<<endl;
		else
			cout<<"    "<<maximum<<endl;

		chessboard.clear();
		maximum = 0;
	}

	return 0;
}