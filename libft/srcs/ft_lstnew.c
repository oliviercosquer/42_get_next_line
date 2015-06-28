/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olivier <olivier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/28 14:34:45 by olivier           #+#    #+#             */
/*   Updated: 2015/06/28 14:59:49 by olivier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*new_elem;

	new_elem = (t_list *)(malloc(sizeof(t_list)));

	if (new_elem)
	{
		new_elem->content_size = content_size;
		new_elem->content = (void *)malloc(content_size);
		if (new_elem->content && content)
			ft_memcpy(new_elem->content, content, content_size);
		(void)content;
		new_elem->next = NULL;
	}
	return (new_elem);
}