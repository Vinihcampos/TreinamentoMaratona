#include <bits/stdc++.h> 

using namespace std;

struct classcomp {
	bool operator() (const vector<string> & a, const vector<string> & b) const{
		for(int i = 0; i < a.size(); ++i){
			if(a[i].size() > b[i].size()) return true;
			else if(a[i].size() < b[i].size()) return false;
			else{
				if(a[i] != b[i]){
					return (a[i].compare(b[i]) <= 0);
				}
			}
		}
		
		return a > b;
	}
};

struct classcomp2 {
	bool operator() (const string & a, const string & b) const{
		if(a.size() > b.size()) return true;
		else if (a.size() < b.size()) return false;
		else
			return (a.compare(b) <= 0);
	}
};

int n,t,p,s;
string input;
vector<string> words;
vector<vector<string>> speech;
set<vector<string>> restriction;

void backtracking(int index, vector<string> curr){
	if(curr.size() > s) return; 
	if(curr.size() == s){
		int cont = 0;
		for(auto it = restriction.begin(); it != restriction.end(); it++){
			cont = 0;
			for(int i = 0; i < s; ++i){
				//cout<<"F: "<<(*it)[0]<<", S: "<<(*it)[1]<<endl;
				if( (*it)[0] == curr[i] || (*it)[1] == curr[i]){
					++cont;	
				}
			}
			if(cont >= 2){ 
				break;
			}
		}
		if(cont < 2){ 
			sort(curr.begin(), curr.end(), classcomp2());
			speech.push_back(curr);
		}
	}else{
		for(int i = index + 1; i < t; ++i){
			curr.push_back(words[i]);
			backtracking(i, curr);
			curr.pop_back();
		}
	}
}

int main(){
	
	getline(cin, input);
	n = stoi(input);
	int cont = 1;

	while(n--){
		stringstream ss;
		getline(cin, input);
		ss << input;
		ss >> t >> p >> s;
		for(int i = 0; i < t; ++i){
			getline(cin, input);
			std::transform(input.begin(), input.end(), input.begin(), [](unsigned char c) { return std::toupper(c); });
			words.push_back(input);
		}
		//sort(words.begin(), words.end(), classcomp2());
		for(int i = 0; i < p; ++i){
			vector<string> s(2);
			ss.str( std::string() );
			ss.clear();
			getline(cin, input);
			ss << input;
			ss >> s[0] >> s[1];
			std::transform(s[0].begin(), s[0].end(), s[0].begin(), [](unsigned char c) { return std::toupper(c); });
			std::transform(s[1].begin(), s[1].end(), s[1].begin(), [](unsigned char c) { return std::toupper(c); });
			restriction.insert(s);
		}
		vector<string> curr;
		for(int i = 0; i <= t - s; ++i){
			curr.push_back(words[i]);
			backtracking(i, curr);
			curr.pop_back();
		}

		printf("Set %d:\n", cont++);
		sort(speech.begin(), speech.end(), classcomp());
		for(auto it = speech.begin(); it != speech.end(); it++){
			for(int i = 0; i < s; ++i){
				if(i == 0)
					cout<<(*it)[i];
				else
					cout<<" "<<(*it)[i];

				if(i == s - 1)
					cout<<endl;
			}
		}

		speech.clear();
		words.clear();
		restriction.clear();

		cout<<endl;
	}

	return 0;
}