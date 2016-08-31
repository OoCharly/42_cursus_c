#include "ft_ls.h"

int	yolo(char *path, DIR *dir, t_pcmp cmp, t_util *util)
{
	t_list		**plst;
	int			out;
	int			tmp;

	if (!(plst = ft_lstpnew(NULL, 0)))
		return(2);
	out = get_list(path, dir, util, plst);
	flag |= (out == 2) ? BIG_ERR : 0;
	
}
