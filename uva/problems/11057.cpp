#include <bits/stdc++.h>

using namespace std;

int n, v;
vector<int> books;
vector<int> books_aux;
pair<int,int> answer;

int main(){
	
	while( scanf("%d", &n) != EOF){
		for(int i = 0; i < n; ++i){
			scanf("%d", &v);
			books.push_back(v);
		}

		sort(books.begin(), books.end());

		scanf("%d", &v);
		answer  = make_pair(0, INT_MAX);
		for(int i = 0; i < n; ++i){
			int remain = v - books[i];
			if(remain == 0) continue;
			else{
				books_aux = books;
				books_aux.erase(books_aux.begin() + i);
				if(binary_search(books_aux.begin(), books_aux.end(), remain)){
					if(abs(books[i] - remain) < abs(answer.first - answer.second)){
						answer.first = books[i];
						answer.second = remain;
					}
				}
			}
		}

		answer.first < answer.second ? printf("Peter should buy books whose prices are %d and %d.\n\n", answer.first, answer.second) : printf("Peter should buy books whose prices are %d and %d.\n\n", answer.second, answer.first);

		books.clear();
	}

	return 0;
}