#include "ft_printf.h"
#include <stdio.h>

void	stat_flag(t_flag *f)
{
	printf("\nalt\t%d\npad_0\t%d\n", f->alt, f->pad_0);
	printf("pad_l\t%d\nsigned\t%d\n", f->pad_left, f->signd);
	printf("s_f\t%c\nform\t%d\n", f->sign_force, f->format);
	printf("alt_s\t%d\npc\t%d\n", f->alt_size, f->precision);
	printf("type\t%c\nbase\t%d\nfw\t%d\n", f->type, f->base, f->fw);
}

void	print_lst(t_list *lst)
{
	t_list *tmp;

	tmp = lst;
	while (tmp)
	{
		printf("\n------------\n");
		printf("data : %s\n", tmp->content);
		printf("size : %zu\n", tmp->content_size);
		tmp = tmp->next;
	}
}
