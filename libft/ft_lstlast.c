/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtresa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/07 18:19:59 by gtresa            #+#    #+#             */
/*   Updated: 2020/11/08 22:11:01 by gtresa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	int i;

	i = 0;
	if (!lst)
		return (NULL);
	while (lst->next != NULL)
	{
		lst = lst->next;
		i++;
	}
	return (lst);
}
