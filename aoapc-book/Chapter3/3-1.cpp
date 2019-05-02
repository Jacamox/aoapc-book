#include<stdio.h>
#include<string.h>

//给出一个OX组成的串，长度为1-80，统计得分，每个0的得分试当前O出现的次数， X的得分为0
//Example：input：OOXXOXXOOO output：10 

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
			count++;  //count作为一个计数板，记录每次的分数 
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
