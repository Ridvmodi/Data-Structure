#include<iostream>
using namespace std;

int max(int a, int b) {
	return a < b ? b : a;
}

int knapSack(int prices[], int weights[], int N, int W) {

	if(N == 0 || W == 0)
		return 0;
	int inc = 0, exc = 0;
	if(weights[N-1] <= W) {
		inc = prices[N-1] + knapSack(prices, weights, N-1, W - weights[N-1]);
	}
	exc = knapSack(prices, weights, N-1, W);

	return max(inc, exc);

}

int knapSackByDp(int prices[], int weights[], int N, int W) {

	int dp[N + 1][W + 1] = {0};
	
	for(int i = 0;i<=N;i++) {
	
		for(int w = 0;w<=W;w++) {

			if(w == 0 || i == 0)
				dp[i][w] = 0;
			else if(weights[i-1] <= w) {
				dp[i][w] = max(prices[i-1] + dp[i-1][w - weights[i-1]], 
								dp[i-1][w]);
			} 
			else
				dp[i][w] = dp[i-1][w];

		}

	}
	return dp[N][W];
}


int main() {

	int prices[] = {60, 100, 120};
	int weights[] = {10, 20, 30};
	
	int weight = 50;
	
	cout<<knapSack(prices, weights, 3, weight)<<endl;
	cout<<knapSackByDp(prices, weights, 3, weight)<<endl;


}
