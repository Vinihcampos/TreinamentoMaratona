#include <bits/stdc++.h>

using namespace std;

struct team{
	int id;
	int qntd;
	int points;
	vector<int> wrong;
	vector<int> ok;

	team() : qntd{0}, points{0} {}
};

bool comp(team a, team b){
	if(a.qntd > b.qntd){
		return true;
	}else if(a.qntd < b.qntd){
		return false;
	}else{
		if(a.points < b.points) return true;
		else if(a.points > b.points) return false;
		else return a.id < b.id;
	}
}

int main(){

	string inputs;
	map<int,team> teams; 
	getline(cin,inputs);

	string word;
	getline(cin, word);

	for(int i = 0; i < stoi(inputs,nullptr); ++i){
		int id, question, time;
		string status;
		while(getline(cin, word) && word != ""){
			stringstream values;
			values << word;
			values >> id >> question >> time >> status;
			if(status[0] == 'I' || status[0] == 'C'){
				if(teams.find(id) == teams.end()){
					team nt; nt.id = id;
					if(status[0] == 'I'){
						nt.wrong.push_back(question);
					}else{
						nt.ok.push_back(question);
						nt.qntd++;
						nt.points += time;
					}
					teams.insert(make_pair(id, nt));	
				}else{
					if(status[0] == 'I'){
						teams.find(id)->second.wrong.push_back(question);
					}else{
						if(count(teams.find(id)->second.ok.begin(), teams.find(id)->second.ok.end(), question) == 0){
							teams.find(id)->second.ok.push_back(question);
							teams.find(id)->second.qntd++;
							teams.find(id)->second.points += time + count(teams.find(id)->second.wrong.begin(), teams.find(id)->second.wrong.end(), question) * 20;
						}
					}
				}
			}else{
				if(teams.find(id) == teams.end()){
					team nt; nt.id = id;
					teams.insert(make_pair(id,nt));
				}
			}
		}
		vector<team> sorted_teams;
		for(auto it = teams.begin(); it != teams.end(); ++it){
			sorted_teams.push_back(it->second);
		}

		sort(sorted_teams.begin(), sorted_teams.end(), comp);

		auto it = sorted_teams.begin();
		
		for(it = sorted_teams.begin(); it != sorted_teams.end(); ++it){
			cout<<it->id<<" "<<it->qntd<<" "<<it->points<<endl;
		}

		if(i < stoi(inputs) - 1) cout<<endl;
		teams.clear();

	}

	return 0;
}