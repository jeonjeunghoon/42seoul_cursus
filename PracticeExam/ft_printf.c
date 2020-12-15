#include <stdlib.h>
#include <stdarg.h>
#include <unistd.h>

typedef struct 	s_list
{
	int			width;
	int			pre;
}				t_list;

t_list g_lst;
int		g_count;
int		g_error;
int		g_len;
unsigned int g_c;

void			g_clear(void)
{
	g_count = 0;
	g_error = 0;
}

void			s_clear(void)
{
	g_lst.width = 0;
	g_lst.pre = 0;
}

int				ft_strlen(char *s)
{
	int i;

	if (!s)
		return (0);
	i = 0;
	while (s[i])
		i++;
	return (i);
}

int				numlen(long long d)
{
	int i;

	i = 0;
	while (d)
	{
		d /= 10;
		i++;
	}
	return (i);
}

long long		ft_atoi(char *format)
{
	long long 	d;
	int			i;
	
	d = 0;
	i = 0;
	while (format[i] >= '0' && format[i] <= '9')
	{
		d *= 10;
		d += format[i] - '0';
		i++;
	}
	return (d);
}

int				u_len(unsigned int d)
{
	int i;

	i = 0;
	while (d)
	{
		d /= 16;
		i++;
	}
	return (i);
}

void			ft_itou(unsigned int d, char **pp, char *base)
{
	int len;

	if (d == 0)
	{
		g_c = -1;
		return ;
	}
	len = u_len(d);
	if (len > 8)
		len = 8;
	if (!(*pp = (char *)malloc(sizeof(char) * (len + 1))))
		return ;
	(*pp)[len] = '\0';
	while (len != 0 && d != 0)
	{
		(*pp)[--len] = base[d % 16];
		d /= 16;
	}
}

void	get_flag(char **format)
{
	(*format)++;
	if (**format >= '1' && **format <= '9')
	{
		g_lst.width = ft_atoi(*format);
		*format += numlen(g_lst.width);
	}
	if (**format == '.')
	{
		(*format)++;
		while (**format == '0')
			(*format)++;
		if (**format >= '1' && **format <= '9')
		{
			g_lst.pre = ft_atoi(*format);
			*format += numlen(g_lst.pre);
		}
		else
			g_lst.pre = -1;
	}
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
	g_count++;
}

void	get_arg(char **format, va_list ap, char **pp)
{
	if (**format == 'c' || **format == 'x')
	{
		g_c = va_arg(ap, unsigned int);
		if (**format == 'x')
			ft_itou(g_c, pp, "0123456789abcdef");
	}
	else if (**format == 's')
		*pp = va_arg(ap, char *);
	else
	{
		g_error = -1;
		return ;
	}
	if (**format == 's' || **format == 'x')
		g_len = ft_strlen(*pp);
	if (**format == 'c')
		g_len = 1;
}

int		ft_printf(char *format, ...)
{
	char *p;
	va_list ap;

	globalclear();
	va_start(ap, format);
	p = NULL;
	while (*format)
	{
		if (*format == '%')
		{
			get_flag(&format);
			get_arg(&format, ap, &p);
			if (g_error == -1)
				return (0);
			print_flag();
			print_arg();
			s_clear();
		}
		else
			ft_putchar(*format);
		format++;
	}
	ft_free(*format, (void *)&p);
	va_end(ap);
	return (g_count);
}