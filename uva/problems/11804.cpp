#include <bits/stdc++.h>

using namespace std;

vector<pair<string, pair<int,int>>> players;
set<string> s;
set<string> f;
bool comp( pair<string, pair<int,int>> a, pair<string, pair<int,int>> b ){

	if(a.second.first > b.second.first){
		return true;
	}else if(a.second.first == b.second.first){
		if(a.second.second < b.second.second){
			return true;
		}else if(a.second.second == b.second.second){
			if(a.first < b.first) return true;
			else return false;
		}else{
			return false;
		}
	}else{ 
		return false;
	}
}

bool comp2( pair<string, pair<int,int>> a, pair<string, pair<int,int>> b ){
	if(a.first < b.first) return true;
	else return false;
}


int main(){
	
	int tests;
	string t;
	getline(cin, t);
	tests = stoi(t);

	for(int i = 0; i < 	tests; ++i){
		for(int j = 0; j < 10; ++j){
			int a,d;
			string name;
			string input;
			getline(cin, input);
			stringstream ss;
			ss << input;
			ss >> name >> a >> d;

			players.push_back( make_pair( name, make_pair( a,d ) ) );
		}

		sort(players.begin(), players.end(), comp);

		for(int i = 0; i < 10; ++i){
			if(i < 5)
				s.insert(players[i].first);
			else
				f.insert(players[i].first);
		}
		cout<<"Case "<<i+1<<":\n(";
		int cont = 0;	
		for(auto i = s.begin(); i != s.end(); i++){
			if(cont == 4){
				cout<<*i<<")\n(";
				cont = 0;
			}
			else{
				cout<<*i<<", ";
				++cont;
			}
		}
		for(auto i = f.begin(); i != f.end(); i++){
			if(cont == 4){
				cout<<*i<<")\n";
				cont = 0;
			}
			else{
				cout<<*i<<", ";
				++cont;
			}
		}
		players.clear();
		s.clear();
		f.clear();
	}
}