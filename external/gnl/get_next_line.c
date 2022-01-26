/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcorso <mcorso@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 15:35:25 by mcorso            #+#    #+#             */
/*   Updated: 2022/01/26 01:24:15 by mcorso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*find_eol(int fd, char *buffer)
{
	char	*tmp;
	int		read_stat;

	read_stat = 1;
	tmp = malloc(sizeof(*tmp) * (BUFFER_SIZE + 1));
	if (!tmp)
		return (0);
	while (!chr(buffer, '\n') && read_stat != 0)
	{
		read_stat = read(fd, tmp, BUFFER_SIZE);
		if (read_stat < 0)
		{
			free(tmp);
			return (NULL);
		}
		tmp[read_stat] = '\0';
		buffer = join(buffer, tmp);
	}
	free(tmp);
	return (buffer);
}

char	*line_cpy(char *buffer)
{
	int		i;
	char	*ret;

	i = 0;
	if (!*buffer)
		return (NULL);
	while (buffer[i] && buffer[i] != '\n')
		i++;
	ret = malloc(sizeof(*ret) * (i + 2));
	if (!ret)
		return (NULL);
	i = 0;
	while (*buffer && *buffer != '\n')
		ret[i++] = *buffer++;
	if (*buffer == '\n')
		ret[i++] = *buffer++;
	ret[i] = '\0';
	return (ret);
}

char	*clean_buff(char *buffer)
{
	int		i;
	int		j;
	char	*new_buff;

	i = 0;
	j = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (!buffer[i])
	{
		free(buffer);
		return (NULL);
	}
	new_buff = malloc(sizeof(*new_buff) + (len(buffer) - i + 1));
	i++;
	if (!new_buff)
		return (NULL);
	while (buffer[i])
		new_buff[j++] = buffer[i++];
	new_buff[j] = '\0';
	free(buffer);
	return (new_buff);
}

char	*get_next_line(int fd)
{
	char		*ret;
	static char	*buffer;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	buffer = find_eol(fd, buffer);
	if (!buffer)
		return (NULL);
	ret = line_cpy(buffer);
	buffer = clean_buff(buffer);
	return (ret);
}
