#include <stdio.h>
#define maxn 100000000000000000

int a[maxn]; //��������棬������ܴ�ʱ 

int main(void)
{
	int x, n = 0;

	
	while(scanf("%d", &x) == 1)
	{
		a[n++] = x;
	}
	for(int i = n-1; i >= 1; i--)
	{
		printf("%d", a[i]);
	}
	printf("%d", a[0]);
	
	return 0;
} 

