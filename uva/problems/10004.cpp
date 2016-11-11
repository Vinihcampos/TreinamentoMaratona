#include <bits/stdc++.h>
using namespace std;

int n_nodes,n_edges,x,y;
vector<vector<int>> edges;

bool bfs(){
    
    int visited[n_nodes] = {0};
    queue<int> q;
    q.push(0);
    visited[0] = 1;
    
    while(!q.empty()){
        int front = q.front();
        q.pop();
        int next; visited[front] == 1 ? next = 2 : next = 1;
        for(int i = 0; i < edges[front].size(); ++i){
            if(visited[ edges[front][i] ] == 0){
                visited[ edges[front][i] ] = next;
                q.push(edges[front][i]);
            }else{
                if(visited[ edges[front][i] ] == visited[front])
                    return false;
            }
        }
    }
    return true;
}

int main() {
    while(cin>>n_nodes){
        if(n_nodes == 0) break;
	    edges = vector<vector<int>>(n_nodes);
        cin>>n_edges;
        for(int i = 0; i < n_edges; ++i){
            cin>>x>>y;
            edges[x].push_back(y);
            edges[y].push_back(x);
        }
        if(bfs()){
            cout<<"BICOLORABLE."<<endl;
        }else{
            cout<<"NOT BICOLORABLE."<<endl;
        }
        edges.clear();
    }
	
	return 0;
}
