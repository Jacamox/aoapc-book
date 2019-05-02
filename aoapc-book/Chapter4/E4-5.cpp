#include<stdio.h>
#include<string.h>
//#define TEST

//有问题，考虑没仔细，只能从后面的列数往前删，没考虑到列数删了别的列会移动
//懒得改了，思路是做个标记，大于该标记的就-1或者+1进行移动， 


int r, c;
int s[100][55], s2[100][55];  //内容r行c列 c<50 r>1

void printcode()
{
	for(int i = 0; i < r; i++)  //i j 比真实行列数小1 
	{
		for(int j = 0; j < c; j++)
		{
			printf("%d ", s[i][j]);
		}
		printf("\n");
	}
}

void del(char type, int a)//删除第a行 
{
	if(type == 'R')
	{
		for(int i = a; i < r; i++)//一行一行移,第a行下面的都要移动 
		{
			for(int j = 0; j < c; j++)
			{
				s[i][j] = s[i+1][j]; //每个都往上移一行 
			}
		}
	}
		
	if(type == 'C') 
	{
		for(int i = a; i < c; i++) //一列一列移,第a列后面的都要移动 
		{
			for(int j = 0; j < r; j++)
			{
				s[j][i] = s[j][i+1]; //每个都往前移一列 
			}
		}
	}
}

void ins(char type, int a)//在第a行后插入一行 
{
	if(type == 'R')
	{
		for(int i = r-1; i > a; i--)//一行一行移,第a行下面的都要移动 
		{
			for(int j = 0; j < c; j++)
			{
				s[i+1][j] = s[i][j]; //每个都往下移一行 
			}
		}
		memset(*(s+a-1),'\0',sizeof(int)*(c-1));//清空第a行 
	}
		
	if(type == 'C') 
	{
		for(int i = c-1; i > a; i--) //一列一列移,第a列后面的都要移动 
		{
			for(int j = 0; j < r; j++)
			{
				s[j][i+1] = s[j][i]; //每个都往后移一列 
				memset(*(s+j)+a,'\0',sizeof(int)); //清空每行的第a+1个 
			}
		}
	}
}

void ex(int r1, int r2, int c1, int c2)
{
	int temp;
	temp = s[r1][c1];
	s[r1][c1] = s[r2][c2];
	s[r2][c2] = temp;
}

int main(void)
{
	
	int r1, r2, c1, c2, q, t;
	char com1, com2, tem;
	
	memset(s, 0, sizeof(s));
	scanf("%d %d", &r, &c);
	
	//读取数据部分 
	getchar();
	for(int i = 0; i < r; i++)  //i j 比真实行列数小1 
	{
		for(int j = 0; j < c; j++)
		{
			scanf("%d", &s[i][j]);
		}
		getchar();
	}
	//getchar();
	
#ifdef TEST

	printf("code is:\n");
	printcode();

#endif
	
	//读取请求部分，进行操作 
	while((tem = getchar()) != '0')
	{
		scanf("%c", &com1);
		scanf("%c", &com2);
		printf("%c %c\n", com1, com2);
		if(com1 == 'D')
		{
			scanf("%d", &t);//次数 
			for(int i = 0; i < t; i++)
			{
				scanf("%d", &q);
				del(com2, q-1);
			}
			//printf("%d\n", t);
			getchar();
			printcode();
		}
		else if(com1 == 'I')
		{
			scanf("%d", &t);
			for(int i = 0; i < t; i++)
			{
				scanf("%d", &q);
				ins(com2, q-1);
			}
			//printf("%d\n", t);
			getchar();
			printcode();
		}
		else if(com1 == 'E')
		{
			getchar();//把X读了 
			scanf("%d %d %d %d", &r1, &r2, &c1, &c2);
			ex(r1, r2, c1, c2);
		}
		else if(com1 == 'P')
		{
			printcode();
		}
		getchar();
	}
	
	
	return 0;
} 
