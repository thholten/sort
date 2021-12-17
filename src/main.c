#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <stdlib.h>

#include "sort.h"

void errusage();

int main(int argc, char *argv[])
{

    int opt;
    int fd = -1;

    while ((opt = getopt(argc, argv, "f:")) != -1)
    {
        switch (opt)
        {
        case 'f':
            if ((fd = open(optarg, O_WRONLY | O_CREAT, 0666)) < 0)
            {
                perror("Main");
                exit(1);
            }

            // direct stdout to file
            if (dup2(fd, 1) < 0)
            {
                perror("Main");
                exit(1);
            }
            break;
        default:
            errusage();
            break;
        }
    }
    return sort();
}

void errusage()
{
    fprintf(stderr, "Usage: sort [-f \"file\" | token1 token2 ...]");
    exit(1);
}
