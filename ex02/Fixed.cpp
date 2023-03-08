/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpizarro <jpizarro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 05:57:42 by jpizarro          #+#    #+#             */
/*   Updated: 2023/03/08 20:29:26 by jpizarro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"


///	CONSTRUCTORS & DESTRUCTOR		///

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


///	COMPARISON OPERATORS			///

bool	Fixed::operator>(Fixed const & fx) const{
	return (this->_rawBits > fx.getRawBits());
}

bool	Fixed::operator<(Fixed const & fx) const{
	return (this->_rawBits < fx.getRawBits());
}

bool	Fixed::operator>=(Fixed const & fx) const{
	return (this->_rawBits >= fx.getRawBits());
}

bool	Fixed::operator<=(Fixed const & fx) const{
	return (this->_rawBits <= fx.getRawBits());
}

bool	Fixed::operator==(Fixed const & fx) const{
	return (this->_rawBits == fx.getRawBits());
}
bool	Fixed::operator!=(Fixed const & fx) const{
	return (this->_rawBits != fx.getRawBits());
}

Fixed&			Fixed::min(Fixed& a, Fixed& b) {
	return (a < b ? a : b);
}

const Fixed&	Fixed::min(const Fixed& a, const Fixed& b) {
	return (a < b ? a : b);
}

Fixed&			Fixed::max(Fixed& a, Fixed& b) {
	return (a > b ? a : b);
}
const Fixed&	Fixed::max(const Fixed& a, const Fixed& b) {
	return (a > b ? a : b);
}


///	ARITHMETIC OPERATORS			///

Fixed&	Fixed::operator=( Fixed const & fx) {
	cout << "Assignation operator called" << endl;
	this->setRawBits(fx.getRawBits());
	return *this;
}

Fixed	Fixed::operator+(Fixed const & fx) const {
	Fixed	newFx;
	newFx.setRawBits(this->_rawBits + fx.getRawBits());
	return newFx;
}

Fixed	Fixed::operator-(Fixed const & fx) const {
	Fixed	newFx;
	newFx.setRawBits(this->_rawBits - fx.getRawBits());
	return newFx;
}

Fixed	Fixed::operator*(Fixed const & fx) const {
	Fixed	newFx;
	newFx.setRawBits((this->_rawBits * fx.getRawBits()) >> this->_shiftPoint);
	return newFx;
}

Fixed	Fixed::operator/(Fixed const & fx) const {
	Fixed	newFx;
	newFx.setRawBits((this->_rawBits << this->_shiftPoint) / fx.getRawBits());
	return newFx;
}


///	INCREMENTALS					///

Fixed&	Fixed::operator++( void ) {
	++(this->_rawBits);
	return *this;
}

Fixed	Fixed::operator++( int num ) {
	(void)num;
	Fixed newFx(*this);
	++(this->_rawBits);
	return newFx;
}

Fixed&	Fixed::operator--( void ) {
	--(this->_rawBits);
	return *this;
}

Fixed	Fixed::operator--( int num ) {
	(void)num;
	Fixed newFx(*this);
	--(this->_rawBits);
	return newFx;
}


///	GETTER & SETTER					///	

int		Fixed::getRawBits( void ) const {
	cout << "getRawBits member function called" << endl;
	return (this->_rawBits);
}

void	Fixed::setRawBits( int const raw ) {
	this->_rawBits = raw;
	return;
}


///	CONVERSIONS						///

float	Fixed::toFloat( void ) const {
	return ((float)this->_rawBits / (1 << this->_shiftPoint));
}
int		Fixed::toInt( void ) const {
	return (this->_rawBits >> this->_shiftPoint);
}


///	STREAM OPERATORS				///

ostream&	operator<<(ostream& COUT, Fixed const & fx) {
	COUT << fx.toFloat();
	return COUT;
}
