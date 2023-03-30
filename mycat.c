#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main(int argc, char **argv)
{

    if (argc < 2)
    {
        printf("引数が足りません");
        return 1;
    }

    for (int i = 1; i < argc; i++)
    {
        int fd = open(argv[i], O_RDONLY);
        char buf[256];
        int n = read(fd, buf, sizeof buf);
        write(STDOUT_FILENO, buf, n);
    }
}