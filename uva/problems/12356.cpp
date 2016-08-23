#include <bits/stdc++.h>

using namespace std;

bool soldiers[1000001];

struct pointers{
	int i;
	pointers * l;
	pointers * r;

	pointers(int _i = 0, pointers * _l = nullptr, pointers * _r = nullptr) : i{_i}, l{_l}, r{_r}{}
};

int main(){
	
	int s, b;
	while(cin>>s>>b && s != 0 && b != 0){
		pointers * left = new pointers(1, nullptr, nullptr);
		pointers * right = new pointers(s, left, nullptr);
		left->r = right;
		pointers root(0, left, right);

		memset(soldiers + 1, false, s);
		string l = "*";
		string r = "*";

		int kl, kr;

		for(int i = 0; i < b; ++i){
			l = "*";
			r = "*";
			cin>>kl>>kr;
			memset(soldiers + kl, true, kr - kl + 1);

			pointers * newL = new pointers()
			
			cout<<l<<" "<<r<<endl;
		}

		cout<<"-"<<endl;
	}

}