#include <bits/stdc++.h>

using namespace std;

int line[8];
int minMove = INT_MAX;
vector<vector<int>> lines;

bool isValid(int * line_){
	int n_line[8] = {0};
	for(int i = 0; i < 8; ++i){
		if(n_line[line_[i]] != 0)
			return false;
		n_line[line_[i]] = 1;
	}
	for(int i = 0; i < 8; ++i){
		for(int j = i + 1; j < 8; ++j){
			if(abs(i - j) == abs(line_[i] - line_[j])){
				return false;
			} 
		}
	}

	return true;
}

void generate(){
	for (int i = 0; i < 8; ++i)
	for (int j = 0; j < 8; ++j)
	for (int k = 0; k < 8; ++k)
	for (int l = 0; l < 8; ++l)
	for (int m = 0; m < 8; ++m)
	for (int n = 0; n < 8; ++n)
	for (int o = 0; o < 8; ++o)
	for (int p = 0; p < 8; ++p){
		int n_line[] = {i, j, k, l, m, n, o , p};

		if(isValid(n_line)){
			lines.push_back(vector<int>(begin(n_line), end(n_line)));
		}		
	}
}


int main(){
	
	int pos;
	int counter = 1;
	generate();
	while(scanf("%d", &pos) != EOF){
		line[0] = pos-1;
		for(int i = 1; i < 8; ++i){
			scanf("%d", &pos);
			line[i] = pos-1;
		}

		for(int i = 0; i < lines.size(); ++i){
			int move = 0;
			line[0] != lines[i][0] ? move += 1 : move += 0;
			line[1] != lines[i][1] ? move += 1 : move += 0;
			line[2] != lines[i][2] ? move += 1 : move += 0;
			line[3] != lines[i][3] ? move += 1 : move += 0;			
			line[4] != lines[i][4] ? move += 1 : move += 0;
			line[5] != lines[i][5] ? move += 1 : move += 0;
			line[6] != lines[i][6] ? move += 1 : move += 0;
			line[7] != lines[i][7] ? move += 1 : move += 0;
			minMove = min(move, minMove);
		}

		printf("Case %d: %d\n", counter++, minMove);
		minMove = INT_MAX;
	}

	return 0;
}