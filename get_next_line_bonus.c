/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dan <dan@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 09:57:00 by dsylvain          #+#    #+#             */
/*   Updated: 2023/10/29 15:19:58 by dan              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

t_Data	*get_data(t_Data **head, int fd)
{
	t_Data	*current;

	current = *head;
	while (current)
	{
		if (current->fd == fd)
			return (current);
		current = current->next;
	}
	current = (t_Data *)malloc(sizeof(t_Data));
	if (!current)
		return (NULL);
	current->buff_nl = NULL;
	current->buffer = NULL;
	current->fd = fd;
	current->next = *head;
	*head = current;
	return (current);
}

char	*get_next_line(int fd)
{
	static t_Data	*head = NULL;
	t_Data			*data;
	char			*next_line;
	char			*tmp;

	data = get_data(&head, fd);
	if (!initialise_variables(&data))
		return (NULL);
	while (!(ft_strchr(data->buff_nl, '\n')) && data->bytes_read)
	{
		data->bytes_read = read(fd, data->buffer, BUFFER_SIZE);
		if (data->bytes_read == -1)
			return (delete_data(&head, fd));
		data->buffer[data->bytes_read] = '\0';
		expand_buff_ln(&data);
	}
	tmp = ft_strchr(data->buff_nl, '\n');
	next_line = build_next_line(&data, tmp, data->bytes_read);
	if (next_line)
		return (next_line);
	delete_data(&head, fd);
	return (NULL);
}

void	*delete_data(t_Data **head, int fd)
{
	t_Data	*current;
	t_Data	*node_to_delete;

	node_to_delete = NULL;
	current = *head;
	if (current->fd == fd)
	{
		*head = current->next;
		node_to_delete = current;
	}
	else
	{
		while (current->next)
		{
			if (current->next->fd == fd)
			{
				node_to_delete = current->next;
				current->next = current->next->next;
				break ;
			}
			current = current->next;
		}
	}
	delete_node(node_to_delete);
	return (NULL);
}

int	initialise_variables(t_Data **data)
{
	size_t			i;

	if (!(*data)->buff_nl)
	{
		(*data)->buff_nl = (char *)malloc((BUFFER_SIZE * 5) * sizeof(char));
		(*data)->buff_nl_size = BUFFER_SIZE * 5;
		i = 0;
		while (i < BUFFER_SIZE * 5)
			(*data)->buff_nl[i++] = '\0';
	}
	if (!(*data)->buffer)
	{
		i = 0;
		(*data)->buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
		while (i < BUFFER_SIZE + 1)
			((*data)->buffer)[i++] = '\0';
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

// int main(void)
// {
// 	int	fd1;
// 	int	fd2;
// 	// char *str;
// 	fd1 = open("text.txt", O_RDONLY);
// 	fd2 = open("text2.txt", O_RDONLY);
// 	printf("%s", get_next_line(fd1));
// 	printf("%s", get_next_line(fd2));
// 	printf("%s", get_next_line(fd1));
// 	printf("%s", get_next_line(fd2));
// 	printf("%s", get_next_line(fd1));
// 	printf("%s", get_next_line(fd2));
// 	printf("%s", get_next_line(fd1));
// 	printf("%s", get_next_line(fd2));
// 	printf("%s", get_next_line(fd1));
// 	printf("%s", get_next_line(fd2));
// 	printf("%s", get_next_line(fd1));
// 	printf("%s", get_next_line(fd2));
// 	printf("%s", get_next_line(fd1));
// 	printf("%s", get_next_line(fd2));
// 	printf("%s", get_next_line(fd1));
// 	printf("%s", get_next_line(fd2));
// 	printf("%s", get_next_line(fd1));
// 	printf("%s", get_next_line(fd2));
// 	// while (str = get_next_line(fd))
// 	// 	printf("%s", str);
// 	return(0);
// }