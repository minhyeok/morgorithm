#include <iostream>
#include <vector>
#include <string>
#include <cstring>

using namespace std;

/***/

int n, board[100][100];
bool jump(int y, int x){
	// base case : out of board;
	if(y >= n || x >= n) return false;
	// base case : reached last place.
	if(y == n-1 && x == n-1) return true;
	int jumpSize = board[y][x];
	return jump(y + jumpSize, x) || jump(y, x + jumpSize);
}

int cache[100][100];
int jump2(int y, int x){
	/* base cases*/
	if(y >= n || x >= n) return 0;
	if(y == n-1 && x == n-1) return 1;
	int& ret = cache[y][x];

	if(ret != -1) return ret;
	int jumpSize = board[y][x];
	return ret = (jump2(y + jumpSize, x) || jump2(y, x + jumpSize));
}


int main()
{
	int nocase = 0;

	/***/

	cin >> nocase;

	for (int i = 0; i < nocase; i++){
		cin >> n;
		/* put board.**/
		for(int j = 0; j < n; j++){
			for (int k = 0; k < n; k++) {
				cin >> board[j][k];
			}
		}
		/* solve problem with above function**/
		memset(cache, 0x00, sizeof(int) * 100 * 100);

		/*case no 1.**/
		cout << "solve with case 1 : " << endl;
		if(jump(0, 0)){
			cout << "    available!" << endl;
		} else {
			cout << "    UNavailable!" << endl;
		}

		cout << "solve with case 2 : " << endl;
		cout << jump2(0, 0) << endl;

	}

	return 0;

}
