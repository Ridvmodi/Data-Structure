#include<iostream>
#include<string.h>
using namespace std;

int min(int a, int b, int c) {
	int minNo = 0;
	while(a && b && c) {
		a--;
		b--;
		c--;
		minNo++;
	}
	return minNo;
}

int findMinimumOperations(char *str, char *str1) {

	int len = strlen(str), len1 = strlen(str1), maxLen;
	maxLen = len > len1 ? len : len1;
	int dp[len + 1][len1 + 1];

	for(int i = 0;i<=maxLen;i++) {
		if(i <= len1)
			dp[0][i] = i;
		if(i <= len)
			dp[i][0] = i;
	}
	for(int i = 1;i<=len;i++) {
		for(int j = 1;j<=len1;j++) {
			if(str[i - 1] == str1[j - 1]) {
				dp[i][j] = dp[i-1][j-1];
			} else {
				dp[i][j] = min(dp[i-1][j], dp[i-1][j-1], dp[i][j-1]) + 1;
			}
		}
	}
	return dp[len][len1];
}

int main() {

	char str[] = "abcdef";
	char str1[] = "azced";

	cout<<findMinimumOperations(str, str1)<<endl;
	
	return 0;
}
