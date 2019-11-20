#include <stdio.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include "get_next_line.h"

int get_next_line(int fd, char **line);

int main(void)
{
    int fd;
    int retour;
    char *line;

    line = (char *)malloc(sizeof(char) * 1000);
    fd = open("text.txt", O_RDONLY);
    while (retour != 0)
    {
    	retour = get_next_line(fd, &line);
		printf("%s\n", line);
    }
    close (fd);
    return (fd);
}
