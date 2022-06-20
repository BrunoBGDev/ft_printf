/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ptr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbraga <bruno.braga.design@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 19:14:28 by bbraga            #+#    #+#             */
/*   Updated: 2022/06/20 00:49:06 by bbraga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*static int	ft_check_base(char *base)
{
	int	count;
	int	count2;

	if (base[0] == '\0' || base[1] == '\0')
		return (0);
	count = 0;
	count2 = 0;
	while (base[count])
	{
		count2 = count + 1;
		if (base[count] == '+' || base[count] == '-')
			return (0);
		if (base[count] < 32 || base[count] > 126)
			return (0);
		while (base[count2])
		{
			if (base[count] == base[count2])
				return (0);
			count2++;
		}
		count++;
	}
	return (1);
}

static void	ft_putnbr_base(unsigned long n, char *base)
{
	unsigned int	count;

	if (ft_check_base(base))
	{
		base_len = 0;
		while (base[count])
			count++;
		if (n > count -1)
		{
			ft_putnbr_base(n / count, base);
			n %= count;
		}
		ft_putchr(base[n], len);
	}	
}*/

int	ft_ptr_len(unsigned int num)
{
	int	len;

	len = 0;
	while (num != 0)
	{
		len++;
		num = num / 16;
	}
	return (len);
}

void	ft_put_ptr(unsigned int num)
{
	if (num >= 16)
	{
		ft_put_ptr(num / 16);
		ft_put_ptr(num % 16);
	}
	else
	{
		if (num <= 9)
			ft_putchar_fd((num + '0'), 1);
		else
			ft_putchar_fd((num - 10 + 'a'), 1);
	}
}

int	ft_ptr(unsigned long long ptr)
{
	int	rtn;

	rtn = 0;
	rtn += write(1, "0x", 2);
	if (rtn == 0)
		rtn += write(1, "0", 1);
	else
	{
		ft_put_ptr(ptr);
		rtn += ft_ptr_len(ptr);
	}
	return (rtn);
}
