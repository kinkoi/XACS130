#include <stdio.h>

void printHexMessage(char *m, int length)
{
  for (size_t i = 0; i < length; i++) {
    printf("%02x", m[i]);
    printf(" ");
  }
  printf("\n");
}

void printMessage(char *m, int length)
{
  for (size_t i = 0; i < length; i++) {
    printf("%c", m[i]);
  }
  printf("\n");

}

void copyString(char *destination, char *source, int length)
{
  for (size_t i = 0; i < length; i++) {
    destination[i] = source[i];
  }
}
