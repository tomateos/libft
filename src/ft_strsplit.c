/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzhou <tzhou@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 16:21:56 by tzhou             #+#    #+#             */
/*   Updated: 2017/08/01 21:08:51 by tzhou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Allocates an array of strings created by splitting string s with delimiter c.
*/

static void	free_words(char **words)
{
	int	i;

	i = 0;
	while (words[i])
		free(words[i++]);
	free(words);
}

static int	get_word_count(char const *s, char c)
{
	int	count;

	if (!s)
		return (-1);
	count = 0;
	while (*s)
	{
		if (*s == c)
			s++;
		else
		{
			count++;
			while (*s != c && *s)
				s++;
		}
	}
	return (count);
}

static int	get_word_len(char const *s, char c)
{
	int	len;

	len = 0;
	while (*s != c && *s)
	{
		s++;
		len++;
	}
	return (len);
}

static char	*get_word(char const *s, char c)
{
	char	*word;
	int		i;

	if (!(word = (char*)malloc(sizeof(char) * (get_word_len(s, c) + 1))))
		return (NULL);
	i = 0;
	while (*s != c && *s)
		word[i++] = *(s++);
	word[i] = 0;
	return (word);
}

char		**ft_strsplit(char const *s, char c)
{
	int		count;
	char	**words;
	int		i;

	count = get_word_count(s, c);
	if (count < 0 || !(words = (char**)malloc(sizeof(char*) * (count + 1))))
		return (NULL);
	i = 0;
	while (i <= count && *s)
	{
		if (*s == c)
			s++;
		else
		{
			if (!(words[i++] = get_word(s, c)))
			{
				free_words(words);
				return (NULL);
			}
			while (*s != c && *s)
				s++;
		}
	}
	words[i] = 0;
	return (words);
}
