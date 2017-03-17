/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinfeld <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/07 14:41:04 by jinfeld           #+#    #+#             */
/*   Updated: 2017/03/16 20:08:23 by jinfeld          ###   ########.fr       */
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
		ft_strcpy(*line, save);
	}
}

char	*bufind(t_bufd **bufd, int fd)
{
	t_list	*current;
		
	if (bufd)
	{
		current = *bufd;
		while (current)
		{
			if (current.content_size = fd)
				return(current);
			current = current->next;
		}
		ft_lstadd(bufd, ft_lstnew(NULL, 0));
		(*bufd)->content_size = fd;
		return (*bufd);
	}
	return (NULL);
}

int		get_next_line(const int fd, char **line)
{
	static t_list	*bufd
	t_list			*current
	char			buf[BUFF_SIZE + 1]
	int				ret;
	char			*tmp;
	
	current = bufind(&bufd, fd);
	if (fd < 0)
		return (-1);
	if (tmp == NULL)
		tmp = ft_strnew(0);
	while (!ft_strchr(save, '\n'))
	{
		ret = read(fd, buf, BUFF_SIZE)
		if (ret < 0)
			return (-1);
		if (ret == 0)
			break ;
		*line[ret] = '\0';
		tmp = ft_strjoin(current.content, buf);
		ft_strdel(&current.content);
		current.content = tmp;
	}
	return(linefill(line, current.content));
}
