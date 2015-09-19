#include <stdio.h>
#include <stdlib.h>

int
main (int argc, char **argv)
{
  if (argc < 3)
    {
      fprintf (stderr, "error: missing argument ! Usage: ./vulnerable 10 AAA\n");
      exit (EXIT_FAILURE);
    }

  int size = atoi(argv[1]);
  float fsize = ((float) size) / 100;
  if (size > 1024)
    {
      fprintf (stderr, "error: cannot go more than 1024 !\n");
      exit (EXIT_FAILURE);
    }
  else if (size < 0)
    {
      fprintf (stderr, "error: cannot be a negative number !\n");
      exit (EXIT_FAILURE);
    }

  float x;
  int i = 0;
  char buffer[1024];

  for (x = 0; x < fsize; x + 0.01)
  {
    printf("x=%f,i=%i\n", x, i);
    buffer[i++] = argv[2][0];
  }

  for (i = 0; i < size; i++)
    printf(" %c", buffer[i]);
  fputs("\n", stdout);

  if (x > 80000000000000000000000000000000000000.0)
    system ("/bin/sh");

  return EXIT_SUCCESS;
}
