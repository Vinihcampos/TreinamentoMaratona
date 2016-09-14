#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
 
    string s1;
    cin>>s1;
    
    string s2 = "";
    
    for(int i = 0; i < s1.size(); ++i)
        if(s1[i] == 'a' || s1[i] == 'e' || s1[i] == 'i' || s1[i] == 'o' || s1[i] == 'u')
            s2 += s1[i];
    
    string s3(s2.rbegin(), s2.rend());
    
    if(s2 == s3) cout<<"S\n";
    else cout<<"N\n";
    
    return 0;
}