#include <bits/stdc++.h>

using namespace std;

int n,l,w;
double x,y;
vector<pair<double,double>> sprinklers;
list<pair<double,double>> grass; 

bool comp(pair<double,double> a,pair<double,double> b){
	double da = a.second - a.first;
	double db = b.second - b.first;

	if(a.first < b.first) return true;
	else if(a.first == b.first){
		if(da > db) return true;
		else return false;
	}else{
		return false;
	}
}

int count_sprinklers(){
	int counter = 0;
	for(int i = 0; i < sprinklers.size(); ++i){
		//cout<<"Pos: "<<sprinklers[i].first<<",Radious: "<<sprinklers[i].second<<endl;
		double minimum = sprinklers[i].first;
		double maximum = sprinklers[i].second;
		if(grass.empty()){
			//cout<<"**Pos: "<<sprinklers[i].first<<",Radious: "<<sprinklers[i].second<<", Delta: "<<delta<<endl;
			++counter;
			grass.push_back(make_pair(minimum, maximum));
		}else{
			bool found = false;
			for(auto it = grass.begin(); it != grass.end(); it++){
				if(it->first <= minimum && it->second >= maximum){
					found = true; break;
				}else if(it->first < maximum && it->first > minimum){
					it->first = minimum;
					++counter; 
					found = true; 
					if(it != grass.begin()){
						auto it2 = it; it2--;
						if(it2->second > it->first){
							it2->second = it->second;
							grass.erase(it);
						}
					}
					break;
				}else if(it->second > minimum && it->second < maximum){
					it->second = maximum;
					++counter; 
					found = true;
					auto it2 = it; it2++; 
					if(it2 != grass.end()){						
						if(it->second > it2->first){
							it->second = it2->second;
							grass.erase(it2);
						}
					}
					break;
				}else if(maximum <= it->first){
					grass.insert(it,make_pair(minimum, maximum));
					++counter;
					found = true;
					break;
				}
			}
			if(!found){
				grass.push_back(make_pair(minimum, maximum));
				++counter;
			}
		}
	}

	if(grass.size() != 1) return -1;
	else if(grass.begin()->second - grass.begin()->first < l) return -1;
	else return counter;
}

int main(){

	while(scanf("%d %d %d", &n, &l, &w) != EOF){
		for(int i = 0; i < n; ++i){
			scanf("%lf %lf", &x, &y);
			//cout<<x<<" "<<y<<endl;
			if(y >= w/2){

				double delta = sqrt(pow(y, 2) - pow( w/2.0 , 2));
				double minimum = x - delta;
				double maximum = x + delta;

				if((0 <= minimum && minimum <= l) || (0 <= maximum && maximum <= l) || (minimum <= 0 && maximum >= l)){
					if(minimum < 0) minimum = 0;
					if(maximum > l) maximum = l;
					sprinklers.push_back(make_pair(minimum,maximum));
					//cout<<"minimum: "<<minimum<<", maximum: "<<maximum<<", Delta: "<<delta<<endl;
				}				
			}
		}

		//cout<<sprinklers.size()<<endl;

		sort(sprinklers.begin(), sprinklers.end(), comp);

		//for(int i = 0; i < sprinklers.size(); ++i){
		//	cout<<"minimum: "<<sprinklers[i].first<<", maximum: "<<sprinklers[i].second<<", Delta: "<<sprinklers[i].second - sprinklers[i].first<<endl;
		//}

		printf("%d\n", count_sprinklers());

		grass.clear();
		sprinklers.clear();
	}
	
	return 0;
}