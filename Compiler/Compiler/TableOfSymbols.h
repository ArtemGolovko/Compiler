#include <vector>
#include <iostream>

#ifndef CHAR_TABLE_H
#define CHAR_TABLE_H
namespace Compiler
{
	struct tableOfSymbolsRow
	{
		int offset;
		char type;
	};

	extern std::vector<tableOfSymbolsRow> tableOfSymbols;
}
#endif // CHAR_TABLE_H_

