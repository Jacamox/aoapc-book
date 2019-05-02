#include<stdio.h>
#include<string.h>
//#define TEST

//�����⣬����û��ϸ��ֻ�ܴӺ����������ǰɾ��û���ǵ�����ɾ�˱���л��ƶ�
//���ø��ˣ�˼·��������ǣ����ڸñ�ǵľ�-1����+1�����ƶ��� 


int r, c;
int s[100][55], s2[100][55];  //����r��c�� c<50 r>1

void printcode()
{
	for(int i = 0; i < r; i++)  //i j ����ʵ������С1 
	{
		for(int j = 0; j < c; j++)
		{
			printf("%d ", s[i][j]);
		}
		printf("\n");
	}
}

void del(char type, int a)//ɾ����a�� 
{
	if(type == 'R')
	{
		for(int i = a; i < r; i++)//һ��һ����,��a������Ķ�Ҫ�ƶ� 
		{
			for(int j = 0; j < c; j++)
			{
				s[i][j] = s[i+1][j]; //ÿ����������һ�� 
			}
		}
	}
		
	if(type == 'C') 
	{
		for(int i = a; i < c; i++) //һ��һ����,��a�к���Ķ�Ҫ�ƶ� 
		{
			for(int j = 0; j < r; j++)
			{
				s[j][i] = s[j][i+1]; //ÿ������ǰ��һ�� 
			}
		}
	}
}

void ins(char type, int a)//�ڵ�a�к����һ�� 
{
	if(type == 'R')
	{
		for(int i = r-1; i > a; i--)//һ��һ����,��a������Ķ�Ҫ�ƶ� 
		{
			for(int j = 0; j < c; j++)
			{
				s[i+1][j] = s[i][j]; //ÿ����������һ�� 
			}
		}
		memset(*(s+a-1),'\0',sizeof(int)*(c-1));//��յ�a�� 
	}
		
	if(type == 'C') 
	{
		for(int i = c-1; i > a; i--) //һ��һ����,��a�к���Ķ�Ҫ�ƶ� 
		{
			for(int j = 0; j < r; j++)
			{
				s[j][i+1] = s[j][i]; //ÿ����������һ�� 
				memset(*(s+j)+a,'\0',sizeof(int)); //���ÿ�еĵ�a+1�� 
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
	
	//��ȡ���ݲ��� 
	getchar();
	for(int i = 0; i < r; i++)  //i j ����ʵ������С1 
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
	
	//��ȡ���󲿷֣����в��� 
	while((tem = getchar()) != '0')
	{
		scanf("%c", &com1);
		scanf("%c", &com2);
		printf("%c %c\n", com1, com2);
		if(com1 == 'D')
		{
			scanf("%d", &t);//���� 
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
			getchar();//��X���� 
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
