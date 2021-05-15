/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtresa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/07 19:00:39 by gtresa            #+#    #+#             */
/*   Updated: 2020/11/08 21:23:08 by gtresa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void*))
{
	t_list *curlst;

	if (lst)
	{
		curlst = lst;
		while (curlst->next != NULL)
		{
			(*f)(curlst->content);
			curlst = curlst->next;
		}
		(*f)(curlst->content);
	}
}
