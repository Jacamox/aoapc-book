#include <stdio.h>
#define maxn 1010 

int main(void)
{
	int a[maxn], b[maxn], n;
	int kase = 1;
	
	while(scanf("%d", &n) == 1 && n)
	{
		printf("Game %d: \n", kase++);
		for(int i = 0; i < n; i++)
		{
			scanf("%d", &a[i]);
		}
		while(1) //while(1)����for(;;)�ƺ�Ҳ�� 
		{
			int A = 0, B = 0;
			
			for(int i = 0; i < n; i++)
			{
				scanf("%d", &b[i]);
				if(a[i] == b[i])
				{
					A++;
				}
			}
			
		if(b[0] == 0)
		{
			break; //��ȡֹͣ��ָ������������������for(;;)����ѭ�� 
		}
		
		for(int i = 1; i <= 9; i++)
		{
			int c1 = 0, c2 = 0;
			
			for(int j = 0; j < n; j++)
			{
				if(a[j] == i)
				{
					c1++;
				}
				if(b[j] == i)
				{
					c2++;
				}
			}
			
			if(c1 < c2)
			{
				B += c1;
			}
			else
			{
				B += c2;
			}
		}
		
		printf("    (%d,%d)\n", A, B-A);
		}
		
	}
	
	return 0;
} 
