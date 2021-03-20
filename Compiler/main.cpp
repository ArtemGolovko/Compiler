#include <iostream>
#include <string>
#include <vector>
#include "CharTable.h"
#include "Token.h"
#include "Lexer.h"


int main(int argc, char* argv[])
{
	setlocale(LC_ALL, "ru");

	const TokenType PLUS("PLUS");
	const TokenType MINUS("MINUS");
	const TokenType DIV("DIV");
	const TokenType MUL("MUL");
	const TokenType NUM("NUM");

	std::vector<StaticTokenDefinition> statics = {
		StaticTokenDefinition(PLUS, "+"),
		StaticTokenDefinition(MINUS, "-"),
		StaticTokenDefinition(DIV, "/"),
		StaticTokenDefinition(MUL, "*"),
	};

	std::vector<DynamicTokenDefinition> dynamics = {
		DynamicTokenDefinition(NUM, "[0-9]+")
	};

	std::string input = "1+1-1/1*1";

	Lexer lexer(statics, dynamics);
	try {
		std::vector<Token*> lexems(lexer.tokenize(input));
		for (auto it = lexems.cbegin(); it != lexems.cend(); ++it)
		{
			std::cout << (*it)->getType().getStrType() << " " << (*it)->getValue() << std::endl;
		}
	}
	catch (std::exception& ex)
	{
		std::cout << ex.what() << std::endl;
		std::exit(-1);
	}

	return 0;
}