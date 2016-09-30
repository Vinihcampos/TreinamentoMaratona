#include <bits/stdc++.h>

using namespace std;

int matrix[500][500] = {{0}};
int countP;
int countB;

int main(){
	
	int n,p;
	int x,y;
	scanf("%d %d", &n, &p);

	for(int i = 0; i < p; ++i){
		scanf("%d %d", &x, &y);
		matrix[x-1][y-1] = 1;
	}

	for(int i = 0; i < p; ++i){
		scanf("%d %d", &x, &y);
		matrix[x-1][y-1] = -1;
	}

	countP = p;
	countB = p;

	for(int i = 0; i < n; ++i){
		for(int j = 0; j < n; ++j){
			bool keep = true;
			int current = 0;
			for(int k = 1; k < n; ++k){
				bool keep = true;
				int current = 0;
				for(int l = i; l + k < n; ++l){
					for(int m = j; m + k < n; ++m){
						if(matrix[l+k][m+k] != 0 && matrix[l+k][m+k] != current && current != 0){
							keep = false;
							break;
						}else if(matrix[l+k][m+k] != 0){
							current = matrix[l+k][m+k];
						}
					}
					if(!keep) break;
				}
				if(keep && current != 0){
					if(current == 1) countP++;
					else countB++;
				}else if(!keep){
					break;
				}
			}
		}
	}

	printf("%d %d\n", countP, countB);

	return 0;
}