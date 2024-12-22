#pragma once
#include <exception>

class EndGameException : public std::exception {
	char* message;
public:
	EndGameException(char* message) { this->message = message; }
	virtual const char* what() const throw() {
		return message;
	}
};