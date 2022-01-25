/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 16:07:28 by abonard           #+#    #+#             */
/*   Updated: 2022/01/20 14:12:25 by abonard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H

# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

int		strlen_custom(char *ptr);
int		ft_check(char *kurkiputcheck, char c);
void	ft_copy(char *src, char *dest);
char	*concat(char *str, char *buffer);
char	*ft_input(char *str, char *line, char *buff);
char	*realloc_thing_well_shit(char *line, char *str);
char	*ft_frifri(char *str, char *s2);
char	*get_next_line(int fd);

#endif
