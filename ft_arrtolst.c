/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arrtolst.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srheede <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/04 08:51:54 by srheede           #+#    #+#             */
/*   Updated: 2018/06/08 11:42:40 by srheede          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

t_list	*ft_arrtolst(char **arr)
{
	t_list	*list;
	t_list	*begin;
	int 	i;

	if (!arr)
		begin = ft_lstnew(NULL, 0);
	else
	{
		i = 0;
		list = ft_lstnew(arr[i], ft_strlen(arr[i]));
		begin = list;
		i++;
   		while (arr[i])
    	{
       		list->next = ft_lstnew(arr[i], ft_strlen(arr[i]));
        	list = list->next;
			i++;
		}
            list->next = ft_lstnew(arr[i], ft_strlen(arr[i]));
	}
	return (begin);
}
