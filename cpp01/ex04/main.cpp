/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eprottun <eprottun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 12:12:32 by eprottun          #+#    #+#             */
/*   Updated: 2026/01/08 15:08:39 by eprottun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <sstream>

static int readFile(const char* filename, std::string &content) {
	std::stringstream buffer;
	std::ifstream file(filename);
	
	if (!file.is_open())
	{
		std::cerr << "File couldn't be opened" << std::endl;
		return 0;
	}
	buffer << file.rdbuf();
	content = buffer.str();
	file.close();
	return 1;
}

static int stringReplace(std::string& content, const char* find, const char* replace) {
	std::string string1 = find;
	std::string string2 = replace;
	
	if (string1.length() == 0)
	{
		std::cerr << "String to find can't be empty" << std::endl;
		return 0;
	}
	std::size_t pos = content.find(string1);
	while (pos != std::string::npos)
	{
		content.erase(pos, string1.length());
		content.insert(pos, string2);
		pos = content.find(string1, pos + string2.length());
	}
	return 1;
}

static int writeFile(const char* filename, const std::string &content) {
	std::string newName = filename;
	newName.append(".replace");
	std::ofstream file(newName.c_str());
	if (!file.is_open())
	{
		std::cerr << "File couldn't be opened" << std::endl;
		return 0;
	}
	file << content;
	file.close();
	return 1;
}

int main(int ac, char *argv[]) {
	std::string content;
	
	if (ac != 4)
	{
		std::cerr << "Wrong number of parameters" << std::endl;
		return 1;
	}
	if (!readFile(argv[1], content))
		return 1;
	if (!stringReplace(content, argv[2], argv[3]))
		return 1;
	if (!writeFile(argv[1], content))
		return 1;
	return 0;
}
