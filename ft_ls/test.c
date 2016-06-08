#include "../libft/includes/libft.h"
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/dir.h>
#include <sys/stat.h>
#include <time.h>

int	main(int ac, char **av)
{
	struct stat	*s;
	struct dirent	*d;
	DIR			*pdir;
	int			n;
	
	if (ac == 1)
		pdir = opendir("./");
	else
		pdir = opendir(av[1]);
	d = readdir(pdir);
	printf("%s\n", d->d_name);
	if (!pdir)
		perror(strerror(errno));
	return (0);
}
