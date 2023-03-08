/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpizarro <jpizarro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 05:57:42 by jpizarro          #+#    #+#             */
/*   Updated: 2023/03/08 07:16:46 by jpizarro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed( void ) : _rawBits(0) {
	cout << "Default constructor called" << endl;
	return;
}

Fixed::Fixed( Fixed const & fx ) {
	cout << "Copy constructor called" << endl;
	*this = fx;
	return;
}

Fixed::~Fixed( void ) {
	cout << "Destructor called" << endl;
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