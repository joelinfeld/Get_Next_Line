/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinfeld <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/07 14:41:04 by jinfeld           #+#    #+#             */
/*   Updated: 2017/03/07 20:36:43 by jinfeld          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		get_next_line(const int fd, char **line)
{
	static char *save;
	char	buf[BUFF_SIZE + 1]
	
	if(!(buf = (char*)ft_memalloc(BUFF_SIZE + 1)))
		return (-1);
	if (fd < 0)
		return (-1);
	while (!ft_strchr(save, '\n'))
	{
		ret = read(fd, *line, BUFF_SIZE)
		if (ret < 0)
			return (-1);
		if (ret == 0)
			break ;
		line[ret] = '\0';
		str = ft_strjoin(str, buf);
	}
	if (close(fd) < 0)
		return (-1);
}
