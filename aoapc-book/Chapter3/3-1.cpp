#include<stdio.h>
#include<string.h>

//����һ��OX��ɵĴ�������Ϊ1-80��ͳ�Ƶ÷֣�ÿ��0�ĵ÷��Ե�ǰO���ֵĴ����� X�ĵ÷�Ϊ0
//Example��input��OOXXOXXOOO output��10 

int main(void)
{
	char str[81];
	int n, count = 0, score = 0;
	
	scanf("%s", &str);
	n = strlen(str);
	
	for(int i = 0; i < n; i++)
	{
		if(str[i] == 'O')
		{
			count++;  //count��Ϊһ�������壬��¼ÿ�εķ��� 
		}
		if(str[i] == 'X' || i == n-1)
		{
			score += count * (count + 1) / 2;  
			count = 0;
		}
		//printf("%d\n",score);
	}
	
	printf("Final Score is %d", score);
	
    return 0;
} 
