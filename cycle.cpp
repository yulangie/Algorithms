#include <stdio.h>
#include <vector> 
#include <list>

using namespace std;

void print_adjancylist(vector<list<int> >& nodes){
	for (int i=0; i<nodes.size(); ++i) {
		list<int>::iterator it;
		printf(" node = %d -----> ", i );	
		for (it = nodes[i].begin(); it != nodes[i].end(); ++it ){
			printf( " %d ", *it);
		}
		printf("\n");		
	}


}

void fill_adjacencylist(vector<list<int> >& nodes) {
	nodes[0].push_back(1);
	nodes[0].push_back(7);

	nodes[1].push_back(2);
	nodes[1].push_back(3);

	nodes[3].push_back(2);
	nodes[3].push_back(4);

	nodes[4].push_back(7);

	nodes[5].push_back(6);
	nodes[5].push_back(3);

	nodes[7].push_back(0);
}

bool find(int node, vector<int>& status, vector<list<int> >& nodes){
	//if (visited[node]) {
	//	printf("Q: Does node %d has neighbours ? %s\n", node, 
	//		nodes[node].empty() ? "yes" : "no");
	//	return (! nodes[node].empty() ) ? true : false;
	//}
	if (status[node]==-1){
		return false;
	}
	if (status[node]==1) {
		return true;
	}

	status[node]=1;
	//visited[node]=true;

	list<int>::const_iterator cit;
	for(cit = nodes[node].begin(); cit != nodes[node].end(); ++cit) {
		printf("neigh =  %d of node %d\n", *cit, node);
		bool found = find(*cit, status, nodes);
		if (found) {
			return true;
		}
	}
	status[node]=-1;
	return false;

}

bool cycle_exist(vector<list<int> >& nodes) {
	vector<int> status(nodes.size(), 0);
	for (int node=0; node<nodes.size(); ++node){
		//vector<bool> visited (nodes.size(),false);
		if ( find(node, status, nodes) ){
			return true;
		} 
	}
	return false;
}

int main(){
	int N = 8;
	vector<list<int> > nodes(N, list<int> ());
	fill_adjacencylist(nodes);
	print_adjancylist(nodes);

	bool cycle = cycle_exist(nodes);
	printf("Q: does a cycle exist? A: %s\n", cycle ? "yes" : "no");

	return 0;
}