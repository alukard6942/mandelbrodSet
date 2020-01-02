#include <stdio.h>
#include <stdlib.h>

#define STEPS 50
#define IRITATION 500
// mandlebrod set


int main (int argc, char**argv)
{
	double rc = atof(argv[1]);
	double ic = atof(argv[2]);
	double step = 1/atof(argv[3]);
	int steps = STEPS;
	if (argc > 5) steps = atoi(argv[5]);
	double zoom = step * steps;
	long iritacion = IRITATION;
	if(argc > 4) iritacion = atoi(argv[4]);

	while (1)
	{
		printf("%g + %gi zoom: %gx iritacions: %li %i\n",rc,ic, step, iritacion,argc);

		// rerender
		for (double i = ic + zoom/2; i > ic -zoom/2; i -= step)
		{	
			for (double r = rc - zoom; r < rc +zoom; r+= step )
			{
				double a = 0; double b = 0;
				int draw = 1;
				int n;
				for (n = 0; n < iritacion; n++)
				{
					double aa = a * a - b * b;
					double bb = 2 * a * b;
					a = aa +r;
					b = bb +i;
					if (a*a +b*b > 4 )
					{
						draw = 0; 
						break;
					}
				}
				//printf("\033[%im",(int)n/50);
				printf(draw ? "**" : "  ");
				//printf("\033[0m");
			}
			printf("\n");
		}
		if (argc <= 6) return 1;

		zoom /= 3;
		char c;
		system("/bin/stty raw");
		c = getchar();
		system("/bin/stty cooked");
		
		switch(c)
		{
			case '0':
				step *= 1.5;
				break;
			case '1':
				rc -= zoom;
				ic -= zoom;
				break;
			case '2':
				ic -= zoom;
				break;
			case '3':
				rc += zoom;
				ic -= zoom;
				break;
			case '4':
				rc -= zoom;
				break;
			case '5':
				step *= 0.8;
				break;
			case '6':
				rc += zoom;
				break;
			case '7':
				rc -= zoom;
				ic += zoom;
				break;
			case '8':
				ic += zoom;
				break;
			case '9':
				rc += zoom;
				ic += zoom;
				break;
			case '+':
				iritacion *= 2;
				break;
			case '-':
				iritacion /= 2;
				break;
			case 'q':
				return 1;
			default:
				step *= 0.3;
				break;

		}
		zoom = step *  steps;
	}
	


}