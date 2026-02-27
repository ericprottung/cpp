/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eprottun <eprottun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 11:45:18 by eprottun          #+#    #+#             */
/*   Updated: 2025/12/09 14:02:52 by eprottun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"
#include "WrongAnimal.hpp"

WrongCat::WrongCat() : WrongAnimal(){
	type = "WrongCat";
}

WrongCat::WrongCat(const WrongCat& other) : WrongAnimal(other) {
	type = other.type;
}

WrongCat& WrongCat::operator=(const WrongCat& other) {
	type = other.type;
	return *this;
}

WrongCat::~WrongCat() {}
