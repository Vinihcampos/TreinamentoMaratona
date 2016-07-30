#include <bits/stdc++.h>

using namespace std;

int main(){
	int i,j;
	while(cin>>i>>j){
		int total_count = 0;
		int aux, aux_i, aux_j;
		aux_i = i; aux_j = j;
		
		if(aux_j < aux_i)
			swap(aux_i, aux_j);

		for(; aux_i <= aux_j; ++aux_i){
			aux = aux_i;
			int partial_count = 1;			
			while(aux != 1){
				partial_count++;
				if(aux % 2 != 0)
					aux = 3*aux + 1;
				else
					aux /= 2;
			}
			if(total_count < partial_count) 
				total_count = partial_count;
		}
		cout<<i<<" "<<j<<" "<<total_count<<endl;
	}
	return 0;
}