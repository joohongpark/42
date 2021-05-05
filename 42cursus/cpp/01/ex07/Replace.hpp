/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Replace.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joopark <joopark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 12:37:25 by joopark           #+#    #+#             */
/*   Updated: 2021/05/06 01:08:06 by joopark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REPLACE_H
#define REPLACE_H

#include <string>
#include <fstream>

class Replace {
	private:
		std::string _file;
		std::string _buf;
	public:
		Replace();
		bool open(std::string filename);
		void replace(std::string find, std::string replace);
		bool save(std::string filename);
};

#endif
