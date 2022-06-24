/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misrailo <misrailo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 19:09:01 by misrailo          #+#    #+#             */
/*   Updated: 2022/05/10 19:13:34 by misrailo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long long int	nbr;
	long long int	a;
	long long int	b;

	nbr = n;
	a = 0;
	b = 9;
	if (nbr < a)
	{
		ft_putchar_fd('-', fd);
		nbr = -nbr;
	}
	if (nbr > b)
	{
		ft_putnbr_fd(nbr / 10, fd);
		ft_putchar_fd(nbr % 10 + '0', fd);
	}
	else
	{
		nbr = nbr + '0';
		ft_putchar_fd(nbr, fd);
	}
}
