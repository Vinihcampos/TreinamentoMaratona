#include <bits/stdc++.h>

using namespace std;

struct Node{
	int center;
	int side;
};

void calculateHeights(vector<int> & height, Node nodes[10000]){
	queue<int> centers;
	centers.push(1);

	while(!centers.empty()){

		int h = 0;
		int c = centers.front();
		
		while(c != 0){
			h++;
			if(nodes[c].side != 0) centers.push(nodes[c].side);
			c = nodes[c].center;			
		}
		height.push_back(h);
		centers.pop();
	}
}

int main(){
	Node right[10001];
	Node left[10001];
	vector<int> heightL;
	vector<int> heightR;

	int l,r;
	int n,c,s;

	scanf("%d", &l);
	for(int i = 0; i < l; ++i){
		scanf("%d %d %d", &n, &s, &c);
		left[n].center = c;
		left[n].side = s;
	}

	scanf("%d", &r);
	for(int i = 0; i < r; ++i){
		scanf("%d %d %d", &n, &c, &s);
		right[n].center = c;
		right[n].side = s;
	}

	calculateHeights(heightL, left);
	calculateHeights(heightR, right);

	auto hl = max_element(heightL.begin(), heightL.end());
	auto hr = max_element(heightR.begin(), heightR.end());

	if(heightL[0] > heightR[0]){
		printf("%d\n", l + r - min(heightL[0], *hr));
	}else{
		printf("%d\n", l + r - min(heightR[0], *hl));
	}

	return 0;
}