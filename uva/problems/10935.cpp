#include <bits/stdc++.h>

using namespace std;

int main(){
	
	queue<int> cards;
	int size;

	while(scanf("%d", &size) != EOF && size != 0){
		for(int i = 1; i <= size; ++i) 
			cards.push(i);
		
		printf("Discarded cards:");
		if(cards.front() == cards.back()) printf("\n");
		while(cards.front() != cards.back()){
			printf(" %d", cards.front());
			cards.pop();
			
			cards.front() != cards.back() ? printf(",") : printf("\n");
			cards.push(cards.front());
			cards.pop();
		}
		printf("Remaining card: %d\n", cards.front());
		cards.pop();
	}

	

	return 0;
}