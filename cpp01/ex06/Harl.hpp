/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eprottun <eprottun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 17:28:43 by eprottun          #+#    #+#             */
/*   Updated: 2025/11/26 17:38:57 by eprottun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
# define HARL_HPP

# include <iostream>

using std::string;
using std::cout;
using std::endl;

class Harl {
	public :
		void complain( std::string level );
	private :
		void debug( void );
		void info( void );
		void warning( void );
		void error( void );
}	;
#endif