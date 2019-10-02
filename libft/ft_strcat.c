/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrella <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/03 18:04:48 by mbrella           #+#    #+#             */
/*   Updated: 2019/09/05 19:53:41 by mbrella          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcat(char *s1, const char *s2)
{
	unsigned int slen1;
	unsigned int slen2;

	slen1 = 0;
	slen2 = 0;
	while (s1[slen1])
		slen1++;
	while (s2[slen2])
	{
		s1[slen1] = s2[slen2];
		slen1++;
		slen2++;
	}
	s1[slen1] = '\0';
	return (s1);
}
