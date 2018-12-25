#include <iostream>
#include <vector>
#include <string>


/* Problem : answer*
   7 1 5 9 6 7 3 : 20
   1 4 4 4 4 1 1  : 16
   1 8 2 2 : 8

 */

using namespace std;

class Problem{
	private:
		vector<int> walls;
		int maxsize;
	public:
		void addWalls(int height);
		Problem();
};

Problem::Problem(){
	maxsize = 0;
}

void Problem::addWalls(int height){
	walls.push_back(height);
}

int solveProblem(Problem &pm){

	/* how to solve this with Div n' Conq ??? **/

	/***/
	return 0;
}

int main()
{
	int nocase = 0;
	int amount = 0;
	int bufferNum = 0;

	Problem * prob;

	cin >> nocase;


	for (int i = 0; i< nocase; i++) {
		prob = new Problem();
		cin >> amount;
		for (int j = 0; j < amount ; j++){
			cin >> buffer;
			prob->addWalls(bufferNum);
		}

		solveProblem(*prob);
	}

	return 0;
}
