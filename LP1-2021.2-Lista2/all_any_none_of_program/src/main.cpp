#include <iostream>   // cout, endl
#include <cassert>    // assert()
#include <iterator>   // std::begin(), std::end()
#include <vector>     // std::vector
#include <sstream>    // std::stringstream
#include <string>     // std::string

#include "all_any_none_of.h"

// convert a string to a vector of integers
std::vector<int> string_to_vector(const std::string& s)
{
	std::vector<int> v;
	std::stringstream ss(s);
	int i;
	while (ss >> i)
		v.push_back(i);
	return v;
}


void AlOf(std::vector<int> inputs, std::string predicate){
	// find a number in the predicate
	std::stringstream ss(predicate);
	int num;
	ss >> num;
	if (predicate.find(">")){
		bool result = std::all_of(inputs.begin(), inputs.end(), [num](const int& e){return e > num;});
		if (result){
			std::cout << "True" << std::endl;
		} else {
			std::cout << "False" << std::endl;
		}
	} else{
		bool result = std::all_of(inputs.begin(), inputs.end(), [num](const int& e){return e < num;});
		if (result){
			std::cout << "True" << std::endl;
		} else {
			std::cout << "False" << std::endl;
		}
	}
}

int main(){

	std::string functionName;
	std::string inputs;
	std::string predicate;

	while(std::cin >> functionName >> inputs >> predicate){
		std::vector<int> v = string_to_vector(inputs);

		if (functionName == "all_of"){
			AlOf(v, predicate);
		}
		// } else if (functionName == "any_of"){
		// 	AnOf(vecNumbers, predicate);
		// } else if (functionName == "none_of"){
		// 	NoOf(vecNumbers, predicate);
		// }
	}
}
