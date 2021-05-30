#include "read_png.h"

ReadPng_ *init_reader(char *filename)
{
  ReadPng_ *rpng = calloc(1, sizeof(*rpng));

  FILE* file = fopen(filename, "rb");

  if(file)
  {
    fseek(file, 1, SEEK_END);
    rpng->size = ftell(file);
    fseek(file, 0, SEEK_SET);

    rpng->info = calloc(rpng->size, sizeof(*rpng->info));
    fread(rpng->info, 1, rpng->size, file);

    fclose(file);

    return rpng;
  }

  fprintf(stderr, "No such file.");
  exit(EXIT_FAILURE);
}

ReadPng_ *decode(ReadPng_* rpng)
{
  
  // Get the beginning of the file.
  unsigned int beginning[4];
  for(int i = 0; i < 4; i++)
  {
    beginning[i] = rpng->info[i];
  }

  if(beginning[0] == -119)
  {

    // Check the rest of the bytes in the array beginning.
    char *rest = calloc(3, sizeof(*rest));
    for(int i = 1; i < 4; i++)
    {
      rest[i - 1] = rpng->info[i];
    }

    if(strcmp(rest, "PNG") == 0)
    {
      printf("Here");
    }

    return rpng;
  }

  fprintf(stderr, "Invalid start to file %s", rpng->filename);
  exit(EXIT_FAILURE);
}