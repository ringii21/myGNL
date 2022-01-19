/************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   second_get_next_line.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 15:10:22 by abonard           #+#    #+#             */
/*   Updated: 2022/01/19 20:48:33 by abonard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "get_next_line.h"

char	*concat(char *str, char *buffer)
{
	int		len_str;
	char	*new_str;
	int		lenght_buff;
	int		total_lenght;

	len_str = strlen_custom(str);
	lenght_buff = strlen_custom(buffer);
	total_lenght = len_str + lenght_buff;
	new_str = (char *)malloc(sizeof (char ) * (total_lenght + 1));
	if (new_str == NULL)
	{
		free(str);
		return (NULL);
	}
	if (str)
		ft_copy(str, new_str);
	ft_copy(buffer, new_str + len_str);
	free(str);
	return (new_str);
}

char	*ft_input(char *str, char *line /*int stop*/)
{
	int	i;
	int	j;

	j = 0;
	if (!str)
	{
		free(str);
		return (NULL);
	}
	i = ft_check(str, '\n');
//	printf("i->%d\nstop%d\n", i, stop);
	if (i == -1)
		i = strlen_custom(str);
	line = malloc(sizeof(char) * i + 1);
	if (line == NULL)
		return (NULL);
	while (j < i)
	{
	//	if (str[george] == '\n' && stop == 1)
	//		break;
		line[j] = str[j];
		j++;
	}
	line[j] = '\0';
	return (line);
}

char	*realloc_thing(char *str)
{
	char	*new_str;
	int		lenght_nstr;
	int		lenght_str;
	int		i = 0;
	int		temp;

	if (str[0] == '\0')
	{
		free(str);
		return (NULL);
	}
	lenght_str = strlen_custom(str);
	lenght_nstr = ft_check(str, '\n');
//	printf("|%d|\n", lenght_nstr);
	temp = lenght_nstr;
	lenght_nstr = lenght_str - lenght_nstr;
	new_str = malloc(sizeof(char) * lenght_nstr + 1);
	if (new_str == NULL)
	{
		free(str);
		return (NULL);
	}
	while (i < lenght_nstr)
	{
		new_str[i] = str[temp + i];
		i++;
	}
	new_str[i] = '\0';
	free(str);
	return (new_str);
}

char	*get_next_line(int fd)
{
	static char	*str;
	char		*line;
	char		buff[BUFFER_SIZE + 1];
//	int			stop;
	int			i;

//	stop = -1;
	line = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, buff, 0) < 0)
		return (NULL);
	while (1)
	{
		i = read(fd, buff, BUFFER_SIZE);
		buff[i] = '\0';
		str = concat(str, buff);
		if (str == NULL)
			return (ft_frifri(str, NULL));
		if ((ft_check(str, '\n') != -1) || i == 0)
		{/*
			if (i == 0)
				stop = 1;*/
			break ;
		}
	}
	line = ft_input(str, line);
	if (line == NULL)
		return (ft_frifri(str, NULL));
	str = realloc_thing(str);
	if (str == NULL)
		return (ft_frifri(line, NULL));
	return (line);
}


#include <fcntl.h>

int main(int ac, char **av)
{
	(void)ac;
	char *line;
	int fd = open(av[1], O_RDONLY);

	while ((line = get_next_line(fd)) != NULL)
	{
		printf("%s", line);
		free(line);
	}
	free(line);
	//while (1)
	//	;
//	exit(1);
	system("leaks a.out");
	return (0);
}
