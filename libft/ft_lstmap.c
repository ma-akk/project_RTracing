/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtresa <gtresa@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 16:57:30 by gtresa            #+#    #+#             */
/*   Updated: 2020/11/10 22:08:41 by gtresa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void*), void (*del)(void*))
{
	t_list	*lstnew;
	t_list	*fstlst;

	if (lst == NULL)
		return (NULL);
	fstlst = NULL;
	while (lst)
	{
		lstnew = ft_lstnew(f(lst->content));
		if (lstnew == NULL)
		{
			ft_lstclear(&fstlst, del);
			return (NULL);
		}
		ft_lstadd_back(&fstlst, lstnew);
		lst = lst->next;
	}
	return (fstlst);
}
