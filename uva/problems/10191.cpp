#include <bits/stdc++.h>

using namespace std;

int main(){

	char time[480];

	string inputs;
	int count = 1;
	while(getline(cin, inputs)){
		
		string curent;
		int value = stoi(inputs,nullptr);
		memset(time, '0' , 480);

		for(int i = 0; i < value; ++i){
			getline(cin, curent);
			int start = stoi(curent.substr(0,2),nullptr) * 60 + stoi(curent.substr(3,2),nullptr);
			int finish = stoi(curent.substr(6,2),nullptr) * 60 + stoi(curent.substr(9,2),nullptr);

			for(int j = start - 600; j < finish - 600; ++j){
				time[j] = '1';
			}
				
		}
		int interval = 0, startTime = 0, auxInterval = 0, auxStartTime = 0;
		for(int i = 0; i < 480; ++i){
			if(time[i] == '0'){
				if(auxStartTime == 0){
					auxStartTime = 600 + i;
				}
				++auxInterval;
			}else{
				if(auxInterval != 0){
					if(auxInterval > interval){
						interval = auxInterval;
						startTime = auxStartTime;
					}
					auxInterval = 0;
					auxStartTime = 0;
				}
			}
		}

		if(auxInterval != 0){
			if(auxInterval > interval){
				interval = auxInterval;
				startTime = auxStartTime;
			}
			auxInterval = 0;
			auxStartTime = 0;
		}
		
		cout<<"Day #"<<count++<<": the longest nap starts at "<<startTime/60<<":";
		startTime%60 == 0 ? cout<<"00" : startTime%60 < 10 ? cout<<"0"<<startTime%60 : cout<<startTime%60;
		
		if(interval/60 > 0)
			cout<<" and will last for "<<interval/60<<" hours and "<<interval%60<<" minutes.";
		else
			cout<<" and will last for "<<interval%60<<" minutes.";

		cout<<endl;
	}

	return 0;
}