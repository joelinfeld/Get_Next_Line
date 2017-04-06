/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinfeld <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/07 14:41:04 by jinfeld           #+#    #+#             */
/*   Updated: 2017/03/21 19:05:56 by jinfeld          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>

int		linefill(char **line, char **save)
{
	char *end;

	if(ft_strlen(*save))
	{
		end = ft_strchr(*save, '\n');
		*line = ft_strnew(ft_strlen(*save));
		if (end != NULL)
		{
			*end = '\0';
			ft_memmove(*line, *save, ft_strlen(*save));
			ft_strclr(*save);
			*save = ++end;
			return(1);
		}
		else
		{
			ft_memmove(*line, *save, ft_strlen(*save));
			ft_strclr(*save);
			return (1);	
		}
	}
	return (0);
}

t_list	*bufind(t_list **bufd, int fd)
{
	t_list	*current;
		
	current = *bufd;
	while (current)
	{
		if ((int)current->content_size == fd)
			return(current);
		current = current->next;
	}
	ft_lstadd(bufd, ft_lstnew("", fd));
	return (*bufd);
}

int		get_next_line(const int fd, char **line)
{
	static t_list	*bufd;
	t_list			*current;
	char			buf[BUFF_SIZE + 1];
	int				ret;
	char			*tmp;
	
	if (fd < 0 || !line || (!(tmp = ft_strnew(0))))
		return (-1);
	current = bufind(&bufd, fd);
	while ((ret = read(fd, buf, BUFF_SIZE)))
	{
		if (ret < 0)
			return (-1);
		buf[ret] = '\0';
		tmp = ft_strjoin(current->content, buf);
		ft_strclr(current->content);
		current->content = tmp;
		if (ft_strchr(current->content, '\n'))
			break ;
	}
	ft_strdel(&tmp);
	return(linefill(line, (char**)&current->content));
}

/*
int			main(int ac, char **av)
{
	int		fd;
	char	*line;

	if (ac == 1)
		fd = 0;
	if (ac == 2)
		fd = open(av[1], O_RDONLY);
	else return (2);
	while	(get_next_line(fd, &line) == 1)
	{
		ft_putendl(line);
		free(line);
	}
	if (ac == 2)
		close (fd);
	return(0);
}
*/
