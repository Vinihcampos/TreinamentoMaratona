#include <bits/stdc++.h>

using namespace std;

long long binToDec(string number){
	long long value = 0;
	for(int i = 0; i < number.length(); ++i){
		if(number[i] == '1') {
			value += pow(2, number.length() - 1 - i);
		}
	}

	return value;
}

long long mdc(long long a, long long b){
	if(b == 0){
		return a;
	}else{
		return mdc(b,a%b);
	}
}

int main(){


	int inputs;
	string n1,n2;
	long long a,b;
	cin>>inputs;
	for(int i = 0; i < inputs; ++i){
		cin>>n1>>n2;
		a = binToDec(n1);
		b = binToDec(n2);

		if(b > a) swap(a,b);
		
		cout<<"Pair #"<<i+1<<": ";
		if(mdc(a,b) != 1) cout<<"All you need is love!\n";
		else cout<<"Love is not all you need!\n";
	}

	return 0;
}