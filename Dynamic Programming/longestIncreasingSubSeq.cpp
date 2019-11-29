#include<iostream>
#include<string.h>
using namespace std;

int max(int a, int b) { return a > b ? a : b; }

int maxAmongArr(int *arr, int size) {
	int maxNo = -32768;
	for(int i = 0;i<size;i++) {
		maxNo = maxNo < arr[i] ? arr[i] : maxNo;
	}
	return maxNo;
}

int main() {

	int arr[] = {3, 10, 2, 1, 20};
	int size = 5;

	int countArr[size];

	for(int i = 0;i<size;i++) countArr[i] = 1;

	for(int i = 1;i<size;i++) {
		for(int j = 0;j<i;j++) {
			if(arr[i] > arr[j]) {
				countArr[i] = max(countArr[j] + 1, countArr[i]);
			}
		}
	}

	cout<<maxAmongArr(countArr, size)<<endl;

}
