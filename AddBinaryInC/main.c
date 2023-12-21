#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int mini(int a, int b)
{
	return a <= b ? a : b;
}

int maxi(int a, int b)
{
	return a >= b ? a : b;
}

char* addBinary(char* a, char* b)
{
	int allocSize = maxi(strlen(a), strlen(b)) + 2;
	int count = allocSize - 1;
	int i = strlen(a) - 1;
	int j = strlen(b) - 1;
	int longer = maxi(i, j);
	int shorter = mini(i, j);

	bool overflow = false;

	char* result = (char*) malloc(sizeof(char) * allocSize);
	result[count] = '\0';
	count--;

	while (shorter >= 0)
	{
		if (a[i] == '0' && b[j] == '0')
		{
			if (!overflow)
			{
				result[count] = '0';
			}
			else
			{
				result[count] = '1';
				overflow = false;
			}
		}
		else if (a[i] == '0' && b[j] == '1' || a[i] == '1' && b[j] == '0')
		{
			if (!overflow)
			{
				result[count] = '1';
			}
			else
			{
				result[count] = '0';
			}
		}
		else if(a[i] == '1' && b[j] == '1')
		{
			if (!overflow)
			{
				result[count] = '0';
				overflow = true;
			}
			else
			{
				result[count] = '1';
			}
		}

		shorter--;
		longer--;
		i--;
		j--;
		count--;
	}

	char* remaining = i >= j ? a : b;

	while (longer >= 0)
	{
		if (remaining[longer] == '0')
		{
			if (!overflow)
			{
				result[count] = '0';
			}
			else
			{
				result[count] = '1';
				overflow = false;
			}
		}
		else if (remaining[longer] == '1')
		{
			if (!overflow)
			{
				result[count] = '1';
			}
			else
			{
				result[count] = '0';
			}
		}
		longer--;
		count--;
	}

	if (overflow)
	{
		result[count] = '1';
	}
	else
	{
		char* shortenedResult = (char*) malloc(sizeof(char) * allocSize - 1);
		for (int iter = 0; iter < allocSize - 1; iter++)
		{
			shortenedResult[iter] = result[iter + 1];
		}
		char* temp = result;
		free(temp);
		result = shortenedResult;
	}

	return result;
}

int main(void)
{
	char* liczba1 = "1010";
	char* liczba2 = "1011";

	printf("%s", addBinary(liczba1, liczba2));

	return 0;
}