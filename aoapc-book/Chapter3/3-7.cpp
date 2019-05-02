#include<stdio.h>
#include<string.h> 
//#define TEST 

int a[1005][4];//记录对应位置出现次数最多的字母 

//DNA序列 
int main(void)
{
	int m, n, max, loc;
	char s;
	
	memset(a, 0, sizeof(a)); //清0 
	scanf("%d %d", &m, &n); //m行n列 
	
	getchar();
	//统计部分 
	for(int i = 0; i < m; i++)
  	{
		for(int j = 0; j < n; j++)
		{
			scanf("%c", &s);
			switch(s) //ACGT
			{
				case 'A':
				{
					a[j][0]++;
					break;
				}
				case 'C':
				{
					a[j][1]++;
					break;
				}
				case 'G':
				{
					a[j][2]++;
					break;
				}
				case 'T':
				{
					a[j][3]++;
					break;
				}
			}
		}
		getchar();
	}

#ifdef TEST
	
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < 4; j++)
		{
			printf("%d", a[i][j]);
		}
		printf("\n");
	}
	
#endif
	
	//输出结果 
	for(int i = 0; i < n; i++)
	{
		loc = 0;
		max = a[i][0];
		for(int j = 0; j < 3; j++)
		{
			if(max < a[i][j+1])
			{
				loc = j+1;
				max = a[i][j+1];
			}
		}
		switch(loc)
		{
			case 0:
			{
				printf("A");
				break;
			}
			case 1:
			{
				printf("C");
				break;
			}
			case 2:
			{
				printf("G");
				break;
			}
			case 3:
			{
				printf("T");
				break;
			}
			
		}
	}
	
	return 0;
}
