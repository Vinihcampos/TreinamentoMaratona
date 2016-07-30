#include <iostream>

using namespace std;

int main(){
	int queries;
	int centerX,centerY;
	int x,y;
	while(cin>>queries && queries != 0){
		cin>>centerX>>centerY;
		for(int i = 0; i < queries; ++i){
			cin>>x>>y;
			if(x == centerX || y == centerY){
				cout<<"divisa\n";
			}else if(x > centerX){
				if(y > centerY)
					cout<<"NE\n";
				else
					cout<<"SE\n";
			}else{
				if(y > centerY)
					cout<<"NO\n";
				else
					cout<<"SO\n";
			}
		}
	}

	return 0;
}