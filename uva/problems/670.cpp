#include <bits/stdc++.h>

using namespace std;

int l, n, m;
int x,y;
int s,t;

vector<pair<int,int>> bob;
vector<pair<int,int>> places;
vector<map<int,int>> edges;

struct aux{
	int before;
	int index;
	int next;

	aux(int _before, int _index, int _next) : before{_before}, index{_index}, next{_next}{}
};

float euclidian(pair<int,int> a, pair<int,int> b){
	return sqrt( pow( a.first - b.first, 2 ) + pow( a.second - b.second, 2 ) );
}

bool comp(aux a, aux b){

	float dist = euclidian(bob[a.before - 1], bob[a.next - 1]) * 2;
	float distA = euclidian(bob[a.before - 1], places[a.index - n - 1]) + euclidian(bob[a.next - 1], places[a.index - n - 1]);
	float distB = euclidian(bob[b.before - 1], places[b.index - n - 1]) + euclidian(bob[b.next - 1], places[b.index - n - 1]);
	
	return abs(distA - dist) < abs(distB - dist);
}

bool bfs(vector<bool> & global_visited){
	int visited[n+m+2] = {0};

	queue<int> path;
	path.push(s);
	visited[s] = s;
	while(!path.empty() && visited[t] == 0){
		int front = path.front();
		path.pop();

		vector<aux> auxiliar;

		if(front > s && front <= n){
			for(auto i = edges[front].begin(); i != edges[front].end(); i++){
				if( visited[ i->first ] == 0 && i->second > 0 /*&& !global_visited[ i->first ]*/){
					auxiliar.push_back(aux(front, i->first,front+1));
				}
			}
			sort(auxiliar.begin(), auxiliar.end(), comp);
			for(int i = 0; i < auxiliar.size(); ++i){
				visited[ auxiliar[i].index ] = front;
				path.push(auxiliar[i].index);
			}

		}else{
			for(auto i = edges[front].begin(); i != edges[front].end(); i++){
				if( visited[ i->first ] == 0 && i->second > 0 /*&& !global_visited[ i->first ]*/){
					visited[ i->first ] = front;
					path.push(i->first);
				}
			}
		}
		
	}

	if(visited[t] == 0) return false;
	else{
		int curr = t;
		int minimum = 1;

		curr = t;
		while(curr != s){
			auto it = edges[ visited[curr] ].find(curr);
			it->second = -1;
			it = edges[ curr ].find(visited[curr]);
			it->second = 1;

			curr = visited[curr];

			if(curr != s && curr != t)
				global_visited[curr] = true;
		}

		return true;
	}
}

void ek(){

	vector<bool> global_visited(n + m + 2);
	vector<map<int,int>> copy = edges;

	while(bfs(global_visited));

	int flow = n;
	string path = "";
	for(auto i = 1; i <= n; i++){
		if(i == 1)
			path += to_string(bob[i-1].first) + " " + to_string(bob[i-1].second);
		else
			path += " " + to_string(bob[i-1].first) + " " + to_string(bob[i-1].second);

		for(auto it = edges[i].begin(); it != edges[i].end(); it++){
			if(it->second == -1){
				path += " " + to_string(places[it->first - n - 1].first) + " " + to_string(places[it->first - n - 1].second);
				flow++;
				break;
			}
		}
	}

	printf("%d\n", flow);
	cout<<path<<endl;

}

int main(){
	
	scanf("%d", &l);

	while(l--){
		scanf("%d %d", &n, &m);

		for(int i = 0; i < n; ++i){
			scanf("%d %d", &x, &y);
			bob.push_back(make_pair(x,y));
		}

		for(int i = 0; i < m; ++i){
			scanf("%d %d", &x, &y);
			places.push_back(make_pair(x,y));
		}

		map<int,int> curr;
		for(int i = 0; i < n + m + 2; ++i){
			edges.push_back(curr);
		}

		s = 0;
		t = n + m + 1;

		for(int i = 1; i <= n; ++i){
			edges[0].insert(make_pair(i, 1));
			edges[i].insert(make_pair(0, 0));
		}

		for(int i = n+1; i <= n + m; ++i){
			edges[i].insert(make_pair(t, 1));
			edges[t].insert(make_pair(i, 0));
		}

		for(int i = 0; i < n - 1; ++i){
			float dist = euclidian(bob[i], bob[i+1]);
			for(int j = 0; j < m; ++j){
				if( euclidian(bob[i], places[j]) + euclidian(bob[i+1], places[j]) <= 2 * dist ){
					edges[i + 1].insert(make_pair(n+1+j,1));
					edges[n+1+j].insert(make_pair(i + 1,0));
				}
			}
		}

		ek();
		if(l > 0)
			cout<<endl;

		edges.clear();
		bob.clear();
		places.clear();
	}

	return 0;
}