/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcorso <mcorso@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 15:33:44 by mcorso            #+#    #+#             */
/*   Updated: 2022/01/26 01:22:58 by mcorso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

int		chr(char *s, char c);
char	*get_next_line(int fd);
char	*line_cpy(char *buffer);
char	*clean_buff(char *buffer);
char	*find_eol(int fd, char *buffer);
char	*join(char *s1, char *s2);
size_t	len(char *str);

#endif
