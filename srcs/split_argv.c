/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_argv.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubuntu <ubuntu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 18:19:02 by pbret             #+#    #+#             */
/*   Updated: 2024/11/04 16:12:14 by ubuntu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_strncpy(char *str1, char *str2, int nb)
{
	int	i;

	i = 0;
	while (i < nb && str2[i])
	{
		str1[i] = str2[i];
		i++;
	}
	str1[i] = '\0';
	return ;
}

int	ft_count_words(char *str)
{
	int		i;
	int		word;
	int		flag;

	i = 0;
	word = 0;
	flag = 0;
	while (str[i])
	{
		while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n')
			i++;
		while (str[i] != ' ' && str[i] != '\t' && str[i] != '\n' && str[i])
		{
			flag = 1;
			i++;
		}
		if (flag == 1)
		{
			flag = 0;
			word += 1;
		}
	}
	return (word);
}

char	**ft_initialisation_tab(char **tab, char *str)
{
	int		i;
	int		start;
	int		j;

	i = 0;
	j = 0;
	start = 0;
	while (str[i])
	{
		while (str[i] && (str[i] == ' ' || str[i] == '\t' || str[i] == '\n'))
			i++;
		start = i;
		while (str[i] && (str[i] != ' ' && str[i] != '\t' && str[i] != '\n'))
			i++;
		if (i > start)
		{
			tab[j] = malloc(sizeof(char) * (i - start + 1));
			ft_strncpy(tab[j], &str[start], (i - start));
			j++;
		}
	}
	tab[j] = NULL;
	return (tab);
}

char	**ft_split_argv(char *str)
{
	char	**tab;
	int		nb_words;

	nb_words = ft_count_words(str);
	tab = malloc(sizeof(char *) * (nb_words + 1));
	if (!tab)
		return (NULL);
	ft_initialisation_tab(tab, str);
	return (tab);
}

/* int	main(int ac, char ** av)
{
	char	**tab;
	int		i;

	i = 0;
	tab = NULL;
	if(ac == 2)
	{
		tab = ft_split1(av[1]);
		if (!tab)
			return (1);
		while (tab[i])
		{
			printf("%s\n", tab[i]);
			i++;
		}
	}
	i = 0;
	if (tab != NULL)
	{
		while (tab[i])
			free(tab[i++]);
		free(tab);
	}

	return (0);
}*/