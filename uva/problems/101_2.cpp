#include <bits/stdc++.h>

using namespace std;

struct block{
	block * position;
	stack<int> elementos;
};

block blocks[25];

void moveOver(int of, int od){
	block * curr = blocks[of].position;
	cout<<"Of,od: "<<of<<" "<<od<<"-"<<curr->elementos.top()<<endl;
	while(curr->elementos.top() != of){
		int aux = curr->elementos.top();
		curr->elementos.pop();

		blocks[aux].position = &blocks[aux];
		blocks[aux].elementos.push(aux);
		//cout<<"Top: "<<curr->elementos.top()<<",Of: "<<of<<" Od: "<<od<<" Move over\n";
	}
	//cout<<"chegou aqui\n";
	if(!curr->elementos.empty() && curr->elementos.top() == of){
		curr->elementos.pop();
		curr->position = blocks[od].position;

		curr = blocks[od].position;
		curr->elementos.push(of); 
	}
}

void moveOnto(int of, int od){
	block * curr = blocks[od].position;
	while(curr->elementos.top() != od){
		int aux = curr->elementos.top();
		curr->elementos.pop();

		blocks[aux].position = blocks + aux;
		blocks[aux].elementos.push(aux);
		//cout<<"Move onto\n";
	}
	cout<<curr->elementos.top()<<endl;
	moveOver(of, od);
}

void pileOver(int of, int od){
	block * curr = blocks[of].position;
	stack<int> aux_stack;
	while(curr->elementos.top() != of){
		aux_stack.push(curr->elementos.top());
		curr->elementos.pop();
		//cout<<"Pilor over1\n";
	}
	if(!curr->elementos.empty() && curr->elementos.top() == of){
		aux_stack.push(curr->elementos.top());
		curr->elementos.pop();
	}
	curr = blocks[od].position;
	while(!aux_stack.empty()){
		blocks[aux_stack.top()].position = curr;
		curr->elementos.push(aux_stack.top());
		aux_stack.pop();
		//cout<<"Pile over2\n";
	}
}

void pileOnto(int of, int od){
	block * curr = blocks[od].position;
	while(curr->elementos.top() != od){
		int aux = curr->elementos.top();
		curr->elementos.pop();
		
		blocks[aux].position = blocks + aux;
		blocks[aux].elementos.push(aux);
		//cout<<"Pile onto\n";
	}

	pileOver(of, od);
}

int main(){

	for(int i = 0; i < 25; ++i){
		stack<int> new_stack; new_stack.push(i);
		blocks[i].position = &blocks[i];
		blocks[i].elementos = new_stack;
	}

	string n_blocks, inputs;
	getline(cin, n_blocks);
	while(getline(cin, inputs) && inputs.compare("quit")){
		string command, type;
		int of, od;

		stringstream ss;
		ss << inputs;
		ss >> command >> of >> type >> od;
		if(!command.compare("move")){
			if(!type.compare("over")){
				moveOver(of, od);
			}else{
				moveOnto(of, od);
			}
		}else{
			if(!type.compare("over")){
				pileOver(of, od);
			}else{
				pileOnto(of, od);
			}
		}
	}

	for(int i = 0; i < stoi(n_blocks, nullptr); ++i){
		cout<<i<<":";
		stack<int> aux;
		
		while(!blocks[i].elementos.empty()){
			aux.push(blocks[i].elementos.top());
			blocks[i].elementos.pop();
		}

		while(!aux.empty()){
			cout<<" "<<aux.top();
			aux.pop();
		}

		cout<<endl;	
	}

	return 0;
}