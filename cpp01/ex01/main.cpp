/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eprottun <eprottun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 17:51:05 by eprottun          #+#    #+#             */
/*   Updated: 2025/11/25 18:33:48 by eprottun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main() {
    int N = 15;
    Zombie* horde = zombieHorde(15, "mynameisthesameaseveryoneelse");

    for (size_t i = 0; i < (size_t)N; i++)
    {
        horde[i].announce();
    }
    delete[] horde;
    return 0;
}
