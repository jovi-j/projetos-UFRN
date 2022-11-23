#include <stdio.h>

int main(int argc, char const *argv[])
{
	int w,h, factors[4] = {0,0,0,0};
	// Land, Forest, Desert, Water
	scanf("%d %d", &w,&h);
	double totalArea = w * h;
	getchar();
	for(int i = 0; i <= w; i++)
	{
		for (int j = 0; j <= h; j++)
		{
			char c;
			scanf("%c", &c);
			if(c == 'X'){
				printf("Planeta Hostil\n");
				return 0;
			}
			switch (c){
			case '~':
				factors[3]++;
				break;
			case '^':
				factors[2]++;
				break;
			case '*':
				factors[1]++;
				break;
			case '.':
				factors[0]++;
				break;
			default:
				break;
			}
		}		
	}
	if (factors[3] >= totalArea * 0.85){
		printf("Planeta Aquático\n");
	}
	else if (factors[2] >= totalArea * 0.60){
		printf("Planeta Desértico\n");
	}
	else if (factors[1] >= totalArea * 0.65){
		printf("Planeta Selvagem\n");
	}
	else if (factors[3] >= totalArea * 0.50 
			&& factors[1] >= totalArea * 0.20){
		printf("Planeta Classe M\n");
	}else{
		printf("Planeta Inóspito\n");
	}
	return 0;
}