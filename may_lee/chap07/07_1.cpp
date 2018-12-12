#include <iostream>
#include <vector>
#include <string>

using namespace std;

class treeNode;

class Problem{
private:
	treeNode *root;
	string compressed;
	string::iterator treeMakingIter;
	void makeTreeRecursion();
public:
	Problem(string quizString);
	void makeTree();
	void traverseTreePreOrder();
};

Problem::Problem(string quizString){
	compressed = quizString;/* copy members*/
	treeMakingIter = compressed.begin();
}

void Problem::makeTreeRecursion(treeNode * recurNode){
	for (int i = 0; i< 4; i++){
	}
};

void traverseTreePreOrder() {
}

void Problem::makeTree(){
	/* make tree with recursing strategy.**/
	/* note: 'x' contains 4 extra elements.*/
	treeNode * currentNode;

	if(*treeMakingIter == 'x') {
		/* you have to do recursion and do same thing.*/
		currentNode = new treeNode(*treeMakingIter);
		this.root = currentNode;
		makeTreeRecursion(currentNode);
	} else if(*treeMakingIter == 'w' || *treeMakingIter == 'b'){
		/* if it is stared with child node, don't have to do recursion.**/
		currentNode = new treeNode(*treeMakingIter);
	}

}

class treeNode{
public:
	char colour;
	treeNode *child[4];
	treeNode(char _colour);
};

treeNode::treeNode(char _colour){
	colour = _colour;
	child[0] = NULL; 
	child[1] = NULL; 
	child[2] = NULL; 
	child[3] = NULL; 
}

int solveProblem(Problem &pm);

int main(){

	int nocase = 0;
	Problem * prob;

	cin >> nocase;

	for (int i=0; i< nocase; i++){
		prob = new Problem;
		cin >> prob->compressed;
		solveProblem(prob);
	}

	return 0;
}

int solveProblem(Problem &pm){

	/**1. make tree with compressed string.*/

	/**2. swap first two nodes with last two nodes.*/

	/**3. print tree with pre-order traverse */

	return 0;
};
