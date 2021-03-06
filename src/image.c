#include <stdlib.h>
#include <stdio.h>

#include "image.h"
#include "memory.h"

int read_image(const char *path) {
  FILE* file = fopen(path, "rb");
  if (!file) { return 0; };
  read_image_file(file);
  fclose(file);
  return 1;
}

uint16_t swap16(uint16_t instr) {
  return (instr << 8) | (instr >> 8);
}

void read_image_file(FILE* file)
{
  /* the origin tells us where in memory to place the image */
  uint16_t origin;
  fread(&origin, sizeof(origin), 1, file);
  origin = swap16(origin);

  /* we know the maximum file size so we only need one fread */
  uint16_t max_read = MEMORY_MAX - origin;
  uint16_t* p = memory + origin;
  size_t read = fread(p, sizeof(uint16_t), max_read, file);

  /* swap to little endian */
  while (read-- > 0)
  {
    *p = swap16(*p);
    ++p;
  }
}
