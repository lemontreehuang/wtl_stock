#include <string>
#include <cerrno>
#include <fstream>
#include "file_parse.h"
#include "dad_parse_iterator.h"

#ifndef dad_file_parse_h
#define dad_file_parse_h
using namespace std;

class dad_file_parse :public file_parse<parse_of_dad,char *>
{
public:
	using iterator = dad_parse_iterator;
	dad_parse_iterator begin() const
	{
		return dad_parse_iterator(block_, block_ + size_, {
			(id_of_dad *)(block_ + 20),
			(quote_of_dad *)(block_ + 16 + 32)
		});
	}

	dad_parse_iterator end() const
	{
		return dad_parse_iterator();
	}
	
};

#endif