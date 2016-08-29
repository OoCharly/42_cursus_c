#include "ft_ls.h"

int	yolo(int flag, char *path, DIR *dir, pcmp cmp)
{
	t_list		**plst;
	void		(*f)(char*);

	if (!(plst = ft_lstpnew(NULL, 0)))
		return(NULL);
	f = (flag & NO_STAT) ? &ls_getinfo : &ls_getinfo_nostat;
}
