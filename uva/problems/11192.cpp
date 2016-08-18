#include <bits/stdc++.h>

using namespace std;

int main(){

	int length;
	string word;
	while(cin>>length && length != 0){
		cin>>word;
		for(int i = 0; i < word.length(); i += word.length()/length){
			for(int j = i + (word.length()/length - 1); j >= i; --j){
				cout<<word[j];
			}
		}
		cout<<endl;
	}

	return 0;
}