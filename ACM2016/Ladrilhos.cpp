#include <bits/stdc++.h>
 
using namespace std;

int parent[40001];
int rankh[40001];
int size[40001];

void makeset(int n){
    for(int i = 0; i < n; ++i){
        parent[i] = i;
        rankh[i] = 0;
        size[i] = 1;
    }
}

int find(int u){
	if(u != parent[u]){
		parent[u] = find(parent[u]);
	}

	return parent[u];
}

void join(int u, int v){
	int pu = find(u);
	int pv = find(v);
	if(rankh[pu] > rankh[pv]){
		parent[pv] = pu;
		size[pu] += size[pv];
	}else if(rankh[pu] < rankh[pv]){
		parent[pu] = pv;
		size[pv] += size[pu];
	}else{
		parent[pu] = pv;
		size[pv] += size[pu];
		rankh[pv]++;
	}
}

int H, L;

int m[202][202];

int element(int i, int j){
	--i; --j;
	return(i * L + j);
}
 
int main() {
 
    cin>>H>>L;
    makeset(H*L);

    for(int i = 0; i <= L + 1; ++i)
    	m[0][i] = m[H + 1][i] = -1;
 	for(int i = 0; i <= H + 1; ++i)
    	m[i][0] = m[i][L + 1] = -1;

    for(int i = 1; i <= H; ++i)
    	for(int j = 1; j <= L; ++j)
    		cin>>m[i][j];

	for(int i = 1; i <= H; ++i){
    	for(int j = 1; j <= L; ++j){
    		if(m[i][j] == m[i-1][j])
    			join(element(i,j), element(i-1, j));
    		if(m[i][j] == m[i][j-1])
    			if(find(element(i,j)) != find(element(i, j-1)))
    				join(element(i,j), element(i,j-1));    
    	}
    }

    int ans  = INT_MAX;

    for(int i = 0; i < H*L; ++i){
    	int j = find(i);
    	ans = min(ans, size[j]);
    }

    printf("%d\n", ans);

    return 0;
}