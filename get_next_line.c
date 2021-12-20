/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 14:12:38 by abonard           #+#    #+#             */
/*   Updated: 2021/12/20 17:26:45 by abonard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "get_next_line_utils.c"
#include <unistd.h>
#include <stdlib.h>

char	*concat(char *str, char *buffer)
{
	int		guy;
	char	*new_str;
	int		lenght_buff;

	guy = strlen_custom(str);
	lenght_buff = strlen_custom(buffer);
	new_str = (char *)malloc(sizeof (char ) * (guy + lenght_buff + 1));
	if (new_str == NULL)
		return (NULL);
	if (str)
		ft_copy(str, new_str);
	ft_copy(buffer, new_str + guy);
	free(str);
	return (new_str);
}

char	*ft_input(char *str, char *line)
{
	int	i;
	int	george;

	george = 0;
	//mallloc la bonne taille
	i = ft_check(str, '\n');
	if (i == -1)
		i = strlen_custom(str);
	line = malloc(sizeof(char) * i + 1);
	if (line == NULL)
		return NULL;
	while (george < i)
	{
		line[george] = str[george];
		george++;
	}
	line[george] = '\0';
	return (line);
}

char	*realloc_thing_well_shit(char *line, char *str)
{
	char	*new_str;
	int		lenght_nstr;
	int		guy;
	int		i;
	int		lolo;

	guy = strlen_custom(str);
	lenght_nstr = strlen_custom(line);
	lolo = lenght_nstr + 1;
	lenght_nstr = guy - lenght_nstr;
	new_str = malloc(sizeof(char) * lenght_nstr + 1);
	if (new_str == NULL)
		return NULL;
	i = 0;
	while (i < lenght_nstr)
	{
		new_str[i] = str[lolo + i];
		i++;
	}
	new_str[i] = '\0';
	free(str);
	return (new_str);
}

char	*get_next_line(int fd)
{
	static char	*str;
	char		*line = NULL;
	char		buff[BUFFER_SIZE + 1];
	int			i;
	
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, buff, 0) < 0)
		return (NULL);
	while (1)
	{
		i = read(fd, buff, BUFFER_SIZE);
		buff[i] =  '\0';
		str = concat(str, buff);
		if (str == NULL)
			return (ft_frifri(str));
		if ((ft_check(str, '\n') > 0) || i == 0)
			break;
	}
	line = ft_input(str, line);
	if (line == NULL)
		return (ft_frifri(str));
	str = realloc_thing_well_shit(line, str);
	if (str == NULL)
		return (ft_frifri(line));
	return (line);
}