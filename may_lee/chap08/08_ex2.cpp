#include <iostream>
#include <cmath>
#include <cstring>

using namespace std;

/* it causes 'relocation to fit' error when linking process**/
#define MAX_NUMBER 100

int n , triangle[100][100];
int cache[100][100][MAX_NUMBER * 100+1];
int catche[100][100];

int path1(int y, int x, int sum){
	if( y == n-1) return sum + triangle[y][x];
	//memoize
	int & ret = cache[y][x][sum];
	if(ret != -1) return ret;
	sum += triangle[y][x];
	return ret = max(path1(y+1, x+1, sum) , path1(y+1, x, sum));
}

int path2(int y, int x){
	if (y == n -1 ) return triangle[y][x];
	//memoize
	int & rt = catche[y][x];
	if(rt != -1) return rt;
	return rt = max(path2(y+1, x), path2(y+1, x+1)) + triangle[y][x];
}

int main()
{
	int nocase = 0;
	
	cin >> nocase;

	for (int i = 0 ; i < nocase ; i++){
		cin >> n;
		for (int j = 0; j < n; j++) {
			for (int k = 0; k <= j; k++){
				cin >> triangle[j][k];
			}
		}
		memset(cache, 0xff, sizeof(int) * 100 * 100 * (MAX_NUMBER +1));
		memset(catche, 0xff, sizeof(int) * 100 * 100);

#if 0
		cout << "solve with typical memoization : " << endl;
		cout << path1(0, 0, 0) << endl << endl;
#endif
		cout << "solve with optimized memoization : " << endl;
		cout << path2(0, 0) << endl << endl;
	}
}
