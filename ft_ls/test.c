#include "../libft/includes/libft.h"
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <sys/dirent.h>
#include <sys/types.h>
#include <sys/dir.h>
#include <sys/stat.h>
#include <time.h>

int	main(int ac, char **av)
{
	struct stat	*s;
	DIR			*pdir;
	int			n;

	s = ft_memalloc(sizeof(struct stat));
	printf("%d\n", lstat("/tmp", s));
	printf("%d\n", s->st_mode);
	return (0);
}
