/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dan <dan@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 04:58:59 by dsylvain          #+#    #+#             */
/*   Updated: 2023/10/29 11:22:26 by dan              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H
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
	char			*buff_nl;
	char			*buffer;
	int				bytes_read;
	int				fd;
	struct t_Data	*next;
}	t_Data;

void	delete_node(t_Data *node_to_delete);
int		initialise_variables(t_Data **data);
char	*build_next_line(t_Data **data, char *tmp, int bytes_read);
void	*delete_data(t_Data **data, int fd);
char	*get_next_line(int fd);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strdup(const char *s);
void	*ft_memmove(void *dest, const void *src, size_t n);
char	*ft_strndup(const char *s, size_t n);		
char	*ft_strchr(const char *s, int c);
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlen(const char *s);

#endif
