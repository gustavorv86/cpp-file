
#ifndef SUDOKU_EXCEPTION_H
#define SUDOKU_EXCEPTION_H

#include <string>

using namespace std;

namespace io {

	class file_exception : public exception {
	private:
		string message;
		
	public:
		file_exception(const string message);
		virtual ~file_exception();

		const char * what() const throw();
	};
}

#endif
