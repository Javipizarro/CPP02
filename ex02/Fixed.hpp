/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpizarro <jpizarro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 05:57:45 by jpizarro          #+#    #+#             */
/*   Updated: 2023/03/14 22:57:55 by jpizarro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <cmath>

using std::cout;
using std::endl;
using std::string;
using std::ostream;

class	Fixed {

public:
///	CONSTRUCTORS & DESTRUCTOR		///
	Fixed( void );
	Fixed( int const num );
	Fixed( float const ft );
	Fixed( Fixed const & fx );
	~Fixed( void );

///	COMPARISON OPERATORS			///
	bool	operator>(Fixed const & fx) const;
	bool	operator<(Fixed const & fx) const;
	bool	operator>=(Fixed const & fx) const;
	bool	operator<=(Fixed const & fx) const;
	bool	operator==(Fixed const & fx) const;
	bool	operator!=(Fixed const & fx) const;

	static	Fixed& min(Fixed& a, Fixed& b);
	static	const Fixed& min(const Fixed& a, const Fixed& b);
	static	Fixed& max(Fixed& a, Fixed& b);
	static	const Fixed& max(const Fixed& a, const Fixed& b);
	
///	ARITHMETIC OPERATORS			///
	Fixed&	operator=(Fixed const & fx);
	Fixed	operator+(Fixed const & fx) const;
	Fixed	operator-(Fixed const & fx) const;
	Fixed	operator*(Fixed const & fx) const;
	Fixed	operator/(Fixed const & fx) const;

///	INCREMENTALS					///
	Fixed&	operator++( void );
	Fixed	operator++( int num );
	Fixed&	operator--( void );
	Fixed	operator--( int num );

///	GETTER & SETTER					///	
	int		getRawBits( void ) const;
	void	setRawBits( int const raw );

///	CONVERSIONS						///
	float	toFloat( void ) const;
	int		toInt( void ) const;

private:
	int					_rawBits;
	static const int	_shiftPoint = 8;

};

///	STREAM OPERATORS				///

ostream&	operator<<(ostream& COUT, Fixed const & fx);

#endif