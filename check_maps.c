#include "cub3d.h"

char *get_content(char *argv)
{
	int	fd;
	char *all_content;
	char *line;

	fd = open(argv, O_RDONLY);
	if(fd < 1)
	{
		write(1, "error: file", 13);
		return(NULL);
	}
	while(1)
	{
		line = get_next_line(fd);
		if(!line)
			break;
		all_content = ft_strjoin(all_content, line);
		free(line);
	}
	return(all_content);
}