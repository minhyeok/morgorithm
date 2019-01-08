#include <iostream>
#include <vector>

using namespace std;

struct problem{
	char board[21][21];
	int answerCount;

};

int main()
{
	int nocase;
	int h = 0, w = 0;
	problem * prob;

	cin >> nocase;

	for (int i = 0; i < nocase; i++) 
	{
		prob = new problem;
		/**input board*/
		cin >> h;
		cin >> w;
		for(int j = 0; j < h ; j++) {
			cin >> board[j];
		}
		prob->board 


	}

	return 0;
}
