#include <stdio.h>
#include <math.h>

int main(void)
{
	double i;
	
	for(i = 0.0; i != 10.0; i += 0.1)
	    printf("%lf\n", i); //����������ר�е�off-by-one����float���͸����� 
	
	return 0;
} 

