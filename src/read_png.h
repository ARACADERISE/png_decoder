#ifndef R_PNG
#define R_PNG
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const static int BEGINNING[4] = { 0x89, 0x50, 0x4e, 0x47 };

typedef struct ReadPng
{
  char *filename;

  size_t size;
  char *info;
  char *pixel_array;
} ReadPng_;

ReadPng_ *init_reader(char *filename);
ReadPng_ *decode(ReadPng_* rpng);

#endif