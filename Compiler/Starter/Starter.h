#include <iostream>
#include "Compiler/CharTable.h"
#include "Compiler/Token.h"
#include "Compiler/Lexer.h"
#include "Utils/ArgumentsParser.h"
#include "Utils/Reader.h"

#ifndef STARTER_STARTER_H
#define STARTER_STARTER_H
namespace Starter {
	class Starter
	{
	public:
		Starter(int argc, char* argv[]);

	private:
		Utils::ArgumentsParser::Argusents m_arguments;
		Compiler::Lexer* m_lexer;
		void parse(std::string input);
		void runIteractiveMode();
	};
}
#endif // STARTER_STARTER_H

