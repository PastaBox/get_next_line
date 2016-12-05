/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grleblan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/04 11:00:35 by grleblan          #+#    #+#             */
/*   Updated: 2016/12/04 12:44:11 by grleblan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFF_SIZE 20
# include <fcntl.h>
# include "../libft/libft.h"

typedef struct		s_gnl
{
	char			*str;
	struct s_gnl	*next;
}					t_gnl;

int			get_next_line(const int fd, char **line);

#endif
