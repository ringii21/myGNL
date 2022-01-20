/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 15:10:35 by abonard           #+#    #+#             */
/*   Updated: 2022/01/20 13:41:35 by abonard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	strlen_custom(char *ptr)
{
	int		i;

	i = 0;
	if (!ptr)
		return (0);
	while (ptr[i])
		i++;
	return (i);
}

void	ft_copy(char *src, char *dest)
{
	int	i;

	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
}

int	ft_check(char *kurkiputcheck, char c)
{
	int	i;

	i = 0;
	while (kurkiputcheck[i])
	{
		if (kurkiputcheck[i] == c)
		{
			i++;
			return (i);
		}
		i++;
	}
	return (-1);
}

char	*ft_frifri(char *str, char *s2)
{
	if (str)
		free(str);
	str = NULL;
	if (s2)
		free(s2);
	s2 = NULL;
	return (NULL);
}
