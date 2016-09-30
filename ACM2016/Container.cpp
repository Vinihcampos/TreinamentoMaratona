#include <bits/stdc++.h>

using namespace std;

struct Container{
	int id;
	int m[2][4];
	int value;

	Container(int v = 0) : value{v} {
		m[0][0] = 0;
		m[0][1] = 0;
		m[0][2] = 0;
		m[0][3] = 0;
		m[1][0] = 0;
		m[1][1] = 0;
		m[1][2] = 0;
		m[1][3] = 0;
	}
};

long long matrixToLongLong(const Container & c){
	long long r = 0;
	long long multi = 1;
	for(int i = 0; i < 2; ++i){
		for(int j = 0; j < 4; ++j){
			multi *= 1000;
			r += c.m[i][j] * multi;
		}
	}
	return r;
}

bool isEqual(const Container& a, const Container& b){
	for(int i = 0; i < 2; ++i)
		for(int j = 0; j < 4; ++j)
			if(a.m[i][j] != b.m[i][j])
				return false;

	return true;
}

map<long long, int> containers;

bool updateValue(Container & c){

	long long r = matrixToLongLong(c);
	auto it = containers.find(r);
	if(it != containers.end()){
		if(it->second > c.value){
			it->second = c.value;
			return true;
		}
		return false;
	}else{
		containers.insert(make_pair(matrixToLongLong(c), c.value));
		return true;
	}

}

void dijkstra(Container & inicial){

	queue<Container> fila;
	fila.push(inicial);
	while(!fila.empty()){

		Container c;

		c = fila.front();
		swap(c.m[0][0], c.m[0][1]);
		c.value += c.m[0][0] + c.m[0][1];
		if(updateValue(c)){
			fila.push(c);
		}
		
		c = fila.front();
		swap(c.m[0][0], c.m[1][0]);
		c.value += c.m[0][0] + c.m[1][0];
		if(updateValue(c)){
			fila.push(c);
		}

		c = fila.front();
		swap(c.m[0][1], c.m[0][2]);
		c.value += c.m[0][1] + c.m[0][2];
		if(updateValue(c)){
			fila.push(c);
		}

		c = fila.front();
		swap(c.m[0][1], c.m[1][1]);
		c.value += c.m[0][1] + c.m[1][1];
		if(updateValue(c)){
			fila.push(c);
		}

		c = fila.front();
		swap(c.m[0][2], c.m[0][3]);
		c.value += c.m[0][2] + c.m[0][3];
		if(updateValue(c)){
			fila.push(c);
		}

		c = fila.front();
		swap(c.m[0][2], c.m[1][2]);
		c.value += c.m[0][2] + c.m[1][2];
		if(updateValue(c)){
			fila.push(c);
		}

		c = fila.front();
		swap(c.m[0][3], c.m[1][3]);
		c.value += c.m[0][3] + c.m[1][3];
		if(updateValue(c)){
			fila.push(c);
		}

		c = fila.front();
		swap(c.m[1][0], c.m[1][1]);
		c.value += c.m[1][0] + c.m[1][1];
		if(updateValue(c)){
			fila.push(c);
		}

		c = fila.front();
		swap(c.m[1][1], c.m[1][2]);
		c.value += c.m[1][1] + c.m[1][2];
		if(updateValue(c)){
			fila.push(c);
		}

		c = fila.front();
		swap(c.m[1][2], c.m[1][3]);
		c.value += c.m[1][2] + c.m[1][3];
		if(updateValue(c)){
			fila.push(c);
		}
		
		fila.pop();
	}
}

int main(){

	Container inicial;
	Container final(INT_MAX);

	for(int i = 0; i < 2; ++i){
		for(int j = 0; j < 4; ++j){
			cin>>inicial.m[i][j];
		}
	}

	for(int i = 0; i < 2; ++i){
		for(int j = 0; j < 4; ++j){
			cin>>final.m[i][j];
		}
	}

	if(isEqual(final, inicial)){
		cout<<"0\n";
	}else{
		containers.insert(make_pair(matrixToLongLong(inicial), 0));
		containers.insert(make_pair(matrixToLongLong(final), final.value));
		dijkstra(inicial);
		cout<<containers.find(matrixToLongLong(final))->second<<endl;
	}
	

	return 0;
}