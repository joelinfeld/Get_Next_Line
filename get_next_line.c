/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinfeld <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/07 14:41:04 by jinfeld           #+#    #+#             */
/*   Updated: 2017/03/09 13:49:21 by jinfeld          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		linefill(char **line, char *save)
{
	char	end;

	end = ft_strchr(save, '\n');
	if (end != NULL)
	{
		end = '\0';
	}
}

int		get_next_line(const int fd, char **line)
{
	static char *save;
	char		buf[BUFF_SIZE + 1]
	char		*tmp;
	int			ret;
	
	if (fd < 0)
		return (-1);
	if (save == NULL)
		save = ft_strnew(0);
	while (!ft_strchr(save, '\n'))
	{
		ret = read(fd, buf, BUFF_SIZE)
		if (ret < 0)
			return (-1);
		if (ret == 0)
			break ;
		line[ret] = '\0';
		tmp = ft_strjoin(save, buf);
		ft_strdel(save);
		save = tmp;
	}
	return(linefill(line, save));
	if (close(fd) < 0)
		return (-1);
}
