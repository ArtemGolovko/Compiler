#include <vector>
#include <iostream>

#ifndef CHAR_TABLE_H
#define CHAR_TABLE_H

struct charTableRow
{
	int offset;
	char type;
};

std::vector<charTableRow> charTable;

#endif // CHAR_TABLE_H_

