#include <stdio.h>
#include <string.h>
#include "util.h"

#define MESSAGE_LEN 11

int main()
{
  char *key = "secretkey10";
  char *message = "hello world";
  char scramble[MESSAGE_LEN];
  char originalMessage[MESSAGE_LEN];
  char tamperMessage[MESSAGE_LEN];
  char tamperOriginalMessage[MESSAGE_LEN];

  for(int i=0; i<MESSAGE_LEN; i++) {
    scramble[i] = (char) (key[i] ^ message[i]);
  }

  printf("encrypted message :");
  printHexMessage(scramble, MESSAGE_LEN);

  for (int i = 0; i < MESSAGE_LEN; i++) {
    originalMessage[i] = (char) (scramble[i] ^ key[i]);
  }

  printf("decrypted message :");
  printMessage(originalMessage, MESSAGE_LEN);

  char *world = "world";
  char *peter = "peter";
  copyString(tamperMessage, scramble, MESSAGE_LEN);

  int count = 0;
  for (int i = 6; i < MESSAGE_LEN; i++) {
    tamperMessage[i] = (char)(peter[count] ^ world[count] ^ scramble[i]);
    count++;
  }

  for (int i = 0; i < MESSAGE_LEN; i++) {
    tamperOriginalMessage[i] = (char)(tamperMessage[i] ^ key[i]);
  }

  printf("tampered encrypted message :");
  printHexMessage(tamperMessage, MESSAGE_LEN);
  printf("decrypted message :");
  printMessage(tamperOriginalMessage, MESSAGE_LEN);

  return 0;
}
