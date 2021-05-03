/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Replace.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joopark <joopark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 12:37:31 by joopark           #+#    #+#             */
/*   Updated: 2021/05/03 16:47:08 by joopark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Replace.hpp"

Replace::Replace() : _file(), _buf() {}

bool Replace::open(std::string filename) {
	std::string tmp;

	std::ifstream file(filename);
	if (!file.is_open())
		return (false);
	tmp = "";
	while (!file.eof()) {
		std::getline(file, tmp);
		if (_file.length() == 0) {
			_file = tmp;
		} else {
			_file = _file + "\n" + tmp;
		}
	}
	file.close();
	return (true);
}

void Replace::replace(std::string find, std::string replace) {
	size_t start;
	size_t len;
	size_t found;

	start = 0;
	len = _file.length();
	if (find.length() < 1) {
		_buf = _file;
	} else {
		while (true) {
			found = _file.find(find, start);
			if (found == std::string::npos) {
				_buf = _buf + _file.substr(start, (len - start));
				break ;
			}
			_buf = _buf + _file.substr(start, (found - start));
			_buf = _buf + replace;
			start = found + find.length();
		}
	}
}

bool Replace::save(std::string filename) {
	std::ofstream file(filename);
	if (!file.is_open())
		return (false);
	file << _buf;
	file.close();
	return (true);
}