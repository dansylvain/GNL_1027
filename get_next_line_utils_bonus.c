/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dan <dan@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 10:00:32 by dan               #+#    #+#             */
/*   Updated: 2023/10/29 15:44:08 by dan              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

void	expand_buff_ln(t_Data **data)
{
	char	*tmp;
	size_t	i;
	size_t	j;

	tmp = NULL;
	i = 0;
	if (((*data)->buff_nl_size - ft_strlen((*data)->buff_nl) < BUFFER_SIZE + 1))
	{
		tmp = (*data)->buff_nl;
		(*data)->buff_nl = (char *)malloc((*data)->buff_nl_size * 2);
		(*data)->buff_nl_size *= 2;
		while (tmp[i])
		{
			(*data)->buff_nl[i] = tmp[i];
			i++;
		}
		free(tmp);
	}
	if (!i)
		i = ft_strlen((*data)->buff_nl);
	j = 0;
	while (j < ft_strlen((*data)->buffer))
		(*data)->buff_nl[i++] = (*data)->buffer[j++];
	while (i < (size_t)(*data)->buff_nl_size)
		(*data)->buff_nl[i++] = '\0';
}

void	delete_node(t_Data *node_to_delete)
{
	if (node_to_delete)
	{
		free(node_to_delete->buff_nl);
		free(node_to_delete->buffer);
		node_to_delete->buff_nl = NULL;
		node_to_delete->buffer = NULL;
		free(node_to_delete);
		node_to_delete = NULL;
	}
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	i;

	if ((start + len) > ft_strlen(s))
		substr = (char *)malloc(sizeof(char) * (ft_strlen(s) - start + 1));
	else
		substr = (char *)malloc(sizeof(char) * len + 1);
	if (substr == NULL)
		return (NULL);
	i = 0;
	while (i < len && s[start + i])
	{
		substr[i] = s[start + i];
		i++;
	}
	substr[i] = '\0';
	return (substr);
}

char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)(s));
		s++;
	}
	if ((char)c == '\0')
		return ((char *)(s));
	return (NULL);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}
