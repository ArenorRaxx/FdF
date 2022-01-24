/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcorso <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 15:33:44 by mcorso            #+#    #+#             */
/*   Updated: 2022/01/16 17:27:05 by mcorso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

int		ft_strchr(char *s, char c);
char	*get_next_line(int fd);
char	*line_cpy(char *buffer);
char	*clean_buff(char *buffer);
char	*find_eol(int fd, char *buffer);
char	*ft_strjoin(char *s1, char *s2);
size_t	ft_strlen(char *str);

#endif
