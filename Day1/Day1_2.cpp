#include <iostream>
#include <fstream>
#include <string>

int	parseLine( std::string line ) {
	std::string	number = "00";

	for (size_t i = 0; i < line.length(); ++i) {
		if (std::isdigit( line[i])) {
			number[0] = line[i];
		break;
		}
	}
	for (size_t j = line.length(); j > 0; j--) {
		if (std::isdigit( line[j - 1])) {
			number[1] = line[j - 1];
		break;
		}
	}
	return std::atoi( number.c_str() );
}

int	main( int ac, char **av ) {

	if (ac != 2)
		return 1;
	std::string		input = av[1];
	std::ifstream	infile( input );
	int				result = 0;

	input.clear();
	while (std::getline( infile, input )) {
		result += parseLine( input );
	}
	std::cout << result << std::endl;
	return 0 ;
}