#include <iostream>
#include <string>

#ifndef UTILS_ARGUMENTS_PARSER_H
#define UTILS_ARGUMENTS_PARSER_H

namespace Utils
{
	class ArgumentsParser
	{
	public:
		struct Argusents
		{
			bool isInteractiveMode = false;

			std::string filename{ "" };
		};

		static Argusents parse(int argc, char* argv[]);

		static void printHelp();
	};
}

#endif // UTILS_ARGUMENTS_PARSER_H


