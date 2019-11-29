#include<iostream>
using namespace std;

int max(int a, int b) { return a > b ? a : b; }

int findMaxProfit(int *prices, int size) {

	int dp[size + 1];
	dp[0] = 0;

	for(int i = 1;i<=size;i++) {
		int maxProfit = -32768;
		for(int j = 0;j<i;j++) {
			maxProfit = max(maxProfit, prices[j] + dp[i-j-1]);	
		}
		dp[i] = maxProfit;
	}

	return dp[size];

}


int main() {

	int prices[] = {1, 5, 8, 9, 10, 17, 17, 20};
	int size = 8;
	
	cout<<findMaxProfit(prices, size)<<endl;
	
	return 0;
}
