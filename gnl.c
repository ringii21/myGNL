/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 13:09:47 by abonard           #+#    #+#             */
/*   Updated: 2022/01/18 13:42:05 by abonard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

char	*concat(char *str, char *buff)
{
	int		i;
	char	*new_str;
	int		len_buff;
	int		total;

	i = strlen_custom(str);
	len_buff = strlen_custom(buff);
	total = i + len_buff;
	new_str = (char *)malloc(sizeof (char ) * (total + 1));
	if (new_str == NULL)
		return (NULL);
	if (str)
		ft_copy(str, new_str);
	total = 0;
	while (buff[total])
	{
		new_str[i + total] = buff[total];
		total++;
	}
	new_str[i + total] = '\0';
	free(str);
	return (new_str);
}

/*char	*ft_input(char *str, int stop)
{
	int	i;
	int	j;
	char *line;
(void)stop;
	i = 0;
	while (str && str[i] && str[i] != '\n')
		i++;
	if (i == 0)
		i = -1;
	printf("%d", i);
	line = malloc(sizeof(char) * i + 1);
	if (line == NULL)
		return (NULL);
	j = 0;
	while (j < i)
	{
	//	if (str[j] == '\n' && stop == 1)
	//		break;
		line[j] = str[j];
		j++;
	}
	line[j] = '\0';
	return (line);
}*/

char	*ft_input(char *str, int stop)
{
	int		len;
	int		i;
	char	*line;

	len = 0;
	i = 0;
	len = ft_check(str, '\n') - 1;
	if (len == 0)
		len = ft_check(str, '\0') - 1;
	if (len == 0)
		stop = -1;
	if ((line = malloc(sizeof(char) * (len + 1))) == NULL)
		return (NULL);
	while (i < len + 1)
	{
		line[i] = str[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	*realloc_thing(char *str)
{
	char	*new_str;
	int		lenght_nstr;
	int		lenght_str;
	int		i = 0;
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
	static char	*str = NULL;
	char		*line;
	char		buff[BUFFER_SIZE + 1];
	int			stop;
	int i = 0;

	stop = -1;
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
		{
			if (i == 0)
				stop = 1;
			break ;
		}
	}
	line = ft_input(str, stop);
	if (line == NULL)
		return (ft_frifri(str));
	str = realloc_thing(str);
	if (str == NULL)
		return (ft_frifri(line));
	return (line);
}
#include <fcntl.h>

int main(int ac, char **av)
{
	(void)ac;
	char *line;
	int fd = open(av[1], O_RDONLY);
	int i = 0;
	while ((line = get_next_line(fd)) != NULL)
	{
		printf("line = %s", line);
		free(line);
		i++;
	}
	return (0);
}
