#include <bits/stdc++.h>

using namespace std;

string input;
string comand;
int position = 0, lastPos = 0;
float gasoline = 0;
int leaks = 0;
float allSum = 0;
float maxSum = 0;

int main(){
	
	stringstream ss;

	while(getline(cin, input)){
		ss << input;
		ss >> position;

		ss >> comand;
		if(comand == "Fuel"){
			ss >> comand;
			allSum += gasoline * (position - lastPos) + leaks * (position - lastPos);
			ss >> gasoline;
			if(gasoline == 0 && position == 0) return 0;
			gasoline /= 100;			
			lastPos = position;
		}else if(comand == "Gas"){
			allSum += gasoline * (position - lastPos) + leaks * (position - lastPos);
			lastPos = position;
			maxSum = max(allSum, maxSum);
			allSum = 0;
		}else{
			if(comand == "Goal"){
				allSum += gasoline * (position - lastPos) + leaks * (position - lastPos);
				maxSum = max(allSum, maxSum);				
				printf("%.3f\n", maxSum);
				position = 0;
				gasoline = 0;
				allSum = 0;
				maxSum = 0;
				leaks = 0;
			}else if(comand == "Mechanic"){
				allSum += gasoline * (position - lastPos) + leaks * (position - lastPos);
				lastPos = position;
				leaks = 0;
			}else{ // LEAK
				allSum += gasoline * (position - lastPos) + leaks * (position - lastPos);
				lastPos = position;
				++leaks;
			}
		}

		ss.clear();
		ss.str(string());
	}

	return 0;
}