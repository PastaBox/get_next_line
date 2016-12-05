/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grleblan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/04 11:02:55 by grleblan          #+#    #+#             */
/*   Updated: 2016/12/05 18:09:29 by grleblan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char		*ft_strjoin_string(char *s1, char *s2)
{
	char	*str;

	if (s1 == NULL)
		if(!(s1 = ft_strnew(0)))
			return (NULL);
	if (s2 != NULL)
	{
		if (!(str = ft_strnew(ft_strlen(s1) + ft_strlen(s2))))
			return (NULL);
		ft_strcpy(str, s1);
		ft_strcat(str, s2);
		return (str);
	}
	return (NULL);
}

int			get_end_of_line(char **tmp, char **line)
{
	char				*len;
	unsigned int		start;

	start = 0;
	if ((len = ft_strchr(*tmp, '\n')))
	{
		if (!(*line = ft_strsub(*tmp, start, len - *tmp)))
			return (0);
		ft_strcpy(*tmp, len + 1);
		return (1);
	}
	return (0);
}

int			get_next_line(int fd, char **line)
{
	int				reader;
	char			buffer[BUFF_SIZE + 1];
	static char		*tmp = NULL;

	if (tmp && get_end_of_line(&tmp, line))
		return (1);
	while ((reader = read(fd, buffer, BUFF_SIZE)) > 0)
	{
		buffer[reader] = '\0';
		tmp = ft_strjoin_string(tmp, buffer);
		if (get_end_of_line(&tmp, line))
			return (1);
	}
	if (reader < 0 || fd <= 0)
		return (-1);
	return (0);
}

int			main(int argc, char **argv)
{
	int			fd;
	char		*line;
	int i;

	i = 0;
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		return (0);
	while (i < 1)
	{
		get_next_line(fd, &line);
		ft_putendl(line);
		i++;
	}
	return (0);
}
