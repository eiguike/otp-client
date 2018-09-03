#include <stdio.h>
#include <stdlib.h>

int Clipboard_CopyToBuffer (char* String) {
  int Status = 0;
  char Buffer[100] = { 0 };

  if (String == NULL) {
    printf("ERROR: Parameter String is set to NULL\n");
    Status = 1;
    goto FINISH;
  }

  sprintf(Buffer, "echo \"%s\" | tr -d \'\n\' | pbcopy", String); 
  system(Buffer);

FINISH:
  return Status;
} 
