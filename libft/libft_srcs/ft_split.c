/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebrandt <benoit.brandt@proton.me>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 23:12:59 by bebrandt          #+#    #+#             */
/*   Updated: 2024/02/01 14:17:34 by bebrandt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static int	ft_count_word(char const *s, char c);
static void	ft_fill_strs(char **strs, char const *s, char c);
static void	ft_free_strs(char **strs, int len);

/*
Split 's' string according 'c' delimiter. allocate memory needed.
free memory in case of NULL allocation of a words.
ft_split("fffHellofffWorldffff", 'f') ==> [["Hello"], ["World"]]
*/
char	**ft_split(char const *s, char c)
{
	int		words;
	char	**str_str;

	words = ft_count_word(s, c);
	str_str = (char **)malloc((words + 1) * sizeof(char *));
	if (!str_str)
		return ((void *)0);
	ft_fill_strs(str_str, s, c);
	return (str_str);
}

/*
Count word in 's' string according to 'c' delimiter
if several delimiter next to each other, count only word.
ft_count_word("uuuhellouuuuworlduuu", 'u') ==> 2
*/
static int	ft_count_word(char const *s, char c)
{
	int	i;
	int	words;
	int	s_len;

	s_len = ft_strlen(s);
	i = 0;
	while (s[i] == c && s[i] != '\0')
		i++;
	words = 0;
	while (s[i])
	{
		if ((s[i] == c && s[i - 1] != c) || (i == s_len - 1 && s[i] != c))
			words++;
		i++;
	}
	return (words);
}

/*
Fill 'strs' tab with words from 's' delimited by 'c'
ft_fill_strs(allocate_strs, "fhelloffworldff", f) => [[hello], [world], [0]]
*/
static void	ft_fill_strs(char **strs, char const *s, char c)
{
	int	start;
	int	end;
	int	i_str;

	start = 0;
	i_str = 0;
	while (s[start])
	{
		if (s[start] != c)
		{
			end = start;
			while (s[end] != c && s[end] != '\0')
				end++;
			strs[i_str] = ft_substr(s, start, end - start);
			if (strs[i_str] == (void *)0)
				ft_free_strs(strs, i_str);
			i_str++;
			start = end - 1;
		}
		start++;
	}
	strs[i_str] = 0;
}

/*
If allocation memory problem occurs in the middle of strs tab.
ft_free_strs free all previous memory allocated in tab + free the tab.
*/
static void	ft_free_strs(char **strs, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		free(strs[i]);
		i++;
	}
	free(strs);
}
