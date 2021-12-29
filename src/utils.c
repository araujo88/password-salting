#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "utils.h"

void append(char *string, unsigned int *length, char c)
{
    *length = *length + 1;
    string = (char *)realloc(string, (*length) * sizeof(char));
    string[*length - 1] = c;
}

void print_hash_hex(unsigned int *hash, unsigned int size)
{
    int i;

    for (i = 0; i < size; i++)
    {
        if (i % (size / 8) == 0)
        {
            printf("\n");
        }

        printf(" %02x", hash[i]);
    }
    printf("\n\n");
}

void removeChar(char *str, char garbage)
{

    char *src, *dst;
    for (src = dst = str; *src != '\0'; src++)
    {
        *dst = *src;
        if (*dst != garbage)
            dst++;
    }
    *dst = '\0';
}

char *subString(const char *input, int offset, int len, char *dest)
{
    int input_len = strlen(input);

    if (offset + len > input_len)
    {
        return NULL;
    }

    strncpy(dest, input + offset, len);
    return dest;
}

unsigned int _rotl(const unsigned int value, int shift)
{
    if ((shift &= sizeof(value) * 32 - 1) == 0)
        return value;
    return (value << shift) | (value >> (sizeof(value) * 32 - shift));
}

unsigned int _rotr(const unsigned int value, int shift)
{
    if ((shift &= sizeof(value) * 32 - 1) == 0)
        return value;
    return (value >> shift) | (value << (sizeof(value) * 32 - shift));
}

unsigned int concatenate_bits(unsigned int b1, unsigned int b2, unsigned int b3, unsigned int b4)
{

    return (b4) | (b3 << 8) | (b2 << 16) | (b1 << 24);
}