
#include "file_exception.h"

using namespace io;

file_exception::file_exception(const string message) {
	this->message = message;
}

file_exception::~file_exception() {
}

const char * file_exception::what() const throw() {
	return this->message.c_str();
}
