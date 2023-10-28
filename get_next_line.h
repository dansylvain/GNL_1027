/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsylvain <dsylvain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 04:58:59 by dsylvain          #+#    #+#             */
/*   Updated: 2023/10/28 06:22:51 by dsylvain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <unistd.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>

typedef struct t_Data
{
	char	*buff_nl;
	char	*buffer;
	int		bytes_read;
}	t_Data;

int	initialise_variables(t_Data **data);
char	*build_next_line(t_Data **data, char *tmp, int bytes_read);
void	*free_all(t_Data **data);
void	*ft_memset(void *s, int c, size_t n);
char	*get_next_line(int fd);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strdup(const char *s);
void	*ft_memmove(void *dest, const void *src, size_t n);
char	*ft_strndup(const char *s, size_t n);		
char	*ft_strchr(const char *s, int c);
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlen(const char *s);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);

#endif
