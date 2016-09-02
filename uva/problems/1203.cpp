#include <bits/stdc++.h>

using namespace std;

map<int, vector< pair<int,int> > > argus;
set<int> aux;

int main(){
	

	string query;
	stringstream ss;
	int id, time, queries, min_seconds = 0, seconds = 0;

	while(getline(cin, query) && query != "#"){
		ss << query;
		ss >> query >> id >> time;

		if(argus.find(time) != argus.end()){
			argus[time].push_back(make_pair(id, 0));
		}else{
			vector<pair<int,int>> newQuery;
			newQuery.push_back(make_pair(id, 0));
			argus.insert(make_pair(time,newQuery));
		}
		ss.clear();
	}

	for(auto it = argus.begin(); it != argus.end(); ++it){
		if(it == argus.begin()){
			min_seconds = it->first;
			time = it->first;
		}else{
			if(it->first - time < min_seconds){
				min_seconds = it->first - time;
				time = it->first;
			}
		}
	}

	cin>>queries;
	while(queries > 0){
		seconds += min_seconds;
		
		auto it = argus.begin();
		for(; it != argus.end(); ++it){
			if(seconds/it->first > 0 && seconds/it->first > it->second.begin()->second){
				for(auto it_set = it->second.begin(); it_set != it->second.end(); ++it_set){
					aux.insert(it_set->first);
					it_set->second++;	
				}
			}
		}
		//cout<<"Seconds: "<<seconds<<endl;
		//cout<<"Size: "<<aux.size()<<endl;

		for(auto iterator = aux.begin(); iterator != aux.end(); ++iterator){
			cout<<*iterator<<endl;
			--queries;
			if(queries == 0)
				break;
		}

		aux.clear();

		//it = argus.end(); it--;		
		//if(seconds >= it->first) seconds = 0;
	}
}