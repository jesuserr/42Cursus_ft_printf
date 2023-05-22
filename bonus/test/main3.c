#include <stdio.h>		// para el printf, quitar
#include <stdlib.h>		// para el malloc, quitar
#include <unistd.h>
#include <stdarg.h>
#include "ft_printf_bonus.h"
#include <limits.h>

// # define HEX_LOWER		"0123456789abcdef"
// # define HEX_UPPER		"0123456789ABCDEF"
// # define POINTER_LOW	"0x"
// # define POINTER_UPP	"0X"


// int	ft_putchar(int c)
// {
// 	if (write (1, &c, 1) != 1)
// 		return (-1);
// 	return (1);
// }

// int	ft_putstr(char *s)
// {
// 	int	i;

// 	i = 0;
// 	if (!s)
// 	{
// 		if (write (1, "(null)", 6) != 6)
// 			return (-1);
// 		return (6);
// 	}
// 	while (*s)
// 	{
// 		if (write (1, s++, 1) != 1)
// 			return (-1);
// 		i++;
// 	}
// 	return (i);
// }

// int	ft_put_number(long long n, int *i, char p_holder)
// {
// 	if ((p_holder == '+' || p_holder == ' ') && n >= 0)
// 	{
// 		if (write (1, &p_holder, 1) != 1)
// 			return (-1);
// 		(*i)++;
// 	}	
// 	if (n < 0)
// 	{
// 		if (write (1, "-", 1) != 1)
// 			return (-1);
// 		(*i)++;
// 		n = -n;
// 	}
// 	if (n >= 10)
// 	{
// 		ft_put_number(n / 10, i, 0);
// 		if (*i == -1)
// 			return (-1);
// 		ft_put_number(n % 10, i, 0);
// 	}
// 	else
// 	{
// 		n = n + 48;
// 		if (write (1, &n, 1) != 1)
// 			*i = -2;
// 		(*i)++;
// 	}
// 	return (*i);
// }

// int	ft_put_num_hex(unsigned long long n, char p_holder, int ptr, int *i)
// {
// 	if (ptr == 1 && p_holder == 'p')
// 	{
// 		if (ft_putstr (POINTER_LOW) != 2)
// 			return (-1);
// 		*i = *i + 2;
// 	}
// 	if (ptr == 1 && p_holder == 'x' && n > 0)
// 	{
// 		if (ft_putstr (POINTER_LOW) != 2)
// 			return (-1);
// 		*i = *i + 2;
// 	}
// 	if (ptr == 1 && p_holder == 'X' && n > 0)
// 	{
// 		if (ft_putstr (POINTER_UPP) != 2)
// 			return (-1);
// 		*i = *i + 2;
// 	}	
// 	if (n >= 16)
// 	{
// 		ft_put_num_hex(n / 16, p_holder, 0, i);
// 		if (*i == -1)
// 			return (-1);
// 		ft_put_num_hex(n % 16, p_holder, 0, i);
// 	}
// 	else
// 	{
// 		if (p_holder == 'x' || p_holder == 'p')
// 			if (write (1, &(HEX_LOWER[n]), 1) != 1)
// 				*i = -2;
// 		if (p_holder == 'X')
// 			if (write (1, &(HEX_UPPER[n]), 1) != 1)
// 				*i = -2;
// 		(*i)++;
// 	}
// 	return (*i);
// }


// int	ft_actions(char const *p_holder, va_list arg)
// {
// 	int	i;

