#ifndef HELP_H
#define HELP_H

#include <iostream>
#include <string>
#include <map>
#include <iterator>
#include <vector>

	class Help
	{
	public:
		Help();
		~Help();
		void printMap(std::map<double,double>);

		void printMap(std::map<double,std::vector<int> >);
	};
#endif