#include <bits/stdc++.h>

using namespace std;

int s[13], h[13], d[13], c[13];

void fill(string card){
	char suit = card[1];
	int index;
	if(card[0] == 'A')
		index = 0;
	else if(card[0] == 'T')
		index = 9;
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

void evaluate(){
    int points = 0, sumS = 0, sumH = 0, sumD = 0, sumC = 0;
	points += s[0] * 4 + h[0] * 4 + d[0] * 4 + c[0] * 4;
	points += s[10] + h[10] + d[10] + c[10];
	points += s[11] * 2 + h[11] * 2 + d[11] * 2 + c[11] * 2;
	points += s[12] * 3 + h[12] * 3 + d[12] * 3 + c[12] * 3;
	
	for(int i = 0; i < 13; ++i){
	    sumS += s[i];
	    sumH += h[i];
	    sumD += d[i];
	    sumC += c[i];
	}
	
	if(s[12] > 0 && sumS - s[12] == 0) --points;
	if(h[12] > 0 && sumH - h[12] == 0) --points;
	if(d[12] > 0 && sumD - d[12] == 0) --points;
	if(c[12] > 0 && sumC - c[12] == 0) --points;
	
	if(s[11] > 0 && (sumS - s[11] < 2)) --points;
	if(h[11] > 0 && (sumH - h[11] < 2)) --points;
	if(d[11] > 0 && (sumD - d[11] < 2)) --points;
	if(c[11] > 0 && (sumC - c[11] < 2)) --points;

	if(s[10] > 0 && (sumS - s[10] < 3)) --points;
	if(h[10] > 0 && (sumH - h[10] < 3)) --points;
	if(d[10] > 0 && (sumD - d[10] < 3)) --points;
	if(c[10] > 0 && (sumC - c[10] < 3)) --points;

	if(points >= 16 && 
	  (s[0] || (s[11] && sumS - s[11] >= 2) || (s[12] && sumS - s[12] >= 1) ) && 
	  (h[0] || (h[11] && sumH - h[11] >= 2) || (h[12] && sumH - h[12] >= 1) ) &&
	  (d[0] || (d[11] && sumD - d[11] >= 2) || (d[12] && sumD - d[12] >= 1) ) &&
	  (c[0] || (c[11] && sumC - c[11] >= 2) || (c[12] && sumC - c[12] >= 1) ) ){
		cout<<"BID NO-TRUMP\n";
	}else{
		if(sumS == 2) ++points;
		if(sumH == 2) ++points;
		if(sumD == 2) ++points;
		if(sumC == 2) ++points;

		if(sumS == 1) points += 2;
		if(sumH == 1) points += 2;
		if(sumD == 1) points += 2;
		if(sumC == 1) points += 2;

		if(sumS == 0) points += 2;
		if(sumH == 0) points += 2;
		if(sumD == 0) points += 2;
		if(sumC == 0) points += 2;
        
		if(points < 14) cout<<"PASS\n";
		else if(sumS >= sumH && sumS >= sumD && sumS >= sumC) cout<<"BID S\n";
		else if(sumH >= sumS && sumH >= sumD && sumH >= sumC) cout<<"BID H\n";
		else if(sumD >= sumH && sumD >= sumS && sumD >= sumC) cout<<"BID D\n";
		else cout<<"BID C\n";
	}
}
int main(){
	
	string card;

	while(cin>>card){
		for(int i = 0; i < 13; ++i){
			s[i] = 0; h[i] = 0; d[i] = 0; c[i] = 0;
		}		
        fill(card);
		for(int i = 0; i < 12; ++i){
			cin>>card;
			fill(card);
		}
		
		evaluate();
	}


	return 0;
}
