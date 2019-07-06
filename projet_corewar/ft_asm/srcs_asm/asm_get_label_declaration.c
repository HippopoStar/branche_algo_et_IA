#include "ft_asm.h"

/*
**	ft_putstr("get_label_declaration\n");
*/

int		asm_get_label_declaration(t_asm_data *data, char *line, size_t *i, size_t pos)
{
	size_t	j;

	ft_putstr("get_label_declaration\n");
	j = 0;
	while (ft_strchr(LABEL_CHARS, (int)*(line + (*i) + j)))
	{
		j++;
	}
	if (*(line + (*i) + j) == LABEL_CHAR)
	{
		*(line + (*i) + j) = '\0';
		if (data->label_tab + pos == NULL
				&& !((*(data->label_tab + pos) = ft_strdup(&(*(line + (*i))))) == NULL))
		{
			*i = (*i) + j + 1;
			asm_skip_spacing_chars(line, i);
		}
		else
		{
			return (0);
		}
	}
	return (1);
}
