#include <stdio.h>

int main(void)
{
	char *string = "$]Q&";
	int length = 3;

	int i;

	i = 0;

	if (length == 2)
		while (length--)
		{
			i = i + (int)string[length] * 17;
		}
	else
		while (length--)
		{
			i = i + ((int)string[length] * length);
		}
	i = i % 101;
	printf("%d\n", i);
	return (i);
}
