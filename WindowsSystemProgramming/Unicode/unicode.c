#include <stdio.h>
#include <string.h>

int main() {
	char str1[] = "Hello!! 테스트";
	wchar_t str2[] = L"Hello!! 테스트";

	int str1_size = sizeof(str1);
	int str1_len = strlen(str1);

	int str2_size = sizeof(str2);
	int str2_len = wcslen(str2);

	printf("str1_size : %d\nstr1_len : %d\n",str1_size,str1_len);
	wprintf(L"str2_size : %d\nstr2_len : %d\n",str2_size,str2_len);

}