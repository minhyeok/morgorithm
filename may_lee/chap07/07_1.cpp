#include <iostream>
#include <vector>
#include <string>

using namespace std;

class treeNode{
public:
	char colour;
	treeNode *child[4];
	treeNode(char _colour);
};

class Problem{
private:
	treeNode *root;
	string compressed;
	string::iterator treeMakingIter;
	void traverseTreeInner(treeNode * node);
	void makeTreeRecursion(treeNode * recurNode);
	void swapVerticalInner(treeNode *node);
public:
	Problem(string quizString);
	void swapVertical();
	void makeTree();
	void traverseTree();
};

Problem::Problem(string quizString){
	compressed = quizString;/* copy members*/
	treeMakingIter = compressed.begin();
}

void Problem::makeTreeRecursion(treeNode * recurNode){
	/* assume that Iterator has increased before enter this function.**/
	if(treeMakingIter == compressed.end())
		return;
	for (int i = 0; i< 4; i++){/* it has 4 child and have to fill this pointer*/
		if(*treeMakingIter=='x') {
			recurNode->child[i] = new treeNode(*treeMakingIter);
			treeMakingIter++;
			makeTreeRecursion(recurNode->child[i]);
			continue;
		} else if (*treeMakingIter == 'w' || *treeMakingIter == 'b'){
			recurNode->child[i] = new treeNode(*treeMakingIter);
		}
		treeMakingIter++;
	}
};

void Problem::traverseTree(){
	traverseTreeInner(this->root);
}
void Problem::traverseTreeInner(treeNode *tree) {

	cout << tree->colour;
	if(tree->colour == 'x'){
		for (int i = 0; i< 4; i++){
			if(tree->child[i] != nullptr){
				traverseTreeInner(tree->child[i]);
			}
		}
	}
}

void Problem::swapVerticalInner(treeNode *tree)
{
	treeNode * temp = nullptr;
	if(tree->colour == 'x'){
		for (int i = 0; i< 4; i++){
			if(tree->child[i] != nullptr){
				swapVerticalInner(tree->child[i]);
			}
		}
		/** swap vertically.*/
		temp = tree->child[0];
		tree->child[0] = tree->child[2];
		tree->child[2] = temp;

		temp = tree->child[1];
		tree->child[1] = tree->child[3];
		tree->child[3] = temp;
	}
}
void Problem::swapVertical()
{
	swapVerticalInner(this->root);
}

void Problem::makeTree(){
	/* make tree with recursing strategy.**/
	/* note: 'x' contains 4 extra elements.*/
	treeNode * currentNode;

	if(*treeMakingIter == 'x') {
		/* you have to do recursion and do same thing.*/
		currentNode = new treeNode(*treeMakingIter);
		this->root = currentNode;
		treeMakingIter++;
		makeTreeRecursion(currentNode);
	} else if(*treeMakingIter == 'w' || *treeMakingIter == 'b'){
		/* if it is stared with child node, don't have to do recursion.**/
		currentNode = new treeNode(*treeMakingIter);
		this->root = currentNode;
	}

}

treeNode::treeNode(char _colour){
	colour = _colour;
	child[0] = nullptr; 
	child[1] = nullptr; 
	child[2] = nullptr; 
	child[3] = nullptr; 
}

int solveProblem(Problem &pm);

int main(){

	int nocase = 0;
	Problem * prob;

	cin >> nocase;
	string quizCase;

	for (int i=0; i< nocase; i++){
		cin >> quizCase;
		prob = new Problem(quizCase);
		solveProblem(*prob);
	}

	delete prob;

	return 0;
}

int solveProblem(Problem &pm){

	/**1. make tree with compressed string.*/
	pm.makeTree();
	/**2. swap first two nodes with last two nodes.*/
	pm.swapVertical();

	/**3. print tree with pre-order traverse */
	cout << "result : "<<endl;
	pm.traverseTree();
	cout << endl;

	return 0;
};
