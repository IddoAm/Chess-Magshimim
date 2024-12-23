#pragma once
#include <exception>

class EndGameException : public std::exception {
	const char* message;
public:
	EndGameException(std::string message) { this->message = message.c_str(); }
	virtual const char* what() const throw() {
		return message;
	}
};