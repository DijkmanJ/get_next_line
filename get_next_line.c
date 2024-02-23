/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: jdijkman <jdijkman@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/11/27 16:53:53 by jdijkman      #+#    #+#                 */
/*   Updated: 2024/02/20 18:38:24 by jdijkman      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_firstline(char *totalstring, char *firstline)
{
	if (ft_ncheck(totalstring) > 0)
		firstline = ft_strncpy(totalstring, ft_ncheck(totalstring) + 1, 1);
	else
	{
		if (totalstring == NULL)
			return (NULL);
		if (ft_ncheck(totalstring) == 0)
			firstline = ft_strncpy("\n", 1, 0);
		else
			firstline = ft_strncpy(totalstring, ft_strlen(totalstring) + 1, 0);
	}
	return (firstline);
}

static char	*ft_totalstring(char *totalstring, char *buffer, int fd)
{
	int	check;

	check = -1;
	while (ft_ncheck(totalstring) == -2 && check != 0)
	{
		check = read(fd, buffer, BUFFER_SIZE);
		if (check == -1)
		{
			free(buffer);
			free(totalstring);
			totalstring = NULL;
			return (NULL);
		}
		if (check == 0)
			break ;
		buffer[check] = '\0';
		totalstring = ft_strjoin(totalstring, buffer);
	}
	free(buffer);
	return (totalstring);
}

char	*get_next_line(int fd)
{
	char		*buffer;
	char		*firstline;
	static char	*totalstring;

	firstline = NULL;
	buffer = (char *)malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	if (ft_ncheck(totalstring) == -1)
	{
		free(buffer);
		free(totalstring);
		totalstring = NULL;
		return (firstline = ft_strncpy("\n", 1, 0));
	}
	totalstring = ft_totalstring(totalstring, buffer, fd);
	firstline = ft_firstline(totalstring, firstline);
	totalstring = ft_freedeel(totalstring);
	return (firstline);
}
// int main(void)
// {
// 	int fd;
// 	int i = 5;
// 	fd = open("file.txt", O_RDONLY);
// 	// printf("FD  = %d\n", fd);
// 	while (i > 0)
// 	{
// 		// get_next_line(fd);
// 		printf("%s", get_next_line(fd));
// 		i --;
// 	}	
// }
