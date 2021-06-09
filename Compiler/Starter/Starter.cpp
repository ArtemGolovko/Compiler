#include "Starter.h"

namespace Starter
{
	Starter::Starter(int argc, char* argv[])
	{
		try
		{
			m_arguments = Utils::ArgumentsParser::parse(argc, argv);
		}
		catch (std::exception& ex)
		{
			std::cerr << ex.what() << std::endl;
			std::exit(-1);
		}

		const Compiler::TokenType PLUS("PLUS");
		const Compiler::TokenType MINUS("MINUS");
		const Compiler::TokenType DIV("DIV");
		const Compiler::TokenType MUL("MUL");
		const Compiler::TokenType NUM("NUM");

		std::vector<Compiler::TokenDefinition> tokenDefs = {
			Compiler::make_staticDef(PLUS, "+"),
			Compiler::make_staticDef(MINUS, "+"),
			Compiler::make_staticDef(DIV, "/"),
			Compiler::make_staticDef(MUL, "*"),
			Compiler::make_dynamicDef(NUM, "[0-9]+")
		};

		m_lexer = new Compiler::Lexer(tokenDefs);

		if (m_arguments.filename != "")
		{
			try {
				parse(Utils::Reader::readfile(m_arguments.filename));
			}
			catch (std::exception& ex)
			{
				std::cerr << ex.what() << std::endl;
				exit(-1);
			}
			exit(0);
		}
		if (m_arguments.isInteractiveMode)
		{
			runIteractiveMode();
		}
		system("PAUSE");
	}

	void Starter::parse(std::string input)
	{
		try {
			std::vector<Compiler::Token> lexems(m_lexer->tokenize(input));
			for (auto it = lexems.cbegin(); it != lexems.cend(); ++it)
			{
				std::cout << it->getType().getStrType() << " " << it->getValue() << std::endl;
			}
		}
		catch (std::exception& ex)
		{
			std::cerr << ex.what() << std::endl;
			std::exit(-1);
		}
	}

	void Starter::runIteractiveMode()
	{
		std::cout << "Type \".exit\" to exit" << std::endl;
		std::string input;

	loop:
		std::cout << "> ";
		std::cin >> input;

		if (input == ".exit") {
			std::exit(0);
		}

		parse(input);
		goto loop;
	}
}