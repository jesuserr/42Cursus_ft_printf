/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jesuserr <jesuserr@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 13:21:44 by jesuserr          #+#    #+#             */
/*   Updated: 2023/02/08 09:35:46 by jesuserr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_actions(char const p_holder, va_list arg)
{
	int	i;

	i = 0;
	if ((p_holder) == '%')
		return (ft_putchar('%'));
	else if (p_holder == 'c')
		return (ft_putchar(va_arg (arg, int)));
	else if (p_holder == 's')
		return (ft_putstr(va_arg (arg, char *)));
	else if (p_holder == 'd' || p_holder == 'i')
		return (ft_put_number(va_arg (arg, int), &i));
	else if (p_holder == 'u')
		return (ft_put_number(va_arg (arg, unsigned int), &i));
	else if (p_holder == 'x' || p_holder == 'X')
		return (ft_put_num_hex(va_arg (arg, unsigned int), p_holder, 0, &i));
	else if (p_holder == 'p')
		return (ft_put_num_hex(va_arg (arg, unsigned long long), 'x', 1, &i));
	return (i);
}

int	ft_printf(char const *p_holders, ...)
{
	va_list	args;
	int		i;
	int		j;

	i = 0;
	va_start (args, p_holders);
	while (*p_holders)
	{
		if (*p_holders != '%')
		{
			if (write (1, p_holders++, 1) != 1)
				return (-1);
			i++;
		}
		else
		{
			p_holders++;
			j = ft_actions (*p_holders++, args);
			if (j == -1)
				return (-1);
			i = i + j;
		}
	}	
	va_end (args);
	return (i);
}
