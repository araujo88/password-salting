#ifndef CSPRNG_H_INCLUDED
#define CSPRNG_H_INCLUDED

void removeChar(char *str, char garbage);                            // removes char from string
char *subString(const char *input, int offset, int len, char *dest); // selects substring from a given string
void CSPRNG(unsigned int size, char salt[size]);                     // generates random string from /dev/urandom

#endif // CSPRNG_H_INCLUDED