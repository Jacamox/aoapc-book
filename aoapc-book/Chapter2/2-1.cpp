#include <stdio.h>
#include <math.h>

int main(void)
{
	int i;
	for(i=100; i<1000; i++)
	{
		int a,b,c;
		c = i % 10;
		b = ((i - a) % 100) / 10;
		a = (i - b * 10 - a) / 100;
		if(i == (pow(a,3) + pow(b,3) + pow(c,3)))
		{
			printf("%d\n", i);
		}
	}
	return 0;
}
