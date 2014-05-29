#include <stdio.h>
#include <vector>
#include <limits>
#include <iostream>

using namespace std;

static const double INF = std::numeric_limits<int>::max();

void print_vec(vector<double>& v) {
	//cout << v[2] << " test ";
	//cout << v.size() << "\n";
	//printf("size more %d\n",v.size());
	printf("vector is ");
	for (int i=0; i< v.size(); ++i) {
		printf(" %2.2f ", v[i]);
	}
	printf("\n");
}

void print_graph(vector<vector<double> >& A) { // how about using  const vector<vector<double> >&
	int N = A.size();
	//printf("%d \n",N);
	for (int i=0; i<N; ++i) {
		for (int j=0; j<N; ++j) {
			if(A[i][j]==INF){
				printf(" %2.1f ",-1.);
			}
			else{
				printf(" %2.1f ", A[i][j]);
			}
		}	
		printf("\n");
	}

}

void symmetrise(vector<vector<double> >& A) {
	for (int i=0; i<A.size(); ++i) {
		for (int j=0; j<A.size(); ++j) {
			if (A[i][j]>0) {
				A[j][i]=A[i][j];
			}
		}	
	}
}

void create_graph(vector<vector<double> >& A) {
	A[0][2]=0.2;
	A[0][3]=0.1;
	A[2][5]=0.4;
	A[5][3]=1.0;
	A[3][1]=0.7;
	A[3][4]=0.3;
	A[4][1]=2.0;
	symmetrise(A);
}

//void check_neighbours(vector<vector<double> > P, int node) {
//}
int get_min(vector<double>& v, vector<bool>& done){
	//cout << "bool ";
	for (int i=0; i<done.size();++i){
		//printf("v[i]%d\n", v[i]);
		//cout << done[i] << "\n";
	}
	int min = INF;
	int min_i = 0;
	for (int i=0; i<v.size(); ++i) {
		
		if (v[i]<min && done[i]==false) {
			//printf(" i = %d, v[i]= %2.2f", i, v[i]);
			min = v[i];
			min_i = i;
		}
	}
	return min_i;	
}

void initialise(vector<vector<double> >& P) {
	printf("size P %d\n", P[0].size());
	for (int j=0; j<P.size(); ++j) {
		P[0][j]=INF;
	}

}

void dijkstra(vector<vector<double> >& A, vector<double>& dist, int s) {
	int N = A.size();
	vector<bool> done(N,false);
	vector<vector<double> > P (N+1,vector<double>(N,INF));
	
	//initial step
	initialise(P);
	P[0][s]=0;
	//done[s]=true;


	for (int step=1; step<1+1; ++step){

		int node = get_min(P[step-1], done);
		cout << "node = " << node << "\n";
		print_vec(P[node]);
		for (int j=0; j<N; ++j) {
			if (done[j] == false) {
			//if (A[node][j] > 0 && done[j] == false) {
				int new_dist = P[step-1][node] + A[node][j]; 

				P[step][j] = (new_dist < P[step-1][j]) ? new_dist : P[step-1][j];
				cout << "get here \n";
			}
			done[node]=true;
		}
		//cout << "step = " << step << " \n";
		cout << " P[step][3] " << P[step][3] << "\n ";
		print_vec(P[node]);
	}

	for(int i=0; i<done.size(); ++i) {
		cout << "done = " << done[i];
	}
	cout << "\n";
	//print_graph(P);
	//find shorte

}


int main() {
	int N = 6;
	vector<vector<double> > A (N,vector<double>(N,0));
	create_graph(A);
	print_graph(A);
	vector<double> dist(N,INF);
	//cout << " print " << &A[0] << "\n";
	//cout << " print " << &A[0][0] << "\n";
	//print_vec( (A[0]) ) ;
	dijkstra(A,dist,1);
	//printf(" %f ", INF);
}
