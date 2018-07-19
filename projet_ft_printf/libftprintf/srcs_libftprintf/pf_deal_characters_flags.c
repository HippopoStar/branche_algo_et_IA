#include "libftprintf.h"

/*
**	ft_putstr("Appel de \"pf_malloc_and_left_spaces\"\n");
*/

char	*pf_malloc_and_left_spaces(size_t spac, size_t length)
{
	ft_putstr("Appel de \"pf_malloc_and_left_spaces\"\n");
	char	*str;
	size_t	i;

	if (!(str = (char *)malloc((spac + 1) * sizeof(char))))
		return (NULL);
	i = 0;
	while (i < spac - length)
	{
		*(str + i) = ' ';
		i++;
	}
	*(str + spac) = '\0';
	return (str);
}

/*
**	ft_putstr("Appel de \"pf_deal_characters_flags\"\n");
*/

void	pf_deal_characters_flags(const char *format, char *str)
{
	ft_putstr("Appel de \"pf_deal_characters_flags\"\n");
	size_t	i;
	size_t	decal;

	if (pf_is_flag_present(format, '0'))
	{
		i = 0;
		while (*(str + i) == ' ')
		{
			*(str + i) = '0';
			i++;
		}
	}
	else if (pf_is_flag_present(format, '-'))
	{
		decal = 0;
		while (*(str + decal) == ' ')
		{
			decal++;
		}
		i = 0;
		while (*(str + decal + i) != '\0')
		{
			*(str + i) = *(str + decal + i);
			*(str + decal + i) = ' ';
			i++;
		}
	}
}
