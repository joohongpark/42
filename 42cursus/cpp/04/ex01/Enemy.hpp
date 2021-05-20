/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Enemy.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joopark <joopark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 14:31:46 by joopark           #+#    #+#             */
/*   Updated: 2021/05/18 18:43:48 by joopark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENEMY_HPP
#define ENEMY_HPP

#include <string>

class Enemy {
	protected:
		int _hp;
		std::string _type;
	public:
		Enemy(int hp, std::string const & type);
		Enemy(const Enemy & enemy);
		Enemy& operator=(const Enemy & enemy);
		virtual ~Enemy();
		std::string getType(void) const;
		int getHP(void) const;
		virtual void takeDamage(int damage);
};

#endif
