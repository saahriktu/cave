/* Cave v0.3
 * Cave with corridors, ninjas and one exit game.
 * Author: Kurashov Artem
 * License: GNU GPLv3
 */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

static int
get_random (int g_rand_max)
{
  return (int) ((g_rand_max + 1.0) * rand () / (RAND_MAX + 1.0));
}

int main ()
{
  int i, j, sr, fr, h = 3, cr[5][9];
  srand (time (0));
  for (i = 0; i < 5; i++)
    for (j = 0; j < 9; j++)
      cr[i][j] = get_random (8);
  sr = get_random (8);
  while ((fr = get_random (8)) == sr);
  for (;;)
    {
      printf ("current room #%d, health: %d\n", sr, h);
      if (sr == fr)
	{
	  printf ("U found exit! Congratulation! The end.\n");
	  return 0;
	}
      if (cr[0][sr] < 3)
	{
	  printf ("U attacked by ninja!...\n");
	  if (--h == 0)
	    {
	      printf ("U die... Game Over...\n");
	      return 0;
	    }
	}
      printf ("%d corridors here. choose one (1-%d):", 1 + cr[4][sr] / 3,
	      1 + cr[4][sr] / 3);
      do
	{
	  scanf ("%1d", &i);
	  getchar();
	}
      while (i < 1 || i > 1 + cr[4][sr] / 3);
      sr = cr[i][sr];
    }
}
