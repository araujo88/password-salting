#ifndef CSPRNG_H_INCLUDED
#define CSPRNG_H_INCLUDED

#define BUFFER_SIZE 2048

void CSPRNG(unsigned int size, char salt[size]); // generates random string from /dev/urandom

#endif // CSPRNG_H_INCLUDED