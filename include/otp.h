#ifndef OTP_H
#define OTP_H

#include <stdio.h>

#define TRUE 1
#define FALSE 0

#define INTERVAL 30
#define DIGITS 6
#define BASE32_SECRET "YOUNEEDTOCHANGETHIS"

int Otp_New ();
int Otp_Check (char* Secret);
void Otp_Dispose ();
void Otp_Print ();

#endif

