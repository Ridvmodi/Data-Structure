#include<iostream>
#include<string.h>
using namespace std;

int min(int a, int b) {return a < b ? a : b;}

int findWays(int *coins, int size, int change) {

	int ways = 0;
	int dp[size][change + 1];
	memset(dp, 0, sizeof(dp));

	for(int i = 0;i<size;i++) dp[i][0] = 0;

	for(int i = 0;i<size;i++) {
	
		for(int j = 0;j<=change;j++) {
			
			if(j >= coins[i]) {
				dp[i][j] = min(dp[i-1][j], 1 + 	dp[i-1][j-coins[i]]);
			} else {
				dp[i][j] = dp[i-1][j];
			}	
		}
	}

	for(int i = 0;i<size;i++) {

		for(int j = 0;j<=change;j++) {
			cout<<dp[i][j]<<" ";
		}
		cout<<endl;
	}

	return dp[size - 1][change];
}


int main() {

	int coins[] = {2, 5, 3, 6};
	int size = 4, change = 10;
	
	cout<<findWays(coins, size, change)<<endl;

}
