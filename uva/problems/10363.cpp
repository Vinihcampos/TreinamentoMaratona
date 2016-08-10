#include <bits/stdc++.h>

using namespace std;

int main(){

	int inputs;

	cin>>inputs;
	char mapa[7][7];

	for(int i = 0; i < inputs; ++i){
		int qx = 0;
		int qo = 0;
		int vx = 0;
		int vo = 0;
		for(int j = 0; j < 7; ++j){
			for(int k = 0; k < 7; ++k){
				if(j < 2 || j > 4 || k < 2 || k > 4){
					mapa[j][k] = 'a';
				}else{					
					cin>>mapa[j][k];
					mapa[j][k] == 'X' ? ++qx : mapa[j][k] == 'O' ? ++qo : qx;
					
					if((mapa[j-2][k] == mapa[j-1][k] && mapa[j-1][k] == mapa[j][k])       || /* VERTICAL            */
					   (mapa[j][k-2] == mapa[j][k-1] && mapa[j][k-1] == mapa[j][k])       || /* HORIZONTAL          */
					   (mapa[j-2][k-2] == mapa[j-1][k-1] && mapa[j-1][k-1] == mapa[j][k]) || /* DIAGONAL PRINCIPAL  */
					   (mapa[j-2][k+2] == mapa[j-1][k+1] && mapa[j-1][k+1] == mapa[j][k])    /* DIAGONAL SECUNDARIA */){
						mapa[j][k] == 'X' ? ++vx : mapa[j][k] == 'O' ? ++vo : vx;
					}
				}
				
			}
		}
		if(qo > qx || abs(qx - qo) > 1 || (vx > 0 && vo > 0) || (vo > 0 && qx > qo) || (vx > 0 && qo >= qx)){
			cout<<"no\n";
		}else{
			cout<<"yes\n";
		}
	}

	return 0;
}