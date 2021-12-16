#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <stdlib.h>

void errusage();

int main(int argc, char *argv[])
{

    int isFile = 0, opt;
    int fd = -1;

    while ((opt = getopt(argc, argv, "f:")) != -1)
    {
        switch (opt)
        {
        case 'f':
            if ((fd = open(optarg, O_WRONLY | O_CREAT, 0666)) < 0)
            {
                perror("Open");
            }
            isFile = 1;
            break;
        default:
            errusage();
            break;
        }
    }
}

void errusage()
{
    fprintf(stderr, "Usage: sort [-f \"file\" | token1 token2 ...]");
    exit(1);
}
