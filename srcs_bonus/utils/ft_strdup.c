/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amery <amery@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 12:26:33 by amery             #+#    #+#             */
/*   Updated: 2023/03/20 17:06:49 by amery            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_utils.h"

char	*ft_strdup(const char *s1)
{
	char	*cpy;

	cpy = malloc(sizeof(char) * (ft_strlen(s1) + 1));
	if (cpy == 0)
		return (0);
	ft_strlcpy(cpy, s1, ft_strlen(s1) + 1);
	return (cpy);
}
