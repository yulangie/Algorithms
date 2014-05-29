#include <vector>
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

using namespace std;

void swap(vector<int>& v, int i, int j) {
	int c = v[i];
	v[i]=v[j];
	v[j]=c; 
}

void print(const vector<int>& v) {
	vector<int>::const_iterator it;
	for (it=v.begin(); it!=v.end(); ++it) {
		printf("%8d", *it);
	}
	printf("\n");
}

void print_child(const vector<int>& v, int i) {
	if (i<v.size()){
		printf("%d\n", v[i]);		
	}
	else { 
		printf("No child \n");
	}
}


void make_heap(vector<int>& v, int parent, int last) {
	int size = last + 1;
	if (parent >= (size / 2) ){
		//printf("been here parent = %d last = %d, size = %d, (size/2) = %d\n", 
		//	parent, last, size, (size % 2));
		return;
	}

	int left = 2*parent+1;
	int right = 2*parent+2;
	int curr = parent;
	if ( left <= last && v[left]>v[curr]) {
		curr = left;	
	}
	if (right <= last && v[right]>v[curr]) {
		curr = right;
	}
	
	if (curr != parent){
		swap(v, curr, parent);
		make_heap(v, curr, last);
		//return;
	}
}


void make_heaptree(vector<int>& v, int last) {
	for (int i=(last-1)/2; i>=0; --i){
		make_heap(v,i,last);
	}

}

void sort(vector<int>& v ){	
	int last = v.size()-1;
	make_heaptree(v,last);

	while ( last !=0 ) {
		swap(v,0,last);
		make_heap(v,0,--last);
		//print(v);
	}
}

void get_testdata(vector<int>& v) {
	int N=11;
	int array[]={10,1,4,5,6,7,2,4,8,3,0};
	v.insert(v.begin(),array, array+N);
}

void get_randomdata(vector<int>& v, int N){
	
	for (int i=0; i<N; ++i) {
		int c = rand() % 1002; 
		//printf("c = %d\n", c);
		v[i] =  c;
	}
}

int main(){
	int N = 25;
	vector<int> v(N);
	//get_testdata(v);
	srand ( 4580 );

	get_randomdata(v,N);
	print(v);

	sort(v);
	//make_heaptree(v,v.size()-1);
	print(v);

	return 0;
}