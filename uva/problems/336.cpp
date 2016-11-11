#include <bits/stdc++.h>

using namespace std;

map<int,int> order_number;
vector<vector<int>> edges;
int n;
int x,y;
int p1,p2;

int bfs(int start, int ttl){	
	int visited[edges.size()] = {0};
	queue<pair<int,int>> q;
	if(ttl == 0) return edges.size() - 1;
	q.push(make_pair(start, ttl));
	visited[start] = 1;
	int count = 0;
	while(!q.empty()){
		pair<int,int> front = q.front();
		q.pop();
		if(front.second == 0) continue;
		for(int i = 0; i < edges[front.first].size(); ++i){
			if(visited[ edges[front.first][i] ] == 0){
				visited[ edges[front.first][i] ] = 1;
				q.push(make_pair(edges[front.first][i], front.second - 1));
				++count;
			}
		}
	}

	return edges.size() - 1 - count;
}

int main(){
	
	int cases = 1;
	while(scanf("%d", &n) != EOF && n != 0){
		int cont = 0;
		for(int i = 0; i < n; ++i){
			scanf("%d %d", &x, &y);
			auto id1 = order_number.find(x);
			
			if(id1 == order_number.end()){
				order_number.insert(make_pair(x, cont++));
				p1 = cont-1;
				edges.push_back(vector<int>());
			}else{
				p1 = id1->second;
			}

			auto id2 = order_number.find(y);
			if(id2 == order_number.end()){
				order_number.insert(make_pair(y, cont++));
				p2 = cont-1;
				edges.push_back(vector<int>());
			}else{
				p2 = id2->second;
			}

			edges[p1].push_back(p2);
			edges[p2].push_back(p1);
		}
		while(scanf("%d %d", &x, &y) != EOF){
			if(x == 0 && y == 0) break;
			else if(order_number.find(x) == order_number.end()) 
				cout<<"Case "<<cases++<<": "<<edges.size()<<" nodes not reachable from node "<<x<<" with TTL = "<<y<<".\n";
			else
				cout<<"Case "<<cases++<<": "<<bfs(order_number[x], y)<<" nodes not reachable from node "<<x<<" with TTL = "<<y<<".\n";				
		}

		order_number.clear();
		edges.clear();
	}
	

	return 0;
}