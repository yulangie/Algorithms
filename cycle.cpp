#include <stdio.h>
#include <vector> 
#include <list>

using namespace std;

void print_adjancylist(vector<list<int> >& nodes){ // const
	for (int i=0; i<nodes.size(); ++i) {
		list<int>::iterator it;		// const_iterator
		printf(" node = %d -----> ", i );	
		for (it = nodes[i].begin(); it != nodes[i].end(); ++it ){
			printf( " %d ", *it);
		}
		printf("\n");		
	}


}

void fill_adjacencylist(vector<list<int> >& nodes) { 
	// es ist vielleicht nicht so schoen dass die funktion annahmen daruber macht wieviele eintraege nodes vorher hatte
	// vielleicht koennte man folgendes zu anfang aufrufen: nodes.resize(8, list<int>());
	// und dann brauch der aufrufer (main() ) nur vector<list<int> > anlegen, braucht es noch nicht initialisieren mit werten
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

bool find(int node, vector<bool>& visited, vector<list<int> >& nodes){ // nodes wird nicht veraendert, koennte const gemacht werden
	if (visited[node]) {
		printf("Q: Does node %d has neighbours ? %s\n", node, 
			nodes[node].empty() ? "yes" : "no");
		return (! nodes[node].empty() ) ? true : false; // zu kompliziert?
	}

	visited[node]=true;

	list<int>::const_iterator cit;
	for(cit = nodes[node].begin(); cit != nodes[node].end(); ++cit) {
		printf("neigh =  %d of node %d\n", *cit, node);
		bool found = find(*cit, visited, nodes);
		if (found) {
			return true;
		}
	}
	return false;

}

bool cycle_exist(vector<list<int> >& nodes) { // const ?
	for (int node=0; node<nodes.size(); ++node){
		vector<bool> visited (nodes.size(),false);
		if ( find(node, visited, nodes) ){
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
