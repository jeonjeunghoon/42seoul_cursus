#include <stdio.h>
#include "ft_printf.h"

int main(void)
{
	// printf("\n\n----------------GLOVAL-----------------\n\n");
	// printf("g_arglen============  %d\n", g_arglen);
	// printf("g_count=============  %d\n", g_count);
	// printf("g_error=============  %d\n", g_error);
	// printf("\n\n----------------FLAGS------------------\n\n");
	// printf("is_left=============  %d\n", flag_lst.is_left);
	// printf("is_zero=============  %d\n", flag_lst.is_zero);
	// printf("width===============  %d\n", flag_lst.width);
	// printf("pre=================  %d\n", flag_lst.pre);
	// printf("w_wild==============  %d\n", flag_lst.w_wild);
	// printf("p_wild==============  %d\n", flag_lst.p_wild);
	printf("\n\n----------------return-----------------\n\n");
	printf("expect\n");
	printf("%d\n", printf("%d\n", INT32_MIN));
	printf("mine\n");
	ft_printf("%d\n", ft_printf("%d\n", INT32_MIN));
}