/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctogoe <ctogoe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 12:53:53 by ctogoe            #+#    #+#             */
/*   Updated: 2021/04/28 16:59:12 by ctogoe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(const char *s)
{
	size_t		i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strdup(const char *s1)
{
	char	*copy;
	int		i;
	int		len;

	len = ft_strlen(s1);
	copy = (char *)malloc(sizeof(char) * (len + 1));
	if (!copy)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		copy[i] = s1[i];
		i++;
	}
	copy[i] = '\0';
	return (copy);
}

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	i;
	size_t	j;
	size_t	lens1;
	char	*new_s;

	if (!s1)
		lens1 = 0;
	else
		lens1 = ft_strlen(s1);
	i = -1;
	j = 0;
	if (!(new_s = malloc(sizeof(char) * (lens1 + ft_strlen(s2) + 1))))
		return (NULL);
	while (++i < lens1)
		new_s[i] = s1[i];
	while (j < ft_strlen(s2))
	{
		new_s[i + j] = s2[j];
		j++;
	}
	new_s[i + j] = '\0';
	free(s1);
	return (new_s);
}
