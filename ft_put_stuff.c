/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_stuff.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jesuserr <jesuserr@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 11:45:19 by jesuserr          #+#    #+#             */
/*   Updated: 2023/02/08 09:36:08 by jesuserr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(int c)
{
	if (write (1, &c, 1) != 1)
		return (-1);
	return (1);
}

int	ft_putstr(char *s)
{
	int	i;

	i = 0;
	if (!s)
	{
		if (write (1, "(null)", 6) != 6)
			return (-1);
		return (6);
	}
	while (*s)
	{
		if (write (1, s++, 1) != 1)
			return (-1);
		i++;
	}
	return (i);
}

int	ft_put_number(long long n, int *i)
{
	if (n < 0)
	{
		if (write (1, "-", 1) != 1)
			return (-1);
		(*i)++;
		n = -n;
	}
	if (n >= 10)
	{
		ft_put_number(n / 10, i);
		if (*i == -1)
			return (-1);
		ft_put_number(n % 10, i);
	}
	else
	{
		n = n + 48;
		if (write (1, &n, 1) != 1)
			*i = -2;
		(*i)++;
	}
	return (*i);
}

int	ft_put_num_hex(unsigned long long n, char p_holder, int ptr, int *i)
{
	if (ptr == 1)
	{
		if (ft_putstr (POINTER) != 2)
			return (-1);
		*i = *i + 2;
	}
	if (n >= 16)
	{
		ft_put_num_hex(n / 16, p_holder, 0, i);
		if (*i == -1)
			return (-1);
		ft_put_num_hex(n % 16, p_holder, 0, i);
	}
	else
	{
		if (p_holder == 'x')
			if (write (1, &(HEX_LOWER[n]), 1) != 1)
				*i = -2;
		if (p_holder == 'X')
			if (write (1, &(HEX_UPPER[n]), 1) != 1)
				*i = -2;
		(*i)++;
	}
	return (*i);
}
