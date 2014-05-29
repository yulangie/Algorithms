#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef int (*CallbackType)(int*, int, int); 
const bool print_on = false;


int nr_swap = 0;

void get_data (int* a, int N) {
	for (int i=0; i<N; i++) {
		a[i] = rand() % 102379;
	}
}

void swap(int* a, int i, int j) {
	int c = a[i];
	a[i] = a[j];
	a[j] = c;
	nr_swap++;
}

void print(int* a, int N) {
	if (print_on) {
		for (int i=0; i<N; i++) {
			printf(" %3d ", a[i]);
		}
		printf("\n");	
	}
	
}

int partition(int* a, int begin, int end, int p) {
	// put the pivot at the beginning
	swap(a, begin, p);
	p=begin;
	begin+=1;
	// let begin end end indices approach each other,
	while (begin != end) {
		if (a[begin] > a[p]) {
			swap(a, begin, end);
			end--;
		} 
		else {
			begin++;
		}
	}
	// swap the pivot at the point where 
	// begin = end or begin - 1
	if (a[p] < a[begin]) {
		swap(a, begin-1, p);
		return begin-1;
	}
	else {
		swap(a, p , begin);
		return begin;
	}
}

int get_pivot(int* a, int begin, int end) {
	return begin + (end - begin)/2;
}

int get_pivot_rand (int *a, int begin, int end) {
	int index = begin + rand() % (end-begin + 1) ;  
	return index;
}

int get_pivot_median(int* a, int begin, int end) {
	int x = a[begin];
	int z = a[end];
	int m  = (begin + end)/2;
	int y = a[m]; 
	if (x < y) {
		return (y < z) ? m : ( (x < z) ? end : begin); 
	}
	else {
		return (x < z) ? begin : ( (y < z) ? end : m);
	}
}

void sort(int *a, int begin, int end, CallbackType pivot_function) {
	//print(a,11);
	if (begin == end) {
		return;
	}
	int p = pivot_function(a, begin, end);
	p = partition(a, begin, end, p);
	if (p > begin){ 
		sort(a, begin, p-1, pivot_function);
	}
	if (p < end){
		sort(a, p+1, end, pivot_function);	
	}
	
}

int main() {
	//int a[] = {-4,8,7,1,5,4,2,3,0,-2,6};
	const unsigned long N = 10110;
	srand ( 45804 );
	
	int* a = new int[N];
	get_data(a, N);
	print (a, N);

	//int p = 6;
	//printf("p = %d  and a[p] = %d \n", p, a[p]);
	//int p1 = partition(a, 0, N-1, p);
	//printf("p1 = %d\n", p1);
	//print(a, N);
	sort(a, 0, N-1, &get_pivot);
	print(a, N);
	printf("Nr of swaps for get_pivot = %d\n", nr_swap );



	return 0;
}