#include "help.h"

Help::Help(){

}

Help::~Help(){

}

void Help::printMap(std::map<double,double> maps){
	std::map<double,double>::iterator it;

	std::cout <<"BEGI DUMPING MAP " << std::endl;

	for (it = maps.begin(); it!=maps.end(); ++it)
	{
		/* code */
		std::cout << it->first << " " << it->second << std::endl;
	}

	std::cout <<"END DUMPING MAP " << std::endl;


}

void Help::printMap(std::map<double,std::vector<int> > maps){
	std::map<double,std::vector<int> >::iterator it;

	std::cout <<"BEGI DUMPING MAP " << std::endl;

	for (it = maps.begin(); it!=maps.end(); ++it)
	{
		/* code */
		std::cout << "Key " << it->first << std::endl;

		std::vector<int> values = it->second;

		for (int i = 0; i < values.size(); ++i)
		{
			/* code */
			std::cout << "Element " << i << " " <<values.at(i) << std::endl;
		}

		std::cout << "END KEY" << std::endl;
		
	}

	std::cout <<"END DUMPING MAP " << std::endl;
}