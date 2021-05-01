#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "get_next_line.h"
#include "get_next_line_bonus.h"

int main(int argc, char **argv)
{
	int i = 1;
	char *line;
	int fd;
	int gnl_return;
	line = NULL;

	if (argc == 1)
	{
		printf("-------- Argument not found. Please enter a filename or write to the stdin ---------\n");
		fd = 0;
	}
	if (argc > 2)
	{
		printf("------------------- Only one argument needs to be entered -----------------------\n");
		return (1);
	}
	if (argc == 2)
	{
		fd = open(argv[1], O_RDONLY);
		if (fd == -1)
		{
			printf("----------------------- Error : unable to open file -----------------------------\n");
			return (1);
		}
	}
	while ((gnl_return = get_next_line(fd, &line)) > 0)
	{
		printf("GNL return line %d: %d [%s]\n", i++, gnl_return, line);
		//getchar();
		free(line);
	}
	printf("GNL return line %d: %d [%s]\n", i++, gnl_return, line);
	free(line);
	if (close(fd) == -1)
	{
		printf("---------------------------- File closing error -------------------------------\n");
		return (1);
	}
	printf("\nTest des leaks\n");
	system("leaks a.out | grep leaked\n");
	return (0);
}
