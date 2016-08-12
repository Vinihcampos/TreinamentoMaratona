#include <bits/stdc++.h>

using namespace std;

int main(){

	string word;
	string aux_word = "";
	while(getline(cin, word) && word != "DONE"){
		for(int i = 0; i < word.length(); ++i){
			if((word[i] > 96 && word[i] < 123) || (word[i] > 64 && word[i] < 91)){
				char c = toupper(word[i]);
				aux_word = aux_word + c;
			}			
		}
		int i = 0;
		for(i = 0; i <= aux_word.length()/2; ++i){
			if(aux_word[i] != aux_word[aux_word.length()-1-i]){
				cout<<"Uh oh..\n";
				i = -1;
				break;
			}
		}

		if(i != -1)
			cout<<"You won't be eaten!\n";

		aux_word = "";
	}

	return 0;
}