#include <stdio.h>		// para el printf, quitar
#include <stdlib.h>		// para el malloc, quitar
#include "ft_printf.h"

int	main(void)
{
	int	i;
	// void	*ptr;
	
	// ptr = malloc (100);
	
	// // printf ("%c\n", 'a');
	// // printf ("%s\n", "hola");
	// printf ("%p\n", ptr);
	// // printf ("%d\n", -1234);
	// // printf ("%i\n", -1234);
	ft_printf ("%u\n", 1234);
	// // printf ("%x\n", 1234);
	// // printf ("%X\n", 1234);
	// // printf ("%%\n");
	//i = printf ("caracteres impresos: %d\n", printf ("1234\n"));
	//printf ("%d", i);

	// ft_printf ("Prueba1: %d %i %% %c %s %bb\n", 2147483647, -2147483648, 'H', "prueba");
	// ft_printf ("Prueba2: %u\n", 4294967295);
	// ft_printf ("Prueba3: %x\n", -65534);
	// ft_printf ("Prueba4: %X\n", -65534);
	// ft_printf ("Prueba5: %p\n", ptr);
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

