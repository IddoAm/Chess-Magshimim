#pragma once
#include <exception>
class PawnException : public std::exception {
public:
	const char* what() const throw() {
		return "PawnException";
	}
};