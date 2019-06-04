#include "lem_in.h"

/*
** On ne peut pas depasser les tableaux dans un sens ni dans l'autre,
** car on sait que chaque tableau commence par '0', correspondant a
** la 1ere salle, et se termine par 'data->size', correspondant a la derniere
** salle (au plus tard en position 'data->size - 1')
*/

void	li_swap_paths(t_route *route, size_t i, size_t j)
{
	size_t	*tmp;

	tmp = *(route->field + i);
	*(route->field + i) = *(route->field + j);
	*(route->field + j) = tmp;
}

void	li_order_paths(t_route *route)
{
	size_t	*tmp;
	size_t	i;

	i = 1;
	while (i <= route->height)
	{
		while (*(*(route->field + i - 1) + route->width) > *(*(route->field + i) + route->width) && i > 0)
		{
			tmp = *(route->field + i - 1);
			*(route->field + i - 1) = *(route->field + i);
			*(route->field + i) = tmp;
			i--;
		}
		i++;
	}
}

size_t	li_edge_len(t_route *route, size_t i, size_t j, size_t k)
{
	size_t	edge_len;
	size_t	*len_1;
	size_t	*len_2;
	size_t	tmp;

	edge_len = 0;
	while (*(*(route->field + i) + j - 1) == *(*(route->field + route->height) + k + 1))
	{
		j--;
		k++;
		edge_len++;
	}
	len_1 = &(*(*(route->field + i) + route->width));
	len_2 = &(*(*(route->field + route->height) + route->width));
	ft_putstr("begin :\n");
	ft_putstr("(*len_1) vaut : ");
	ft_putnbr((int)(*len_1));
	ft_putchar('\n');
	ft_putstr("(*len_2) vaut : ");
	ft_putnbr((int)(*len_2));
	ft_putchar('\n');
	ft_putstr("edge_len vaut : ");
	ft_putnbr((int)edge_len);
	ft_putchar('\n');
	ft_putstr("j vaut : ");
	ft_putnbr((int)j);
	ft_putchar('\n');
	ft_putstr("k vaut : ");
	ft_putnbr((int)k);
	ft_putchar('\n');
	tmp = (*len_1);
	*len_1 = j + ((*len_2) - k);
	*len_2 = k + (tmp - j) - (2 * edge_len);
	ft_putstr("(*len_1) vaut : ");
	ft_putnbr((int)(*len_1));
	ft_putchar('\n');
	ft_putstr("(*len_2) vaut : ");
	ft_putnbr((int)(*len_2));
	ft_putchar('\n');
	return (edge_len);
}

void	li_melt_paths(t_route *route, size_t i, size_t j, size_t k)
{
	size_t	edge_len;

	edge_len = li_edge_len(route, i, j, k);
	while (j < route->width && k + edge_len < route->width)
	{
		*(*(route->field + i) + j - edge_len) = *(*(route->field + route->height) + k + edge_len);
		*(*(route->field + route->height) + k) = *(*(route->field + i) + j);
		j++;
		k++;
	}
	while (j < route->width || k + edge_len < route->width)
	{
		if (j < k + edge_len)
		{
			*(*(route->field + i) + j) = 0;
		}
		else
		{
			*(*(route->field + route->height) + k + edge_len) = 0;
		}
		j++;
		k++;
	}
}

void	li_remove_edges(t_route *route)
{
	size_t	i;
	size_t	j;
	size_t	k;

	k = 1;
	while (k + 1 < *(*(route->field + route->height) + route->width) && *(*(route->field + route->height) + k) != 0)
	{
		j = 1;
		while (j < route->width)
		{
			i = 0;
			while (i < route->height)
			{
				if (*(*(route->field + i) + j) == *(*(route->field + route->height) + k))
				{
					ft_putstr("i vaut : ");
					ft_putnbr((int)i);
					ft_putchar('\n');
					ft_putstr("j vaut : ");
					ft_putnbr((int)j);
					ft_putchar('\n');
					ft_putstr("k vaut : ");
					ft_putnbr((int)k);
					ft_putchar('\n');
					li_melt_paths(route, i, j, k);
					li_swap_paths(route, i, route->height);
					k = 1;
					j = route->width;
					i = route->height;
				}
				i++;
			}
			j++;
		}
		k++;
	}
}