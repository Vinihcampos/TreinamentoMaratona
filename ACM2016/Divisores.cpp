#include <bits/stdc++.h>

using namespace std;

int main(){
	
	unsigned long long a,b,c,d,n;

	cin>>a>>b>>c>>d;
	n = a;

	while(n <= 2 * (a + sqrt(c)) ){
		if(n%a == 0 && n%b != 0 && c%n == 0 && d%n != 0){
			cout<<n<<endl;
			return 0;
		}else{
			n += a;
		}
	}

	cout<<"-1\n";

	return 0;
}