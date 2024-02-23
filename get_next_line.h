/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.h                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: jdijkman <jdijkman@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/11/27 16:56:19 by jdijkman      #+#    #+#                 */
/*   Updated: 2023/12/18 17:54:52 by jdijkman      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif
# include <unistd.h>
# include <stdlib.h>
# include "get_next_line.h"

char		*get_next_line(int fd);
size_t		ft_strlen(const char *s);
int			ft_ncheck(char *str);
char		*ft_strncpy(char *str, int n, int j);
char		*ft_strjoin(char *str1, char *str2);
char		*ft_freedeel(char *str);

#endif
