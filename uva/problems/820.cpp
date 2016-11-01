#include <bits/stdc++.h>

using namespace std;

vector<map<int,int>> edges;
int n,s,t,c;
int x,y,w;

bool bfs(){
	int visited[n+1] = {0};

	queue<int> path;
	path.push(s);
	visited[s] = s;
	while(!path.empty() && visited[t] == 0){
		int front = path.front();
		path.pop();

		for(auto i = edges[front].begin(); i != edges[front].end(); i++){
			if( visited[ i->first ] == 0 && i->second > 0){
				visited[ i->first ] = front;
				path.push(i->first);
			}
		}
	}

	if(visited[t] == 0) return false;
	else{
		int curr = t;
		int minimum = INT_MAX;

		while(curr != s){
			auto it = edges[ visited[curr] ].find(curr);
			minimum = min(minimum, it->second);

			curr = visited[curr];
		}

		curr = t;
		while(curr != s){

			auto it = edges[ visited[curr] ].find(curr);
			it->second -= minimum;
			it = edges[ curr ].find(visited[curr]);
			it->second += minimum;

			curr = visited[curr];
		}
		return true;
	}
}

int ek(){

	int vezes = 1;
	vector<map<int,int>> copy = edges;
	while(bfs());

	int flow = 0;

	for(auto i = edges[s].begin(); i != edges[s].end(); i++){
		auto it = edges[i->first].find(s);
		auto it2 = copy[i->first].find(s);
		flow += it->second - it2->second;
	}

	return flow;

}

int main(){
	int nets = 1;
	while(scanf("%d", &n) != EOF && n != 0){
		map<int,int> curr;
		for(int i = 0; i <= n; ++i){
			edges.push_back(curr);
		}

		scanf("%d %d %d", &s, &t, &c);

		for(int i = 0; i < c; ++i){
			scanf("%d %d %d", &x, &y, &w);

			auto it = edges[x].find(y); 
			if(it != edges[x].end()){
				it->second += w;
				it = edges[y].find(x);
				it->second += w;
			}else{
				edges[x].insert(make_pair(y, w));
				edges[y].insert(make_pair(x, w));
			}
		}

		printf("Network %d\n", nets++);
		printf("The bandwidth is %d.\n\n", ek());

		edges.clear();
	}
	

	return 0;
}