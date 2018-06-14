/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srheede <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/03 10:30:35 by srheede           #+#    #+#             */
/*   Updated: 2018/06/10 15:00:03 by srheede          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

t_list	*set_join(char *buffer, t_list *buffer_list)
{
	t_list *list;

	if (buffer[ft_strlen(buffer) - 1] != '\n' && buffer[0] != '\n')
	{
		list = buffer_list;
		while (buffer_list->next->content != NULL)
		{
			buffer_list = buffer_list->next;
			buffer_list->join = 1;
		}
		buffer_list->next->join = 1;
		buffer_list = list;
	}
	return (buffer_list);
}

t_list	*create_list(char *buffer, t_list *buffer_list)
{
	t_list	*list;
	char	**arr;

		if (!buffer_list)
		{
			arr = ft_strsplit(buffer, '\n');
			buffer_list = ft_arrtolst(arr);
			buffer_list = set_join(buffer, buffer_list);
		}
        else
        {
            list = buffer_list;
            while (buffer_list->next->content != NULL)
                buffer_list = buffer_list->next;
            buffer_list->next = ft_arrtolst(ft_strsplit(buffer, '\n'));
			buffer_list = set_join(buffer, buffer_list);
			if (buffer_list->join == 1 && buffer_list->next->content != NULL)
			{
            	buffer_list->content = ft_strjoin(buffer_list->content, buffer_list->next->content);
            	buffer_list->content_size += buffer_list->next->content_size;
            	buffer_list->next = buffer_list->next->next;
			}
            buffer_list = list;
			list = buffer_list;
		}		
		return (buffer_list);
}

int		get_next_line(const int fd, char **line)
{
    int					i;
	char				*buffer;
	char				**arr;
	static t_list		*buffer_list;

	buffer = ft_strnew(BUFF_SIZE);
    i = read(fd, buffer, BUFF_SIZE);
	if (fd < 0 || i == - 1 || line == NULL)
		return (-1);
	arr = ft_strsplit(buffer, '\n');
	if (ft_strlen(arr[0]) == ft_strlen(buffer))
		*line = buffer; 
	else
	{
		buffer_list = create_list(buffer, buffer_list);
		*line = ft_strndup(buffer_list->content, buffer_list->content_size);
	}
	if (*line == NULL)
		return (0);
	buffer_list = buffer_list->next;
	return (1);
}


