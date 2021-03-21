#include <string>
#include <string_view>
#include <vector>
#include <regex>
#include <algorithm>
#include "Token.h"

#ifndef LEXER_H
#define LEXER_H

namespace Compiler
{

	class Lexer
	{
	private:
		int m_offset{ 0 };
		std::string_view m_source;
		const std::vector<char> m_spaces{ ' ', '\t', '\n', '\r' };

		std::vector<StaticTokenDefinition> m_statics;
		std::vector<DynamicTokenDefinition> m_dynamics;
	public:
		Lexer(
			std::vector<StaticTokenDefinition>& statics,
			std::vector<DynamicTokenDefinition>& dynamics
		);
		std::vector<Token*> tokenize(const std::string& source);

		bool inBounds();
		void skipSpaces();
		void cleanUp();
		Token* dynamicToken();
		Token* staticToken();
	};
}
#endif // LEXER_H