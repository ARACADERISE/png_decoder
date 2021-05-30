#include <stdio.h>
#include "src/read_png.h"

int main()
{
  ReadPng_ *v = init_reader("image.png");
  decode(v);
}