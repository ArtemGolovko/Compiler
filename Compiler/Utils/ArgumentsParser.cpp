#include "ArgumentsParser.h"

namespace Utils
{
	ArgumentsParser::Argusents ArgumentsParser::parse(int argc, char* argv[])
	{
		Argusents arguments;

		for (int i = 1; i < argc; ++i)
		{
			std::string argument = argv[i];
			if (argument == "-f" || argument == "--file")
			{
				++i;
				if (argc < i)
					throw std::exception((argument + ": Argument value required").c_str());

				arguments.filename = std::string(argv[i]);

				continue;
			}
			else if (argument == "-i" || argument == "--interactive")
			{
				arguments.isInteractiveMode = true;

				continue;
			}
			else if (argument == "-h" || argument == "--help")
			{
				printHelp();

				break;
			}
			else
				throw std::exception("Invalid arguments");
		}
		return arguments;
	}

	void ArgumentsParser::printHelp()
	{
		std::cout
			<< "Help: \n"
			<< "\t-f, --file <filename> \tCompile file.\n"
			<< "\t-i, --interactive \tRun iteractive mode.\n"
			<< "\t-h, --help \tInformation about flags and compiler\n"
			<< std::endl;
	}
}