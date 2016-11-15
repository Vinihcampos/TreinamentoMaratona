#include <iostream>

using namespace std;

int main(){
	
	int t; 
	cin>>t;
	int n_bus_stop, input;
	for(int times = 1; times <= t; ++times){
		cin>>n_bus_stop;
		int maxi = 0, curr = 0;
		int start = -1, finish = -1;
		int startF = -1, finishF = -1;  
		for(int i = 0; i < n_bus_stop - 1; ++i){
			cin>>input;
			if(curr + input >= 0){
				curr += input;
				if(start == -1){
					start = i + 1;
				}
				finish = i + 2;
			}else{
				curr = 0;				
				start = -1;
				finish = -1;
			}

			if(curr > maxi || (curr == maxi && finish - start > finishF - startF)){
				maxi = curr;
				startF = start;
				finishF = finish;
			}
		}

		if(maxi > 0){
			cout<<"The nicest part of route " << times << " is between stops "<< startF <<" and "<< finishF <<endl;
		}else{
			cout<<"Route " << times << " has no nice parts\n";
		}
	}

	return 0;
}