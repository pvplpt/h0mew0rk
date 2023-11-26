#include <stdio.h>

int main(int argc, char **argv)
{

	int n;
	int i;
	printf("Input natural number:\n");
	scanf("%d", &n);
	if (n > 0)
	{
		printf("%d => {1, ", n);
		for (i = 2; i < n; i++)
		{
			if (n % i == 0)
			{
				printf("%d, ", i);
			}
		}
		printf("%d}\n", n);
	}
	else
	{
		printf("This is not a natural number.\n");
	}
	getchar();
	return 0;
}
