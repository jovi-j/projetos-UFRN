#include <stdio.h>

int main(int argc, char const *argv[]){
	int width,height,threshold;
	scanf("%d %d %d", &width, &height, &threshold);
	int image[width][height];
	for (int i = 0; i < width; i++)
	{
		for (int j = 0; j < height; j++)
		{
			int value = 0;
			scanf("%d", &value);
			if(value >= threshold){
				image[i][j] = 1;
			}else{
				image[i][j] = 0;
			}
		}
	}

	for (int i = 0; i < width; i++)
	{
		for (int j = 0; j < height; j++)
		{
			printf("%d ", image[i][j]);
		}
		printf("\n");
	}
	
	return 0;
}
