/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eprottun <eprottun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 17:28:43 by eprottun          #+#    #+#             */
/*   Updated: 2026/01/08 15:08:51 by eprottun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
# define HARL_HPP

# include <string>

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