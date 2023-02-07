#include <stdio.h>		// para el printf, quitar
#include <stdlib.h>		// para el malloc, quitar
#include <unistd.h>
#include <stdarg.h>

# define HEX_LOWER	"0123456789abcdef"
# define HEX_UPPER	"0123456789ABCDEF"
# define POINTER	"0x"

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

int	ft_put_number_hex(unsigned long long n, int caps, int ptr, int *i)
{
	if (ptr == 1)
	{
		if (ft_putstr (POINTER) != 2)
			return (-1);
		*i = *i + 2;
	}
	if (n >= 16)
	{
		ft_put_number_hex(n / 16, caps, 0, i);
		if (*i == -1)
			return (-1);
		ft_put_number_hex(n % 16, caps, 0, i);
	}
	else
	{
		if (caps == 0) 
			if (write (1, &(HEX_LOWER[n]), 1) != 1)
				*i = -2;
		if (caps == 1)
			if (write (1, &(HEX_UPPER[n]), 1) != 1)
				*i = -2;
		(*i)++;
	}
	return (*i);
}


int	ft_actions(char const p_holder, va_list arg)
{
	int	i;

	i = 0;
	if ((p_holder) == '%')
		return (ft_putchar('%'));
	else if (p_holder == 'c')
		return (ft_putchar(va_arg (arg, int)));
	else if (p_holder == 'd' || p_holder == 'i')
		return (ft_put_number(va_arg (arg, int), &i));
	else if (p_holder == 'u')
		return (ft_put_number(va_arg (arg, unsigned int), &i));
	else if (p_holder == 'x')
		return (ft_put_number_hex(va_arg (arg, unsigned int), 0, 0, &i));
	else if (p_holder == 'X')
		return (ft_put_number_hex(va_arg (arg, unsigned int), 1, 0, &i));
	else if (p_holder == 's')
		return (ft_putstr(va_arg (arg, char *)));
	else if (p_holder == 'p')
		return (ft_put_number_hex(va_arg (arg, unsigned long long), 0, 1, &i));
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


int	main(void)
{
	//int	i;
	void	*ptr;
	
	ptr = malloc (100);
	// // printf ("%c\n", 'a');
	// // printf ("%s\n", "hola");
	// printf ("%p\n", ptr);
	// // printf ("%d\n", -1234);
	// // printf ("%i\n", -1234);
	ft_printf ("%i\n", -1234);
	printf ("%d\n", ft_printf ("%i\n", -1234));
	// // printf ("%x\n", 1234);
	// // printf ("%X\n", 1234);
	// // printf ("%%\n");
	//i = printf ("caracteres impresos: %d\n", printf ("1234\n"));
	//printf ("%d", i);

	// ft_printf ("Prueba1: %d %i %% %c %s %bb\n", 2147483647, -2147483648, 'H', "prueba");
	// ft_printf ("Prueba2: %u\n", 4294967295);
	// ft_printf ("Prueba3: %x\n", -65534);
	// ft_printf ("Prueba4: %X\n", -65534);
	printf ("%d\n", printf ("Prueba5: %p\n", ptr));
	printf ("%d\n", ft_printf ("Prueba5: %p\n", ptr));
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

