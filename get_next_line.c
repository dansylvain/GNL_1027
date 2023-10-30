/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsylvain <dsylvain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 09:57:00 by dsylvain          #+#    #+#             */
/*   Updated: 2023/10/30 08:08:32 by dsylvain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static t_Data	*data = NULL;
	char			*next_line;
	char			*tmp;

	if (!initialise_variables(&data))
		return (NULL);
	while (!(ft_strchr(data->buff_nl, '\n')) && data->bytes_read)
	{
		data->bytes_read = read(fd, data->buffer, BUFFER_SIZE);
		if (data->bytes_read == -1)
		{
			delete_data(&data);
			return (NULL);
		}
		data->buffer[data->bytes_read] = '\0';
		tmp = data->buff_nl;
		data->buff_nl = ft_strjoin(data->buff_nl, data->buffer);
		free(tmp);
	}
	tmp = ft_strchr(data->buff_nl, '\n');
	next_line = build_next_line(&data, tmp, data->bytes_read);
	if (next_line)
		return (next_line);
	delete_data(&data);
	return (NULL);
}

int	initialise_variables(t_Data **data)
{
	size_t			i;

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
		i = 0;
		(*data)->buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
		while (i < BUFFER_SIZE + 1)
			((*data)->buffer)[i++] = '\0';
		(*data)->buff_nl[0] = '\0';
	}
	if (!*data || !(*data)->buff_nl || !(*data)->buffer)
		return (0);
	(*data)->bytes_read = 1;
	return (1);
}

char	*build_next_line(t_Data **data, char *tmp, int bytes_read)
{
	char	*next_line;
	size_t	i;

	if (tmp)
	{
		next_line = ft_substr((*data)->buff_nl, 0, tmp - (*data)->buff_nl + 1);
		i = 0;
		while (i < ft_strlen(tmp) - 1 && (tmp + 1)[i] != '\0')
		{
			((*data)->buff_nl)[i] = (tmp + 1)[i];
			i++;
		}
		((*data)->buff_nl)[i] = '\0';
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

void	delete_data(t_Data **data)
{
	free((*data)->buff_nl);
	free((*data)->buffer);
	(*data)->buff_nl = NULL;
	(*data)->buffer = NULL;
	free(*data);
	*data = NULL;
}

// #include <unistd.h>
// int main(void)
// {
// 	int	fd;
// 	char *str;
// 	str = "";
// 	fd = open("text2.txt", O_RDONLY);
// 	while(str)
// 	{
// 		str = get_next_line(fd);
// 		if (str)
// 			write(1, &*str, ft_strlen(str));
// 	}
// 	fd = open("text.txt", O_RDONLY);
// 	str = "";
// 	while(str)
// 	{
// 		str = get_next_line(fd);
// 		if (str)
// 			write(1, &*str, ft_strlen(str));
// 	}
// 	return(0);
// }