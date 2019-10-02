/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrella <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 00:31:30 by mbrella           #+#    #+#             */
/*   Updated: 2019/09/10 20:43:21 by mbrella          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	void	*alldel(char **mas)
{
	while (*mas)
	{
		free(*mas);
		mas++;
	}
	free(mas);
	return (NULL);
}

char			**ft_strsplit(char const *s, char c)
{
	char				**mas;
	unsigned int		i;
	unsigned int		cn;

	i = 0;
	cn = 0;
	if (!s || !c)
		return (NULL);
	if (!(mas = (char **)malloc(sizeof(char *) * ft_count_words(s, c) + 1)))
		return (NULL);
	while (s[cn])
	{
		while (ft_isdelim(s[cn], c) && s[cn])
			cn++;
		if (s[cn] != '\0')
			if (!(mas[i] = ft_strsep((char*)(s + cn), (const char)c)))
				return (alldel(mas));
		if (s[cn] == '\0')
			i--;
		while (!ft_isdelim(s[cn], c) && s[cn])
			cn++;
		i++;
	}
	mas[i] = NULL;
	return (mas);
}
