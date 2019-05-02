#include <stdio.h>
#include <math.h>

int main(void)
{
	double i;
	
	for(i = 0.0; i != 10.0; i += 0.1)
	    printf("%lf\n", i); //浮点数类型专有的off-by-one错误，float类型更明显 
	
	return 0;
} 

