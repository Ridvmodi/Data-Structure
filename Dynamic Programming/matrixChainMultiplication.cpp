#include<iostream>
using namespace std;

int findMinimumMulti(int *dimensions, int size) {

	int dp[size][size];
	int i, j, k, l;
	
	// l is the length of multiplication chain

	for(i = 1;i<size;i++) {
		dp[i][i] = 0;
	}

	for(int l = 2;l<size;l++) {

		for(int i = 1;i<size - l + 1;i++) {
			j = i + l - 1;
			dp[i][j] = 32768;
			for(int k = i;k<=j-1;k++) {
				int tempRes = (dp[i][k] + dp[k+1][j] + dimensions[i-1] * 					dimensions[k] * dimensions[j]);
				dp[i][j] = dp[i][j] < tempRes ? dp[i][j] : tempRes;
			}
		}
	}
	return dp[1][size - 1];
}


int main() {

	int dimensions[] = {1, 2, 3, 4};
	int size = 4;

	cout<<"Result is "<<findMinimumMulti(dimensions, size)<<endl;

	return 0;

}
