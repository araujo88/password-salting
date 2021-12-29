#ifndef UTILS_H_INCLUDED
#define UTILS_H_INCLUDED

void removeChar(char *str, char garbage);                                                          // removes char from string
char *subString(const char *input, int offset, int len, char *dest);                               // selects substring from a given string
unsigned int _rotl(const unsigned int value, int shift);                                           // rotate bits left
unsigned int _rotr(const unsigned int value, int shift);                                           // rotate bits right
unsigned int concatenate_bits(unsigned int b1, unsigned int b2, unsigned int b3, unsigned int b4); // concatenate 4 bits

#endif // UTILS_H_INCLUDED