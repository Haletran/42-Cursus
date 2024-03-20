#include <unistd.h>
#include <stdarg.h>
#include <stdlib.h>

int ft_putstr(const char *str)
{
    int i = 0;

    while (str[i])
        write(1, &str[i++], 1);
    return (i);
}

int	ft_putnbr(long long int number, int base)
{
	char	*hexadecimal = "0123456789abcdef";
    int len = 0;

	if (number < 0)
	{
		number *= -1;
		len += write(1, "-", 1);
	}
	if (number >= base)
		ft_putnbr((number / base), base);
	len += write(1, &hexadecimal[number % base], 1);
    return(len);
}


int ft_printf(const char *format, ...)
{
    int len = 0;
    int i = 0;

    va_list pointer;
    va_start(pointer, format);

    while(format[i])
    {
        if (format[i] == '%' && (format[i + 1] == 's' || format[i + 1] == 'd' || format[i + 1] == 'x'))
        {
            i++;
            if (format[i] == 's')
                len  += ft_putstr(va_arg(pointer, char *));
            else if (format[i] == 'd')
                len  += ft_putnbr(va_arg(pointer, int), 10);
            else if (format[i] == 'x')
                len  += ft_putnbr(va_arg(pointer, unsigned int), 16);
        }
        else
            len += write(1, &format[i], 1);
        i++;
    }
    va_end(pointer);
    return (len);
}

#include <stdio.h>

int main()
{
    ft_printf("Magic %s is %d\n", "number", 42);
    ft_printf("My Printf = %d\n", ft_printf("Hexadecimal for %d is %x\n", 42, 42));
    printf("Original Printf = %d", printf("Hexadecimal for %d is %x\n", 42, 42));
    return (0);

}
