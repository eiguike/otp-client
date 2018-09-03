#include <stdio.h>
#include <stdlib.h>

#include "otp.h"

int main() {
  Otp_New();
  Otp_Print();
  Otp_Dispose();
  return 0;
}
