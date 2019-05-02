#include <stdio.h>
#include <math.h>

int main(void)
{
	int j = 1;
	float sum = 0, n, m;
	
	while(scanf("%f%f", &n, &m) != EOF)
	{
		if(n == m && m == 0)
		{
			break;
		}
		
		for(float i = n; i <= m; i++)
		{
			sum += 1 /i /i;
		}
		
		printf("Case %d: %.5f\n", j, sum);
		j++;
	}
} 