// 	i = 0;
// 	if ((*p_holder) == '%')
// 		return (ft_putchar('%'));
// 	else if (*p_holder == 'c')
// 		return (ft_putchar(va_arg (arg, int)));
// 	else if (*p_holder == 's' || (*p_holder == ' ' && *(p_holder + 1) == 's'))
// 		return (ft_putstr(va_arg (arg, char *)));
// 	else if (*p_holder == 'd' || *p_holder == 'i')
// 		return (ft_put_number(va_arg (arg, int), &i, 0));
// 	else if ((*p_holder == '+' || *p_holder == ' ')
// 		&& (*(p_holder + 1) == 'd' || *(p_holder + 1) == 'i'))
// 		return (ft_put_number(va_arg (arg, int), &i, *p_holder));
// 	else if (*p_holder == 'u')
// 		return (ft_put_number(va_arg (arg, unsigned int), &i, 0));
// 	else if (*p_holder == 'x' || *p_holder == 'X')
// 		return (ft_put_num_hex(va_arg (arg, unsigned int), *p_holder, 0, &i));
// 	else if (*p_holder == 'p')
// 		return (ft_put_num_hex(va_arg (arg, unsigned long long), *p_holder, 1, &i));
// 	else if (*p_holder == '#' && (*(p_holder + 1) == 'X' || *(p_holder + 1) == 'x'))
// 		return (ft_put_num_hex(va_arg (arg, unsigned int), *(p_holder + 1), 1, &i));
// 	return (i);
// }

// int	ft_printf(char const *p_holders, ...)
// {
// 	va_list	args;
// 	int		i;
// 	int		j;

// 	i = 0;
// 	va_start (args, p_holders);
// 	while (*p_holders)
// 	{
// 		if (*p_holders != '%')
// 		{
// 			if (write (1, p_holders++, 1) != 1)
// 				return (-1);
// 			i++;
// 		}
// 		else
// 		{
// 			p_holders++;
// 			j = ft_actions (p_holders++, args);
// 			if (*(p_holders - 1) == '#' || *(p_holders - 1) == '+' || *(p_holders - 1) == ' ')
// 				p_holders++;			
// 			if (j == -1)
// 				return (-1);
// 			i = i + j;
// 		}
// 	}	
// 	va_end (args);
// 	return (i);
// }

int	main(void)
{
	//int	i;
	void	*ptr;
	
	ptr = malloc (100);
	printf("% d, % d, % d, % d, % d, % d, % d, % d\n", 0, 5, -1, -10, 100, -1862, INT_MIN, INT_MAX);
	ft_printf("% d, % d, % d, % d, % d, % d, % d, % d\n", 0, 5, -1, -10, 100, -1862, INT_MIN, INT_MAX);
	// printf ("%p\n", ptr);
	// ft_printf ("%p\n", ptr);
	//printf ("%d\n", -1234);
	//printf ("%i\n", -1234);
	//ft_printf ("%i\n", -1234);
	//printf ("%d\n", ft_printf ("%i\n", -1234));
	//ft_printf ("%#x\n", 255);
	//ft_printf ("%#X\n", 255);
	// printf ("% d\n", +120);
	// printf ("% i\n", +120);
	// ft_printf ("% d\n", +120);
	// ft_printf ("% i\n", +120);
	
	// // printf ("%%\n");
	//i = printf ("caracteres impresos: %d\n", printf ("1234\n"));
	//printf ("%d", i);

	// ft_printf ("Prueba1: %d %i %% %c %s %bb\n", 2147483647, -2147483648, 'H', "prueba");
	// ft_printf ("Prueba2: %u\n", 4294967295);
	// ft_printf ("Prueba3: %x\n", -65534);
	// ft_printf ("Prueba4: %X\n", -65534);
	//printf ("%d\n", printf ("Prueba5: %p\n", ptr));
	//printf ("%d\n", ft_printf ("Prueba5: %p\n", ptr));
	// ft_printf ("Prueba6: %X\n", 2147483647);
	// printf ("Prueba6: %X\n", 2147483647);
	
		
	return (0);
}

// el compilador no avisa si el numero de placeholders y argumentos
// no coinciden, proteger?

// si despues del % no hay un caracter valido me lo salto y no hago
// nada, tampoco leo de la lista de argumentos

//unsigned long long
//9223372036854775807
//unsigned int 4294967295
 //2147483647
 //-2147483648

