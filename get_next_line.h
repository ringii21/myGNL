/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 16:07:28 by abonard           #+#    #+#             */
/*   Updated: 2021/12/20 16:13:38 by abonard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifdef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <unistd.h>
# include <stdlib.h>

int		strlen_custom(char *ptr);
int		ft_check(char *kurkiputcheck, char c);
void	ft_copy(char *src, char *dest);
char	*concat(char *str, char *buffer);
char	*ft_input(char *str, char *line);
char	*realloc_thing_well_shit(char *line, char *str);
char	*ft_frifri(char *str);

#endif

