#include<iostream>
#include<string.h>
using namespace std;

int max(int *arr, int size) {

	int maxNo = -32768;
	for(int i = 0;i<size;i++) {
		maxNo = maxNo < arr[i] ? arr[i] : maxNo;
	}
	return maxNo;
}


void findNoOfSubsets(int *elements, int size, int sum) {

	int dp[size + 1][sum + 1];
	memset(dp, 0, sizeof(dp));

	for (int i = 0; i <= size; i++) {
            dp[i][0] = 1;
        }

	for(int i = 1;i<=size;i++) {	
		for(int j = 1;j<=sum;j++) {
			if(j - elements[i - 1] >= 0)
				dp[i][j] = dp[i-1][j] || dp[i-1][j - elements[i - 1]];
			else
				dp[i][j] = dp[i - 1][j];
		}
	}
	int j = sum;
	for(int i = size;i>=1;i--) {
		if(dp[i][j] != dp[i-1][j]) {
			cout<<elements[i - 1]<<" ";
			j -= elements[i - 1];
		}
	}
}


int main() {

	int elements[] = {2, 3, 7, 8, 10}; 
	int size = sizeof(elements) / sizeof(elements[0]);

	findNoOfSubsets(elements, size, 11);	

}
