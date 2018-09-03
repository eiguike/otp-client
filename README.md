# otp-client
---

the purpose of this application is just to retrieve a time-based one-time password (TOTP) through a command line and save it to clipboard's buffer.

---
### Requirements:
- cmake;
- OpenSSL;
- Mac OSX;
---
### Building:
1. Build with cmake passing your secret key
```
$ cmake .. -DSECRET=\"YOURSECRETKEY\"
```
2. Compile using make
```
$ make
```
3. Execute `otp-client`
```
$ ./otp-client
```
4. Paste it!
---
### Credits:
- [COTP library](https://github.com/OTPLibraries/COTP)
