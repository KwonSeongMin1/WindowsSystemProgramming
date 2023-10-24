#include <stdio.h>
int main() {
	int arr[10] = { 0, };
	int arrVal = (int)arr;	// 데이터 손실
	printf("pointer : %d\n", arrVal);
	return 0;
}
