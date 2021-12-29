#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "CSPRNG.h"
#include "SHA256.h"

int main(int argc, char *argv[])
{
    if (argc != 4)
    {
        printf("Not enough arguments provided. Usage: %s <password> <work factor> <salt_size>\n", argv[0]);
        exit(1);
    }
    if (atoi(argv[3]) > 32)
    {
        printf("Maximum salt size is limited to 32 bytes.\n");
        exit(1);
    }

    unsigned int work_factor;
    unsigned long int iterations;
    unsigned int salt_size = atoi(argv[3]);
    char password[strlen(argv[1])];
    char *salt = (char *)malloc(atoi(argv[3]));
    char digest[SIZE];
    unsigned int i;

    strncpy(password, argv[1], strlen(argv[1]));
    password[strlen(argv[1])] = '\0';
    printf("Password: %s\n", password);

    work_factor = atoi(argv[2]);
    printf("Work factor: %u\n", work_factor);

    iterations = (unsigned long int)pow(2, work_factor);
    printf("Number of iterations: %lu\n", iterations);

    printf("Salt length: %u\n", salt_size);

    CSPRNG(salt_size, salt);
    printf("Generated salt: %s\n", salt);

    char salted_password[SIZE];
    sprintf(salted_password, "%s%s", password, salt);
    printf("Salted password: %s\n", salted_password);

    for (i = 0; i < iterations; i++)
    {
        SHA256(salted_password, digest);
        // printf("Hashed salted password: %s - iteration %u\n", digest, i);
        if (i != iterations - 1)
        {
            memcpy(salted_password, digest, SIZE);
            salted_password[64] = '\0';
        }
    }
    printf("Final hashed salted password: %s\n", digest);

    return 0;
}