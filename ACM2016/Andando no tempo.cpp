#include <iostream>
 
using namespace std;
 
int main() {
 
    int a,b,c;
    
    cin>>a>>b>>c;
    
    bool r = (a == b || a == c || b == c) || (a == b + c || b == a + c || c == b + a );
    
    r ? cout<<"S\n" : cout<<"N\n";
 
    return 0;
}