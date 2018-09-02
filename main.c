#include <stdio.h>
#include <stdlib.h>

#include "otp.h"


int main() {
  char Input[100] = { 0 };

  scanf("%s", Input);
  Otp_New();
  if (Otp_Check(Input) == 1) {
    printf("Access Granted!\n");
  } else {
    printf("Access Forbidden!\n");
  }

  Otp_Dispose();
  return 0;
}
