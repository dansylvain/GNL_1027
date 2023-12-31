/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsylvain <dsylvain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 04:58:59 by dsylvain          #+#    #+#             */
/*   Updated: 2023/10/30 09:02:19 by dsylvain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>

typedef struct t_Data
{
	char			*buff_nl;
	char			*buffer;
	int				bytes_read;
	int				buff_nl_size;
	int				fd;
	struct t_Data	*next;
}	t_Data;

char	*get_next_line(int fd);
void	initialise_structure(t_Data **data);
int		initialise_variables(t_Data **data);
void	*expand_buff_nl(t_Data **data);
char	*build_next_line(t_Data **data, char *tmp, int bytes_read);
void	*delete_data(t_Data **data);
char	*get_next_line(int fd);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strchr(const char *s, int c);
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlen(const char *s);

#endif
