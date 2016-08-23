#include <bits/stdc++.h>

using namespace std;

struct elements{
	int father;
	int value;
	int sum;

	elements(int f, int v, int s) : father{f}, value{v}, sum{s} {} 
};

int main(){
	
	stack<elements> negative;

	stringstream ss;
	int number;
	bool valid;
	string values;

	while(getline(cin, values)){
		ss << values;
		valid = true;
		while(ss >> number){
			if(number < 0){
				if(!negative.empty() && negative.top().value < abs(number)){
					valid = false;
					break;
				}else{
					int father;
					
					if(!negative.empty())
						father = negative.top().value;
					else
						father = 0;

					elements e(father,abs(number), 0);
					negative.push(e);
				}
			}else{
				if(!negative.empty() && number == negative.top().value && negative.top().sum < number){
					int father = negative.top().father;
					negative.pop();
					if(!negative.empty() && father == negative.top().value){
						negative.top().sum += number;
					}
				}else{
					valid = false;
					break;
				}
			}
		}

		ss.str( string() );
		ss.clear();

		while(!negative.empty()){
			negative.pop();
			valid = false;
		} 

		if(valid)
			cout<<":-) Matrioshka!\n";
		else
			cout<<":-( Try again.\n";
	}

	return 0;
}