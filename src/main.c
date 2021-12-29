#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "CSPRNG.h"
#include "SHA256.h"

#define SALT_SIZE 32

int main(int argc, char *argv[])
{
    if (argc != 3)
    {
        printf("Not enough arguments provided. Usage: %s <password> <work factor>\n", argv[0]);
        exit(1);
    }

    unsigned int work_factor;
    char password[strlen(argv[1])];
    char salt[SALT_SIZE];
    char digest[2 * SALT_SIZE];
    unsigned int i;

    strncpy(password, argv[1], strlen(argv[1]));
    password[strlen(argv[1])] = '\0';
    printf("Password: %s\n", password);

    // work_factor = atoi(argv[2]);
    work_factor = 1;
    printf("Work factor: %u\n", work_factor);

    CSPRNG(32, salt);
    printf("Generated salt: %s\n", salt);

    char salted_password[SALT_SIZE + strlen(password)];
    sprintf(salted_password, "%s%s", password, salt);
    printf("Salted password: %s\n", salted_password);
    salted_password[64] = '\0';

    for (i = 0; i < work_factor; i++)
    {
        SHA256(salted_password, digest);
        printf("Hashed salted password (SHA-256 - SHA-2): %s - iteration %u\n", digest, i);
        strcpy(salted_password, digest);
        salted_password[64] = '\0';
    }

    return 0;
}