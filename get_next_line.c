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

/*
char	*ft_strjoinfree(char *s1, char *s2, int f)
{
	char	*s3;

	if (s2 == NULL)
		return (NULL);
	if (s1 == NULL)
		return (ft_strdup(s2));
	s3 = ft_strnew(ft_strlen(s1) + ft_strlen(s2));
	if (s3)
	{
		ft_strcpy(s3, s1);
		ft_strcat(s3, s2);
	}
	if (f == 1)
		ft_strdel(&s1);
	else if (f == 2)
		ft_strdel(&s2);
	return (s3);
}
*/

int		linefill(char **line, char **save)
{
	char *end;

	if(ft_strlen(*save))
	{
		end = ft_strchr(*save, '\n');
		if (end != NULL)
		{
			*end = '\0';
			*line = ft_strdup(*save);
			ft_strclr(*save);
			*save = ++end;
			return(1);
		}
		else
		{
			*line = ft_strdup(*save);
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
	current = NULL;
	ft_lstadd(bufd, ft_lstnew(NULL, 0));
	(*bufd)->content_size = fd;
	(*bufd)->content = ft_strnew(0);
	return (*bufd);
}

int		get_next_line(const int fd, char **line)
{
	static t_list	*bufd;
	t_list			*current;
	char			buf[BUFF_SIZE + 1];
	char			*tmp;
	int				ret;
	
	if (fd < 0 || !line || BUFF_SIZE < 0)
		return (-1);
	current = bufind(&bufd, fd);
	while ((ret = read(fd, buf, BUFF_SIZE)))
	{
		if (ret < 0)
			return (-1);
		buf[ret] = '\0';
		tmp = ft_strjoinfree(current->content, buf, 1);
		ft_strdel((char**)&current->content);
		current->content = ft_strdup(tmp);
		ft_strdel(&tmp);
		ft_strclr(buf);
	
		if (ft_strchr(current->content, '\n'))
			break ;
	}
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
