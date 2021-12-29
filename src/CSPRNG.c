#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include "CSPRNG.h"
#include "utils.h"

void CSPRNG(unsigned int size, char salt[size])
{
    FILE *fp;
    char buffer[BUFFER_SIZE];
    char output[BUFFER_SIZE];
    char salt_s[BUFFER_SIZE];
    int j;

    char command[30];
    sprintf(command, "hexdump -C -n %u /dev/urandom", size);

    // Open pipeline
    fp = popen(command, "r");

    if (fp == NULL)
    {
        printf("Failed to run command\n");
        exit(1);
    }

    // Reads first line of output
    fgets(buffer, sizeof(buffer), fp);
    if (buffer[strlen(buffer) - 1] == '\n')
    {
        sprintf(output, "%s", buffer);
    }

    for (j = 0; j < BUFFER_SIZE; j++)
    {
        if (output[j] == '|')
        {
            break;
        }
    }

    subString(output, 10, j - 10, salt_s);

    removeChar(salt_s, ' ');

    strcpy(salt, salt_s);
    salt[2 * size] = '\0';

    // Closes pipeline
    pclose(fp);
}