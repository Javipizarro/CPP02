/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpizarro <jpizarro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 05:57:42 by jpizarro          #+#    #+#             */
/*   Updated: 2023/03/08 14:55:30 by jpizarro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed( void ) : _rawBits(0) {
	cout << "Default constructor called" << endl;
	return;
}

Fixed::Fixed( int const num ) : _rawBits(num << _shiftPoint) {
	cout << "Int constructor called" << endl;
	return;
}

Fixed::Fixed( float const ft ) : _rawBits((int)roundf(ft * (1 << _shiftPoint))) {
	cout << "Float constructor called" << endl;
	return;
}

Fixed::Fixed( Fixed const & fx ) {
	cout << "Copy constructor called" << endl;
	*this = fx;
	return;
}

Fixed::~Fixed( void ) {
	cout << "Destructor called" << endl;
	return;
}

Fixed&	Fixed::operator=( Fixed const & fx) {
	cout << "Assignation operator called" << endl;
	this->setRawBits(fx.getRawBits());
	return *this;
}

int		Fixed::getRawBits( void ) const {
	cout << "getRawBits member function called" << endl;
	return (this->_rawBits);
}

void	Fixed::setRawBits( int const raw ) {
	this->_rawBits = raw;
	return;
}

float	Fixed::toFloat( void ) const {
	return ((float)this->_rawBits / (1 << this->_shiftPoint));
}
int		Fixed::toInt( void ) const {
	return (this->_rawBits >> this->_shiftPoint);
}

ostream&	operator<<(ostream& COUT, Fixed const & fx) {
	COUT << fx.toFloat();
	return COUT;
}
