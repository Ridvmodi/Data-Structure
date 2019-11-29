#include<iostream>
using namespace std;

int printNoOfWays(int *steps, int size, int distance) {

	int dp[distance + 1] = {0};

	dp[0] = 1;

	for(int i = 0;i<size;i++) {
		for(int j = steps[i];j<=distance;j++) {
		
			dp[j] += dp[j-steps[i]];
		}
	}

	return dp[distance];
}

int main() {

	int steps[] = {3, 5, 10};
	int size = 3, distance = 20;
	
	cout<<printNoOfWays(steps, size, distance)<<endl;

}
