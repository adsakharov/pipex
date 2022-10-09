/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arupert <arupert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 00:44:33 by arupert           #+#    #+#             */
/*   Updated: 2022/04/04 04:35:21 by arupert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static size_t	ft_strlen(const char *s)
{
	size_t	l;

	l = 0;
	while (*(s + l) != '\0')
		l++;
	return (l);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*str1;
	unsigned char	*str2;

	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	if (n == 0)
		return (0);
	if (*str1 == '\0' || *str2 == '\0')
		return (*str1 - *str2);
	i = 0;
	while (n > i && (*(str1 + i) != '\0' && *(str2 + i) != '\0'))
	{
		if (*(str1 + i) == *(str2 + i))
			i++;
		else
			return (*(str1 + i) - *(str2 + i));
	}
	if (i == n)
		return (0);
	return (*(str1 + i) - *(str2 + i));
}

char	*ft_slash_strjoin(char const *s1, char const *s2)
{
	char	*s;
	size_t	j;
	size_t	i;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	s = malloc(sizeof(char) * (ft_strlen(s1) + (ft_strlen(s2) + 2)));
	if (s == NULL)
		return (NULL);
	i = 0;
	while (*(s1 + i) != '\0')
	{
		*(s + i) = *(s1 + i);
		i++;
	}
	*(s + i) = '/';
	j = 0;
	while (*(s2 + j) != '\0')
	{
		*(s + i + 1 + j) = *(s2 + j);
		j++;
	}
	*(s + i + 1 + j) = '\0';
	return (s);
}
