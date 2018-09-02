#include "cotp.h"
#include "otp.h"

#include <openssl/evp.h>
#include <openssl/hmac.h>
#include <string.h>

static OTPData* tdata = NULL;


// byte_secret is unbase32 key
// byte_string is data to be HMAC'd
int hmac_algo_sha1(const char byte_secret[], const char byte_string[], char out[]) {

	// Output len
	unsigned int len = SHA1_BYTES;

	// Return the HMAC success
	return HMAC(
			EVP_sha1(),									// algorithm
			(unsigned char*)byte_secret, 10,			// key
			(unsigned char*)byte_string, 8,				// data
			(unsigned char*)out, &len) == 0 ? 0 : 1;	// output
}

int Otp_New() {
  if (tdata != NULL) {
    Otp_Dispose();
  }

  tdata = totp_new(
      BASE32_SECRET,
      SHA1_BITS,
      hmac_algo_sha1,
      SHA1_DIGEST,
      DIGITS,
      INTERVAL);

  if (tdata == NULL) {
    printf("ERROR: tdata is set to NULL\n");
    return 1;
  }

  return 0;
}

int Otp_Check(char* Secret) {
  char* tcode = NULL;
  int Response = FALSE;

  if (Secret == NULL || tdata == NULL) {
    printf("ERROR: Invalid parameters Secret %x tdata %x\n", Secret, tdata);
    return Response;
  }

	tcode = calloc(DIGITS+1, sizeof(char));
  if (tcode == NULL) {
    printf("ERROR: Could not allocate memory for tcode!\n");
    return Response;
  }

	int totp_err_1 = totp_now(tdata, tcode);
	if(totp_err_1 == 0) {
		puts("TOTP Error 1");
		return Response;
	}

  if (strcmp(Secret, tcode) == 0) {
    Response = TRUE;
  }

  if (tcode != NULL) {
    free(tcode);
  }
  return Response;
}

void Otp_Dispose() {
  if (tdata != NULL) {
    otp_free(tdata);
    tdata = NULL;
  }
}
