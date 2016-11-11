#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> edges(10000);
int tests,forbidden;
int start,final;
int input[4];

void createEdges(){
	for(int i = 0; i < 10; ++i)
	for(int j = 0; j < 10; ++j)
	for(int k = 0; k < 10; ++k)
	for(int l = 0; l < 10; ++l){
		int id = l + 10*k + 100*j + 1000*i;

		int idx = l + 10*k + 100*j + 1000*((i+1)%10);
		edges[id].push_back(idx);
		edges[idx].push_back(id);

		idx = l + 10*k + 100*j + 1000*((i+9)%10);
		edges[id].push_back(idx);
		edges[idx].push_back(id);

		idx = l + 10*k + 100*((j+1)%10) + 1000*i;
		edges[id].push_back(idx);
		edges[idx].push_back(id);

		idx = l + 10*k + 100*((j+9)%10) + 1000*i;
		edges[id].push_back(idx);
		edges[idx].push_back(id);

		idx = l + 10*((k+1)%10) + 100*j + 1000*i;
		edges[id].push_back(idx);
		edges[idx].push_back(id);

		idx = l + 10*((k+9)%10) + 100*j + 1000*i;
		edges[id].push_back(idx);
		edges[idx].push_back(id);

		idx = ((l+1)%10) + 10*k + 100*j + 1000*i;
		edges[id].push_back(idx);
		edges[idx].push_back(id);

		idx = ((l+9)%10) + 10*k + 100*j + 1000*i;
		edges[id].push_back(idx);
		edges[idx].push_back(id);
	}
}

int bfs(int visited[10000]){
    if(start == final) return 0;
	queue<pair<int,int>> q;
	q.push(make_pair(start,0));
	visited[start] = 1;
	while(!q.empty()){
		pair<int,int> front = q.front();
		q.pop();
		for(int i = 0; i < edges[front.first].size(); ++i){
			if(visited[ edges[front.first][i] ] == 0){
				if(edges[front.first][i] == final) return front.second + 1;
				visited[ edges[front.first][i] ] = 1;
				q.push(make_pair(edges[front.first][i], front.second + 1));
			}
		}
	}

	return -1;
}

int main(){

	createEdges();
	cin>>tests;
	for(int i = 0; i < tests; ++i){
		cin>>input[0]>>input[1]>>input[2]>>input[3];
		start = input[0]*1000 + input[1]*100 + input[2]*10 + input[3];
		cin>>input[0]>>input[1]>>input[2]>>input[3];
		final = input[0]*1000 + input[1]*100 + input[2]*10 + input[3];
		
		cin>>forbidden;
		int visited[10000] = {0};
		for(int j = 0; j < forbidden; ++j){
			cin>>input[0]>>input[1]>>input[2]>>input[3];
			visited[ input[0]*1000 + input[1]*100 + input[2]*10 + input[3] ] = 1;
		}
        
		cout<<bfs(visited)<<endl;
	}
	
	return 0;
}