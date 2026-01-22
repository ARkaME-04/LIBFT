/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhrandri <rhrandri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 07:54:11 by rhrandri          #+#    #+#             */
/*   Updated: 2026/01/22 14:41:15 by rhrandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "libft.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stddef.h>

/*Allocates memory (using malloc(3)) and returns an
array of strings obtained by splitting ’s’ using
the character ’c’ as a delimiter. The array must
end with a NULL pointer*/

static int	word_count(char const *str, char c);
static char	*fill_word(const char *str, int start, int end);
static void	ft_free(char **strs, int count);
static void	ft_initiate_vars(size_t *i, int *j, int *s_word);

char	**ft_split(char const *s, char c)
{
	size_t	i;
	int		j;
	int		s_word;
	char	**res;

	if (!s)
		return (NULL);
	ft_initiate_vars(&i, &j, &s_word);
	res = calloc((word_count(s, c) + 1), sizeof(char *));
	if (!res)
		return (NULL);
	while (i <= strlen(s))
	{
		if (s[i] != c && s_word < 0)
			s_word = i;
		else if ((s[i] == c || i == strlen(s)) && s_word >= 0)
		{
			res[j] = fill_word(s, s_word, i);
			if (!(res[j]))
				return (ft_free(res, j), NULL);
			s_word = -1;
			j++;
		}
		i++;
	}
	return (res);
}

static int	word_count(char const *str, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (*str)
	{
		if (*str != c && i == 0)
		{
			i = 1;
			count ++;
		}
		else if (*str == c)
			i = 0;
		str++;
	}
	return (count);
}

static char	*fill_word(const char *str, int start, int end)
{
	int		i;
	char	*word;

	i = 0;
	word = malloc((end - start + 1) * sizeof(char));
	if (!word)
		return (NULL);
	while (start < end)
	{
		word[i] = str[start];
		i++;
		start++;
	}
	word[i] = '\0';
	return (word);
}

static void	ft_free(char **strs, int count)
{
	int	i;

	i = 0;
	while (i < count)
	{
		free(strs[i]);
		i++;
	}
	free(strs);
}

static void	ft_initiate_vars(size_t *i, int *j, int *s_word)
{
	*i = 0;
	*j = 0;
	*s_word = -1;
}
/*
int main(int ac, char **av)
{
	(void)ac;
	char	**sp = ft_split((const char *)av[1], ' ');
	int	i = 0;
	if (sp)
		while (sp[i])
		{
			printf("%s\n",sp[i]);
			free(sp[i]);
			i++;
		}
	else
		printf("NULL\n");
	free(sp);
	return (0);
}
*/
