/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctogoe <ctogoe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 13:36:52 by ctogoe            #+#    #+#             */
/*   Updated: 2021/05/01 21:12:06 by ctogoe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>

int						find_n(const char *stock, int c);
int						get_next_line(int fd, char **line);
size_t					ft_strlen(const char *s);
char					*ft_strjoin(char *s1, char *s2);
char					*ft_strdup(const char *s1);
char					*ft_line_end(char *stock, char **line, int i, int ret);
char					*ft_line(char *stock, char **line, int i);

#endif
