/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpizarro <jpizarro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 05:57:45 by jpizarro          #+#    #+#             */
/*   Updated: 2023/03/08 07:16:56 by jpizarro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

using namespace std;

class	Fixed {

public:
	Fixed( void );
	Fixed( Fixed const & fx );
	~Fixed( void );

	Fixed&	operator=(Fixed const & fx);
	int		getRawBits( void ) const;
	void	setRawBits( int const raw );

private:
	int					_rawBits;
	static const int	_shiftPoint = 8;

};

#endif