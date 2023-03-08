/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpizarro <jpizarro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 05:57:45 by jpizarro          #+#    #+#             */
/*   Updated: 2023/03/08 14:42:13 by jpizarro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <cmath>

using namespace std;

class	Fixed {

public:
	Fixed( void );
	Fixed( int const num );
	Fixed( float const ft );
	Fixed( Fixed const & fx );
	~Fixed( void );

	Fixed&	operator=(Fixed const & fx);
	int		getRawBits( void ) const;
	void	setRawBits( int const raw );
	float	toFloat( void ) const;
	int		toInt( void ) const;

private:
	int					_rawBits;
	static const int	_shiftPoint = 8;

};

ostream&	operator<<(ostream& COUT, Fixed const & fx);

#endif