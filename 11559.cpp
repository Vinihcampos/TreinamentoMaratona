#include <iostream>

using namespace std;

int main(){
	int persons, budgets, hotels, weeks;
	int price, minValue, bed;
	bool problem;
	while(cin>>persons>>budgets>>hotels>>weeks){
		minValue = 500001;
		for(int j = 0; j < hotels; ++j){
			problem = true;
			cin>>price;
			for(int i = 0; i < weeks; ++i){
				cin>>bed;
				if(bed >= persons){
					problem = false;
				}
			}
			if(persons * price <= budgets && persons * price < minValue && !problem) {
				minValue = persons * price;
			}
		}
		if(minValue != 500001) cout<<minValue<<endl;
		else cout<<"stay home\n";		
	}
	return 0;
}