#include <bits/stdc++.h>

using namespace std;

int main(){
	
	int inputs;
	int dateCurrent[3],dateBirth[3];
	string current, birth;
	cin>>inputs;

	for(int i = 0; i < inputs; ++i){
		cin>>current;
		cin>>birth;

		dateCurrent[0] = stoi(current.substr(0,2),nullptr);
		dateCurrent[1] = stoi(current.substr(3,2),nullptr);
		dateCurrent[2] = stoi(current.substr(6,4),nullptr);

		dateBirth[0] = stoi(birth.substr(0,2),nullptr);
		dateBirth[1] = stoi(birth.substr(3,2),nullptr);
		dateBirth[2] = stoi(birth.substr(6,4),nullptr);

		cout<<"Case #"<<i+1<<": ";

		int ageC = dateCurrent[2] * 360 + dateCurrent[1] * 30 + dateCurrent[0];
		int ageB = dateBirth[2] * 360 + dateBirth[1] * 30 + dateBirth[0];
		int age = ageC - ageB;
		if(age < 0){
			age = -1;	
		}else{
			if(age > 0){
				age = age/360;
			}
		}

		age > 130 ? cout<<"Check birth date\n" : age < 0 ? cout<<"Invalid birth date\n" : cout<<age<<endl;
	}

	return 0;
}