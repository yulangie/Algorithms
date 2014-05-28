#include <stdio.h>
#include <list>
#include <queue>

using namespace std;

class Node {
public:
	Node(){}
	Node(int key, double val):key(key), val(val){}
	int key;
	double val;
	list<Node* > children;
};

void print_node(Node* node) {
	printf("key = %d and val = %3.4f \n",node->key,node->val);
}

void print_tree_df(Node* node) {
	//print_node(node);
	if (!node->children.empty()) {
		list<Node* >::iterator it;
		for (it=node->children.begin(); 
			it!=node->children.end(); ++it){
			//printf("key=%d\n", (*it)->key );
			print_node(*it);
			print_tree_df(*it);
		}
	}
}

void print_tree_bf(Node* root){
	queue<Node* > allnodes;
	allnodes.push(root);
	list<Node* >::const_iterator it;

	while(!allnodes.empty()){
		Node* node = allnodes.front();
		allnodes.pop();
		
		print_node(node);
		
		for (it = node->children.begin(); 
			it!= node->children.end(); ++it){
			allnodes.push(*it);
		}
	}
}	


Node* find_node(Node* root, int key){

}

void create_testtree(Node& root) {
	root.key = 5;
	root.val = 3.7;
	Node* child1 = new Node(7,8.3);
	Node* child2 = new Node(8,5.2);
	Node* child3 = new Node(9,3.4);

	Node* child21 = new Node(15,-0.1);
	child2->children.push_back(child21);

	root.children.push_back(child1);
	root.children.push_back(child2);
	root.children.push_back(child3);
}


int main (){
	Node root;
	create_testtree(root);
	print_node(&root);
	print_tree_df(&root);
	print_tree_bf(&root);

	return 0;
}