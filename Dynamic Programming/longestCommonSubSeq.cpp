#include<iostream>
#include<string.h>
using namespace std;

int mem[100][100];

int max(int a, int b) {
	return a > b ? a : b;
}

int findLongestComSubSeq(char *str1, char *str2, int i, int j) {

	if(str1[i] == '\0' || str2[j] == '\0')
		return 0;
	else if(str1[i] == str2[j])
		return 1 + findLongestComSubSeq(str1, str2, i + 1, j+1);
	else
		return max(findLongestComSubSeq(str1, str2, i+1, j)
			, findLongestComSubSeq(str1, str2, i, j+1));
}

int findLongestComSubSeqByMem(char *str1, char *str2, int i, int j) {

	if(i == 0 || j == 0)
		return  0;
	if(mem[i - 1][j - 1] != -1)
		return mem[i - 1][j - 1];
	else if(str1[i - 1] == str2[j - 1]) {
		mem[i - 1][j - 1] = 1 + findLongestComSubSeqByMem(str1, str2, i - 1, j - 1);
		return mem[i - 1][j - 1];
	}
	else
		return mem[i - 1][j - 1] = max(findLongestComSubSeqByMem(str1, str2, i - 1, j)
			, findLongestComSubSeqByMem(str1, str2, i, j - 1));
}

int findLongestComSubSeqByDp(char *str1, char *str2, int i, int j) {

	int len1 = strlen(str1), len2 = strlen(str2);
	int dp[len1 + 1][len2 + 1];

	for(int i = 0;i<=len1;i++) {
		for(int j = 0;j<=len2;j++) {

			if(i == 0 || j == 0)
				dp[i][j] = 0;
			else if(str1[i] == str2[j])
				dp[i][j] = 1 + dp[i-1][j-1];
			else 
				dp[i][j] = max(dp[i-1][j], dp[i][j-1]);

		}
	}
	
	return dp[len1][len2];
}


int main() {

	char str1[] = "ahbdlop";
	char str2[] = "acgbdp";

	cout<<findLongestComSubSeq(str1, str2, 0, 0)<<endl;
	memset(mem, -1, sizeof(mem));
	cout<<findLongestComSubSeqByMem(str1, str2, 7, 6)<<endl;
	cout<<findLongestComSubSeqByDp(str1, str2, 0, 0)<<endl;

}
