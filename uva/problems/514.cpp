#include <bits/stdc++.h>

using namespace std;

int main(){
	
	stack<int> estacao;
	queue<int> vagoes;
	queue<int> chegada;

	int size;
	int input;
	while(cin>>size && size != 0){
		
		while(cin>>input && input != 0){
			bool achou = true;
			vagoes.push(1); chegada.push(input);

			for(int i = 2; i <= size; ++i){
				cin>>input;
				vagoes.push(i); chegada.push(input);
			}

			while(!chegada.empty() && achou){
				if(!vagoes.empty()){
					if(vagoes.front() == chegada.front()){
						vagoes.pop();
						chegada.pop();
					}else if(!estacao.empty() && chegada.front() == estacao.top()){
						chegada.pop();
						estacao.pop();
					}else{
						estacao.push(vagoes.front());
						vagoes.pop();
					}
				}else{
					if(!estacao.empty() && chegada.front() == estacao.top()){
						chegada.pop();
						estacao.pop();
					}else{
						achou = false;
					}
				}
			}

			if(achou) cout<<"Yes\n";
			else cout<<"No\n";

			if(!chegada.empty()){
				while(!chegada.empty()) chegada.pop();
				while(!vagoes.empty()) vagoes.pop();
				while(!estacao.empty()) estacao.pop();
			}
		}
		cout<<endl;	
	}
	return 0;
}