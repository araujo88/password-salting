#ifndef SHA256_H_INCLUDED
#define SHA256_H_INCLUDED

unsigned int _rotl(const unsigned int value, int shift);                                           // rotate bits left
unsigned int _rotr(const unsigned int value, int shift);                                           // rotate bits right
unsigned int concatenate_bits(unsigned int b1, unsigned int b2, unsigned int b3, unsigned int b4); // concatenates 4 bits
void SHA256(char string[], char digest[256]);                                                      // generates SHA-256 digest

#endif // SHA256_H_INCLUDED