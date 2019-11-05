// in and out streams and stream iterators.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string>
#include <set>
#include <vector>
#include <iterator>
#include <algorithm>

void second_way_to_do_problem() {
	std::string from, to;
	std::getline(std::cin, from);
	std::getline(std::cin, to);
	std::cout << "Input file: " << from << std::endl;
	std::cout << "Output file: " << to << std::endl;

	std::ifstream in {from};
	std::istream_iterator<std::string> ii {in};
	std::istream_iterator<std::string> eos{};

	std::ofstream out;
	std::ostream_iterator<std::string> oo{ out, "\n" };

	std::vector<std::string> words{ii, eos};
	sort(words.begin(), words.end());
	unique_copy(words.begin(), words.end(), oo);
}

int main()
{
	char enter;

	std::string from, to;
	std::getline(std::cin, from);
	std::getline(std::cin, to);
	std::cout << "Input file: " << from << std::endl;
	std::cout << "Output file: " << to << std::endl;

	std::ifstream in {from};
	std::ofstream out {to};

	std::set<std::string> words {std::istream_iterator<std::string>{in}, std::istream_iterator<std::string>{}};
	copy(words.begin(), words.end(), std::ostream_iterator<std::string>{out});

	second_way_to_do_problem();

	std::cin.get(enter);

    return 0;
}

