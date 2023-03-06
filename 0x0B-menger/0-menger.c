#include "menger.h"
/**
* menger - draws a 2D Menger Sponge
* @level: the level of the Menger Sponge to draw
* Return: None
*/
void menger(int level)
{
	int line, col, level_line, level_col, nb_cases;
	char diese;

	nb_cases = pow(3, level);

	if (level >= 0)
	{
		for (level_line = 0; level_line < nb_cases; level_line++)
		{
			for (level_col = 0; level_col < nb_cases; level_col++)
			{
				diese = '#';
				for (line = level_line, col = level_col; line > 0 || col > 0;
					 line /= 3, col /= 3)
				{
					if (line % 3 == 1 && col % 3 == 1)
					{
						diese = ' ';
						break;
					}
				}
				printf("%c", diese);
			}
			printf("\n");
		}
	}
}
