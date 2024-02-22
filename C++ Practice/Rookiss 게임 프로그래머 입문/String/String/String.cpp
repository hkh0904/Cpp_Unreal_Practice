#include <iostream>
using namespace std;

// [Hello0........]
int StrLen(const char* str)
{
	int count = 0;

	while (str[count] != 0)
		count++;

	return count;
}

char* StrCpy(char* dest, char* src)
{
	char* ret = dest;

	/*int i = 0;

	while (src[i] != 0)
	{
		dest[i] = src[i];
		i++;
	}

	dest[i] = 0;*/

	// pointer를 이용한 복사
	while (*src != 0)
	{
		*dest = *src;
		dest++;
		src++;
	}

	*dest = 0;

	return ret;
}

char* StrCat(char* dest, char* src)
{
	/*char* ret = dest;
	while (true)
	{
		if (*dest != 0)
		{
			dest++;
			continue;
		}
		else
		{
			while (*src != 0)
			{
				*dest = *src;
				dest++;
				src++;
			}
			*dest = 0;
			return ret;
		}
	}*/

	char* ret = dest;

	int len = StrLen(dest);
	int i = 0;

	while (src[i] != 0)
	{
		dest[len + i] = src[i];
		i++;
	}

	dest[len + i] = 0;

	return ret;
}

int main() {
	
	const int BUF_SIZE = 100;

	char a[BUF_SIZE] = "Hello";
	char b[BUF_SIZE] = "World";

	int len = strlen(a);
	cout << len << endl;

#pragma warning(disable:4996)
	char c[BUF_SIZE];
	strcpy(c, a);
	cout << c << endl;

	// cout << strcat(a, b) << endl;


	cout << StrCat(a, b) << endl;
}