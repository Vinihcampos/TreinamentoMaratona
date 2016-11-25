#include <bits/stdc++.h>

using namespace std;

map<string, int> words;

int bkt(string w){
    if(w == "") return 1;
    else{
        auto it = words.find(w);
        if(it != words.end()){
        	//out<<"It: "<<it->first<<","<<it->second<<endl;
        	return it->second;
        }         
        char aux = w[0];
        int start = 0, finish = 0;
        for(int i = 1; i < w.size(); ++i){
        	//cout<<"Aux: "<<aux<<", (I,J): "<<start<<","<<finish<<endl;
        	//cout<<"Word: "<<w<<endl;
            if(w[i] == aux){
                finish = i;
            }
            if(w[i] != aux || i == w.size() - 1){
                if(finish > start){
                    string backtracking = "";
                    if(start == 0){
                        backtracking = w.substr(finish + 1, w.size() - (finish + 1));
                    }else if(finish == w.size() - 1){
                        backtracking = w.substr(0, start);
                    }else{
                        backtracking = w.substr(0, start) + w.substr(finish + 1, w.size() - (finish + 1));
                    }
                    //cout<<"Palavra: "<<backtracking<<", (I,J): "<<start<<","<<finish<<endl;
                    it = words.find(backtracking);
                    if(it != words.end() && it->second == 1) return 1;                    
                    else if(bkt(backtracking) == 1){
                        words.insert( make_pair(w, 1) );
                        return 1;
                    }
                }
                aux = w[i];
                start = i;
                finish = i;
            }
        }
        //cout<<"Chegou e zerou: "<<w<<endl;
        words.insert( make_pair(w, 0) );
        return 0;
    }
}

int main(){
	
	int t;
	scanf("%d", &t);
	while(t--){
		string word;
		cin>>word;
		cout<<bkt(word)<<endl;
		words.clear();
	}

	return 0;
}