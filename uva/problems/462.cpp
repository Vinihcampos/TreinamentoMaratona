#include <bits/stdc++.h>

using namespace std;

int s[13], h[13], d[13], c[13];

void fill(string card){
	char suit = card[1];
	int index;
	if(card[0] == 'A')
		index = 0;
	else if(card[0] == 'T')
		index = 9
	else if(card[0] == 'J')
		index = 10;
	else if(card[0] == 'Q')
		index = 11;
	else if(card[0] == 'K')
		index = 12;
	else
		index = card[0] - 49;

	switch(suit){
		case 'S':
			s[index]++;
		break;
		case 'H':
			h[index]++;
		break;
		case 'D':
			d[index]++;
		break;
		case 'C':
			c[index]++;
		break;
		default:
		break;
	}
}

int main(){
	
	string card;

	while(getline(cin, card)){
		for(int i = 0; i < 13; ++i){
			s[i] = 0; h[i] = 0; d[i] = 0; c[i] = 0;
		}
		

		for(int i = 0; i < 12; ++i){
			
		}

	}


	return 0;
}