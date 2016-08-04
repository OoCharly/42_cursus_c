#include "../libft/includes/libft.h"
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/dir.h>
#include <sys/stat.h>
#include <attr/xattr.h>
#include <time.h>
/***test1***/
int	main(int ac, char **av)
{
	struct stat	*s;
	struct dirent	*d;
	DIR			*pdir;
	int			n;
	char		path[_POSIX_PATH_MAX];
	
	s= malloc(sizeof(struct stat));
	strcat(path, "./");
	if (ac == 1)
		pdir = opendir("./");
	else
	{
		strcat(path, av[1]);
		pdir = opendir(av[1]);
	}
	if (path[strlen(path) - 1] != '/')
		path[strlen(path)] = '/';
	while ((d = readdir(pdir)))
	{
		memcpy(strrchr(path, '/') + 1, d->d_name, strlen(d->d_name) +1);
		if ((lstat(path, s)) < 0)
		{
			perror(path);
			exit(-1);
		}
		printf("%s\n", d->d_name);
		printf("time %lu\ntime %sblks %ld\n\n", s->st_mtime, ctime(&(s->st_mtime)), s->st_nlink);
	}
	if (!pdir)
		perror(strerror(errno));
	return (0);
}
/***test2***
int	main(int ac, char **av)
{
	char	path[_POSIX_PATH_MAX];
	int	i;

	i = 0;
	while (i < _POSIX_PATH_MAX)
		path[i++] = 0;
	if (ac != 2)
		return (1);
	printf("%zd\n", getxattr("/", "usr", path, 10));
	perror("xattr");
	printf("%s\n", path);
	printf("%zd\n", listxattr(av[1], path, 10));
	printf("%s\n", path);
	return (0);
}
*/
