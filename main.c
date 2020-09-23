#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include "get_next_line.h"

int main(int ac, char **av)
{
    (void)ac;
    int fd = open(av[1], O_RDONLY);
    char *line;
    int ret = 0;
    while ((ret = get_next_line(fd, &line)) > 0)
    {
        printf("[%d] %s\n", ret, line);
        free(line);
    }
    printf("[%d] %s\n", ret, line);
    free(line);
    //printf("%s\n", line);
}