#include <stdio.h>
#include <vector>
#include <limits>

using namespace std;

static const double INF = std::numeric_limits<double>::max();


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

void djkstra(vector<vector<double> >& A, vector<double>& dist, int s) {
	int N = A.size();
	vector<bool> done(false);
	vector<vector<double> > P (N,vector<double>(N));
	
	//initial step
	for (int j=0; j<N; ++j) {
		P[0][j]=INF;
	}
	P[0][s]=0;
	//done[s]=true;


	print_graph(P);
	//find shorte

}

int main() {
	int N = 6;
	vector<vector<double> > A (N,vector<double>(N,0));
	create_graph(A);
	print_graph(A);
	vector<double> dist(N,INF);
	djkstra(A,dist,1);
	//printf(" %f ", INF);
}
