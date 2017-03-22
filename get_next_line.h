/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinfeld <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/07 14:42:00 by jinfeld           #+#    #+#             */
/*   Updated: 2017/03/21 19:07:43 by jinfeld          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFF_SIZE 32
# include <stdlib.h>

struct	s_bufd
{
	int					fd;
	char 				*save;
	struct s_bufd 		*next;
}				t_bufd;
int get_next_line(const int fd, char **line);

#endif
