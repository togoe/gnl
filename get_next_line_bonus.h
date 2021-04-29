/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctogoe <ctogoe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 13:36:52 by ctogoe            #+#    #+#             */
/*   Updated: 2021/04/28 16:56:09 by ctogoe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>

char					*ft_line_end(char *stock, char **line, int i, int ret);
char					*ft_line(char *stock, char **line, int i);
int						find_n(const char *stock, int c);
int						get_next_line(int fd, char **line);
size_t					ft_strlen(const char *s);
char					*ft_strjoin(char *s1, char *s2);
char					*ft_strdup(const char *s1);

#endif
