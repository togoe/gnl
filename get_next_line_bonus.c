/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctogoe <ctogoe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/15 13:46:20 by ctogoe            #+#    #+#             */
/*   Updated: 2021/04/30 21:38:48 by ctogoe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int		find_n(const char *stock, int c)
{
	int	i;

	i = 0;
	while (stock[i] && stock[i] != c)
		i++;
	if (stock[i] == c)
		return (i);
	return (-1);
}

char	*ft_line(char *stock, char **line, int i)
{
	char	*tmp;

	stock[i] = '\0';
	*line = ft_strdup(stock);
	tmp = ft_strdup(stock + i + 1);
	free(stock);
	stock = tmp;
	return (stock);
}

char	*ft_line_end(char *stock, char **line, int i, int ret)
{
	if (ret == 0 && i != -1)
	{
		stock = ft_line(stock, line, i);
		return (stock);
	}
	else if (ret == 0)
	{
		*line = ft_strdup(stock);
		free(stock);
		return (stock);
	}
	free(stock);
	return (stock);
}

int		get_next_line(int fd, char **line)
{
	static char	*stock[1024];
	char		buf[BUFFER_SIZE + 1];
	int			ret;
	int			i;

	i = 0;
	if (fd < 0 || !line || BUFFER_SIZE < 1 || read(fd, buf, 0) < 0)
		return (-1);
	while ((ret = read(fd, buf, BUFFER_SIZE)) > 0 || i != -1)
	{
		buf[ret] = '\0';
		stock[fd] = ft_strjoin(stock[fd], buf);
		i = find_n(stock[fd], '\n');
		if (i != -1)
		{
			stock[fd] = ft_line(stock[fd], line, i);
			return (1);
		}
	}
	stock[fd] = ft_line_end(stock[fd], line, i, ret);
	if (ret == 0 && i != -1)
		return (1);
	else if (ret == 0)
		return (0);
	return (-1);
}
