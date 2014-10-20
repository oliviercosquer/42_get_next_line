#include "get_next_line.h"
#include "libft.h"

int		main(int argc, char **argv)
{
	char	*line;
	int		fd;
	int		code;

	line = NULL;
	if (argc == 2)
	{
		fd = open(argv[1], O_RDONLY);
		while ((code = get_next_line(fd, &line)) > 0)
		{
			ft_putstr(line);
			line = NULL;
			ft_strdel(&line);
			ft_putstr("\n");
		}
	}
	return (0);
}
