#include <vector>
#include <iostream>

#ifndef CHAR_TABLE_H
#define CHAR_TABLE_H
namespace Compiler
{
	struct charTableRow
	{
		int offset;
		char type;
	};

	extern std::vector<charTableRow> charTable;
}
#endif // CHAR_TABLE_H_

