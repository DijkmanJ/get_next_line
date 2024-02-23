/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line_utils.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: jdijkman <jdijkman@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/12/18 17:38:19 by jdijkman      #+#    #+#                 */
/*   Updated: 2023/12/18 17:52:35 by jdijkman      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
		i ++;
	return (i);
}

int	ft_ncheck(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (-2);
	if (str[0] == '\n' && !str[1])
		return (-1);
	while (str[i] != '\0')
	{
		if (str[i] == '\n')
			return (i);
		i ++;
	}
	return (-2);
}

char	*ft_strncpy(char *str, int n, int j)
{
	int		i;
	char	*rtn;

	i = 0;
	if (j == 0)
		rtn = (char *)malloc(ft_strlen(str) + 1);
	if (j == 1)
		rtn = (char *)malloc(ft_ncheck(str) + 2);
	if (!rtn)
		return (NULL);
	if (str[0] == '\0')
	{
		free(rtn);
		return (NULL);
	}
	while (str[i] != '\0' && i < n)
	{
		rtn[i] = str[i];
		i ++;
	}
	rtn[i] = '\0';
	return (rtn);
}

char	*ft_strjoin(char *str1, char *str2)
{
	int		i;
	int		len;
	int		len2;
	char	*str;

	i = -1;
	if (!str1)
	{
		str1 = (char *)malloc(1);
		str1[0] = '\0';
	}
	len = ft_strlen(str1);
	len2 = ft_strlen(str2);
	str = (char *) malloc (len + len2 + 1);
	if (!str)
		return (NULL);
	while (str1[++i] != '\0')
		str[i] = str1[i];
	i = -1;
	while (str2[++i] != '\0')
		str[len + i] = str2[i];
	str[len + i] = '\0';
	free(str1);
	return (str);
}

char	*ft_freedeel(char *str)
{
	int		i;
	int		strlen;
	char	*new;

	i = 0;
	if (!str)
	{
		new = NULL;
		return (NULL);
	}
	strlen = ft_strlen(str);
	while (str[i] != '\n' && str[i] != '\0')
		i ++;
	if (!str[i])
	{
		free(str);
		new = NULL;
		return (NULL);
	}
	i ++;
	new = ft_strncpy(str + i, strlen - i, 0);
	free(str);
	return (new);
}
