#include <bits/stdc++.h>

using namespace std;

int main(){
	
	vector< pair< int, stack<int> > > blocks;

	for(int i = 0; i < 25; ++i){
		stack<int> new_stack; new_stack.push(i);
		blocks.push_back(make_pair(i, new_stack));
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
				while(blocks[blocks[of].first].second.top() != of){
					blocks[blocks[blocks[of].first].second.top()].second.push(blocks[blocks[of].first].second.top());
					blocks[blocks[of].first].second.pop();
				}
				blocks[blocks[of].first].second.pop();
				blocks[of].first = od;
				blocks[blocks[od].first].second.push(of);
			}else{
				while(blocks[blocks[of].first].second.top() != of){
					blocks[blocks[blocks[of].first].second.top()].second.push(blocks[blocks[of].first].second.top());
					blocks[blocks[of].first].second.pop();
				}
				blocks[blocks[of].first].second.pop();
				blocks[of].first = od;
				while(blocks[blocks[od].first].second.top() != od){
					blocks[blocks[blocks[od].first].second.top()].second.push(blocks[blocks[od].first].second.top());
					blocks[blocks[od].first].second.pop();
				}
				blocks[blocks[od].first].second.push(of);
			}
		}else{
			if(!type.compare("over")){
				stack<int> auxStack;
				while(blocks[blocks[of].first].second.top() != of){
					int aux = blocks[blocks[of].first].second.top();
					blocks[blocks[of].first].second.pop();

					blocks[aux].first = blocks[od].first;
					auxStack.push(aux);
				}
				blocks[blocks[of].first].second.pop();
				blocks[of].first = blocks[od].first;
				auxStack.push(of);
				while(!auxStack.empty()){
					blocks[blocks[of].first].second.push(auxStack.top());
					auxStack.pop();
				}
			}else{
				while(blocks[blocks[od].first].second.top() != od){
					blocks[blocks[blocks[od].first].second.top()].second.push(blocks[blocks[od].first].second.top());
					blocks[blocks[od].first].second.pop();
				}

				stack<int> auxStack;
				while(blocks[blocks[of].first].second.top() != of){
					int aux = blocks[blocks[of].first].second.top();
					blocks[blocks[of].first].second.pop();

					blocks[aux].first = blocks[od].first;
					auxStack.push(aux);
				}
				blocks[blocks[of].first].second.pop();
				blocks[of].first = blocks[od].first;
				auxStack.push(of);
				while(!auxStack.empty()){
					blocks[blocks[of].first].second.push(auxStack.top());
					auxStack.pop();
				} 
			}
		}
	}

	for(int i = 0; i < stoi(n_blocks, nullptr); ++i){
		cout<<i<<":";
		stack<int> aux;
		
		while(!blocks[i].second.empty()){
			aux.push(blocks[i].second.top());
			blocks[i].second.pop();
		}

		while(!aux.empty()){
			cout<<" "<<aux.top();
			aux.pop();
		}

		cout<<endl;	
	}

	return 0;
}