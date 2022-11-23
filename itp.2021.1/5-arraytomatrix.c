#include <stdio.h>

int main(int argc, char const *argv[]){
	int sizeArray;
	scanf("%d", &sizeArray);
	int array[sizeArray];
	for (int i = 0; i < sizeArray; i++){
		scanf("%d", &array[i]);
	}
	int lines, columns, inc = 0;
	scanf("%d %d", &lines, &columns);
	int matrix[lines][columns];
		
	for (int i = 0; i < lines; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			matrix[i][j] = array[inc];
			inc++;
		}
		
	}
	
	int selectedLine,selectedColumn;	
	scanf("%d %d", &selectedLine, &selectedColumn);
	
	printf("%d\n", matrix[selectedLine][selectedColumn]);
	return 0;
}