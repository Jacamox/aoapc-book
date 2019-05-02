#include <stdio.h>
#include <math.h>

int main(void)
{

    FILE *fin, *fout;
    fin = fopen("input.txt", "r");
    fout = fopen("output.txt", "w");
    
	int num, count = 0, a, b, c, i = 1;
	
	while(fscanf(fin,"%d%d%d",&a,&b,&c) != EOF)
    {	
    	for(num = 10; num < 100; num++)
		{
			if(num % 3 == a && num % 5 == b && num % 7 == c)
			{
				fprintf(fout, "Case %d: %d\n", i, num);
				count++; 
				i++;
				break;
			}
		} 
			
		if(count == 0)
		{
			fprintf(fout, "Case %d: No answer\n", i);
			i++;
		}
		
		count = 0;
    
    }
        
	fclose(fin);
	fclose(fout);
	
	return 0;
}
