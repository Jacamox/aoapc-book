//#define TEST
#include<stdio.h>
#include<string.h>

char s[11][11];
int label[11][11];

int isfirst(int row, int col)
{
	if(s[row][col] != '*' && ((col == 0 || row == 0) || (s[row-1][col] == '*' || s[row][col-1] == '*'))) //判断是否是起始格 
	{
		return 1;
	}
	else
	{
		return 0;
	}
}


int main(void)
{
	int count = 1;
	int row, col;
	int m = 0, n = 0;
	
	scanf("%d %d", &row, &col);
	memset(label, 0, sizeof(label));
	memset(s, 0, sizeof(s));
	getchar();
	 
	for(int i = 0; i < row; i++)
	{
		for(int j = 0; j < col; j++)
		{
			scanf("%c", &s[i][j]);
		}
		getchar();
	}

	
	for(int i = 0; i < row; i++)
	{
		for(int j = 0; j < col; j++)
		{
			if(isfirst(i,j))
			{
				label[i][j] = count;
				count++;
				//用label记录起始格的位置和编号，内容用s存 
			}
		}
	}
	
#ifdef TEST

	printf("S:\n");
	for(int i = 0; i < row; i++)
	{
		for(int j = 0; j < col; j++)
		{
			printf("%c", s[i][j]);
		}
		printf("\n");
	}
	
	printf("LABEL:\n");
	for(int i = 0; i < row; i++)
	{
		for(int j = 0; j < col; j++)
		{
			printf("%c", label[i][j]);
		}
		printf("\n");
	}


#endif
	
	//Across的部分 
	printf("Across:\n");
	while(m < row)
	{
		if(s[m][n] == '*')
		{
			n++;
		}
		printf("%d:", label[m][n]);
		while(n < col)
		{
			if(s[m][n] != '*')
			{
				printf("%c", s[m][n]);
			}
			if(s[m][n] == '*')
			{
				printf("\n");
				if(n != col-1)
				{
					printf("%d:", label[m][n+1]);
				}
			}
			n++;
		}
		if(s[m][n-1] != '*')
		{
			printf("\n");
		} 
		while(n == col)
		{
			n = 0;
		} 
		
		m++;
	}
	//Down的部分 
	
	
	
} 
