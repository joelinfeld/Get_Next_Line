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

int		linefill(char **line, char *save)
{
	char	*end;

	end = ft_strchr(save, '\n');
	if (end != NULL)
	{
		*end = '\0';
		end++;
		*line = ft_strnew(ft_strlen(save));
		ft_strcpy(*line, save);
		save = end;
		return(1);
	}
	ft_strcpy(*line, save);
	return(0);
}

t_list	*bufind(t_list **bufd, int fd)
{
	t_list	*current;
		
	if (bufd)
	{
		current = *bufd;
		while (current)
		{
			if ((int)current->content_size == fd)
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
	static t_list	*bufd;
	t_list			*current;
	char			buf[BUFF_SIZE + 1];
	int				ret;
	char			*tmp;
	
	current = bufind(&bufd, fd);
	tmp = NULL;
	if (fd < 0)
		return (-1);
	if (tmp == NULL)
		tmp = ft_strnew(0);
	while (!ft_strchr(current->content, '\n'))
	{
		ret = read(fd, buf, BUFF_SIZE);
		if (ret < 0)
			return (-1);
		if (ret == 0)
			break ;
		*line[ret] = '\0';
		tmp = ft_strjoin(current->content, buf);
		ft_strdel((char**)&current->content);
		current->content = tmp;
	}
	return(linefill(line, current->content));
}

void    ft_read_input(int fd)
{
    char    *line;
    int        r;
    
    while ((r = get_next_line(fd, &line)) > 0)
        printf("return value = %d line content : |%s|\n\n", r, line);
    printf("return value = %d line content : |%s|\n\n", r, line);
}

int			main(int ac, char **av)
{
	if (ac == 2)
	{
		fd = open(av[1], O_RDONLY);
		ft_read_input(fd);
		close(fd);
	}
	else
		ft_read_input(0);
	return(0);
}
