#include <bits/stdc++.h>

using namespace std;

int main(){
	
	int input;
	int count = 1;
	while(scanf("%d", &input) != EOF && input != 0){
		map<int, int> teams;
		
		for(int i = 0; i < input; ++i){
			int n_teams;
			scanf("%d", &n_teams);
			for(int j = 0; j < n_teams; ++j){
				int team;
				scanf("%d", &team);
				teams.insert(make_pair(team, i));
			}
		}
		
		list<queue<int>> elements;

		string entradas; int valor;
		printf("Scenario #%d\n", count++);

		while(getline(cin,entradas) && entradas.compare("STOP") != 0){
			if(entradas[0] == 'E'){
				stringstream ss;
				ss << entradas;
				ss >> entradas >> valor;

				auto it = elements.begin();

				for(; it!=elements.end(); ++it){
					if(teams[it->front()] == teams[valor]){
						it->push(valor);
						break;
					}
				}

				if(it == elements.end()){
					queue<int> novaFila;
					novaFila.push(valor);
					elements.push_back(novaFila);
				}
			}else{
				if(!elements.empty()){
					printf("%d\n", elements.front().front());
					elements.front().pop();

					if(elements.front().empty()) elements.pop_front();
				}				
			}
		}
		printf("\n");
	}

	return 0;
}
