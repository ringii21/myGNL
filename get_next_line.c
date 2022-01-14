/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   second_get_next_line.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 15:10:22 by abonard           #+#    #+#             */
/*   Updated: 2022/01/14 16:30:29 by abonard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "get_next_line.h"

char	*concat(char *str, char *buffer)
{
	int		guy;
	char	*new_str;
	int		lenght_buff;
	int		total_lenght;

	guy = strlen_custom(str);
	lenght_buff = strlen_custom(buffer);
	total_lenght = guy + lenght_buff;
	if (!total_lenght)
		return (free(str), NULL);
	new_str = (char *)malloc(sizeof (char ) * (total_lenght + 1));
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

	if (!str)
		return (NULL);
	george = 0;
	i = ft_check(str, '\n') - 1;
	if (i == -1)
		i = ft_check(str, '\0') - 1;
	line = malloc(sizeof(char) * i + 1);
	if (line == NULL)
		return (ft_frifri(str));
	while (george < i)
	{
		line[george] = str[george];
		george++;
	}
	line[george] = '\0';
	return (line);
}

char	*realloc_thing(char *str)
{
	char	*new_str;
	int		lenght_nstr;
	int		lenght_str;
	int		i;
	int		temp;

	if (!str)
		return (NULL);
	lenght_str = strlen_custom(str);
	lenght_nstr = ft_check(str, '\n');
	temp = lenght_nstr;
	lenght_nstr = lenght_str - lenght_nstr;
	new_str = malloc(sizeof(char) * lenght_nstr + 1);
	if (new_str == NULL)
		return (NULL);
	i = 0;
	if (!str[i])
		return (ft_frifri(str));
	while (i < lenght_nstr)
	{
		new_str[i] = str[temp + i];
		i++;
	}
	new_str[i] = '\0';
	return (free(str), new_str);
}

char	*get_next_line(int fd)
{
	static char	*str;
	char		*line;
	char		buff[BUFFER_SIZE + 1];
	int			i;

	line = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, buff, 0) < 0)
		return (NULL);
	while (1)
	{
		i = read(fd, buff, BUFFER_SIZE);
		buff[i] = '\0';
		str = concat(str, buff);
		if (str == NULL)
			return (ft_frifri(str));
		if ((ft_check(str, '\n') != -1) || i == 0)
			break ;
	}
	line = ft_input(str, line);
	if (line == NULL)
		return (ft_frifri(str));
	str = realloc_thing(str);
	if (str == NULL)
		return (ft_frifri(line));
	return (line);
}

/*
#include <fcntl.h>

int main(int ac, char **av)
{
	(void)ac;
	char *line;
	int fd = open(av[1], O_RDONLY);
	int i = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL || i == 20)
			break;
		printf("line = %s\n", line);
		free(line);
		i++;
	}
	return (0);
}*/
