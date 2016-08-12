#include <iostream>

using namespace std;

int main(){

	int n,m;
	int count = 0;
	cin>>n>>m;
	while(true){
		char matrix[n+2][m+2];
		int matrixInt[n+2][m+2];
		for(int i = 0; i < n+2; ++i){
			for(int j = 0; j < m+2; ++j){
				matrixInt[i][j] = 0;
				if(i == 0 || i == n+1 || j == 0 || j == m+1){
					matrix[i][j] = '.';
				}else{
					cin>>matrix[i][j];
				}				
			}
		}

		cout<<"Field #"<<++count<<":\n";

		for(int i = 1; i < n+1; ++i){
			for(int j = 1; j < m+1; ++j){
				if(matrix[i][j] == '*') {
					cout<<'*';
				}else{
					if('*' == matrix[i-1][j-1])
						matrixInt[i][j]++;
					if('*' == matrix[i-1][j])
						matrixInt[i][j]++;
					if('*' == matrix[i-1][j+1])
						matrixInt[i][j]++;
					if('*' == matrix[i][j-1])
						matrixInt[i][j]++;
					if('*' == matrix[i][j+1])
						matrixInt[i][j]++;
					if('*' == matrix[i+1][j-1])
						matrixInt[i][j]++;
					if('*' == matrix[i+1][j])
						matrixInt[i][j]++;
					if('*' == matrix[i+1][j+1])
						matrixInt[i][j]++;
					
					cout<<matrixInt[i][j];
				}				
			}
			cout<<endl;
		}

		cin>>n>>m;
		if(n == 0 && m == 0)
			break;
		else 
			cout<<endl;

	}

	return 0;
}