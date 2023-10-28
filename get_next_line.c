/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsylvain <dsylvain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 09:57:00 by dsylvain          #+#    #+#             */
/*   Updated: 2023/10/28 06:35:17 by dsylvain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static t_Data	*data = NULL;
	char			*next_line;
	char			*tmp;

	initialise_variables(&data);
	while (!(ft_strchr(data->buff_nl, '\n')) && data->bytes_read)
	{
		data->bytes_read = read(fd, data->buffer, BUFFER_SIZE);
		if (data->bytes_read == -1)
			return (free_all(&data));
		data->buffer[data->bytes_read] = '\0';
		tmp = data->buff_nl;
		data->buff_nl = ft_strjoin(data->buff_nl, data->buffer);
		free(tmp);
	}
	tmp = ft_strchr(data->buff_nl, '\n');
	next_line = build_next_line(&data, tmp, data->bytes_read);
	if (next_line)
		return (next_line);
	free_all(&data);
	return (NULL);
}


int	initialise_variables(t_Data **data)
{
	if (!*data)
	{
		*data = (t_Data *)malloc(sizeof(t_Data));
		(*data)->buff_nl = NULL;
		(*data)->buffer = NULL;
	}
	if (!(*data)->buff_nl)
	{
		(*data)->buff_nl = (char *)malloc(1);
		(*data)->buff_nl[0] = '\0';
	}
	if (!(*data)->buffer)
	{
		(*data)->buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
		ft_memset((*data)->buffer, '\0', BUFFER_SIZE + 1);
		(*data)->buff_nl[0] = '\0';
	}
	if (!*data || !(*data)->buff_nl)
		return (0);
	(*data)->bytes_read = 1;
	return (1);
}

char	*build_next_line(t_Data **data, char *tmp, int bytes_read)
{
	char	*next_line;

	if (ft_strchr((*data)->buff_nl, '\n'))
	{
		next_line = ft_substr((*data)->buff_nl, 0, tmp - (*data)->buff_nl + 1);
		ft_strlcpy((*data)->buff_nl, tmp + 1, ft_strlen(tmp));
		return (next_line);
	}
	else if (bytes_read == 0 && *(*data)->buff_nl)
	{
		next_line = ft_substr((*data)->buff_nl, 0, ft_strlen((*data)->buff_nl));
		*(*data)->buff_nl = '\0';
		return (next_line);
	}
	return (NULL);
}

void	*free_all(t_Data **data)
{
	free((*data)->buff_nl);
	free((*data)->buffer);
	(*data)->buff_nl = NULL;
	(*data)->buffer = NULL;
	free(*data);
	*data = NULL;
	return (NULL);
}

void	*ft_memset(void *s, int c, size_t n)
{
	size_t			i;

	i = 0;
	while (i < n)
		((unsigned char *)s)[i++] = (unsigned char)c;
	return (s);
}

// GERER RETOUR DE READ = -1
int main(void)
{
	int	fd;
	char *str;

	fd = open("text2.txt", O_RDONLY);
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	while (str = get_next_line(fd))
		printf("%s", str);
	return(0);
}