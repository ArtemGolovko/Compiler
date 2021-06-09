#include <string>
#include <string_view>
#include <vector>
#include <regex>
#include <algorithm>
#include "Token.h"
#include "TokenDefinition.h"

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

		std::vector<TokenDefinition> m_tokenDefs;
	public:
		Lexer(
			std::vector<TokenDefinition> tokenDefs
		);
		std::vector<Token> tokenize(const std::string& source);

		bool inBounds();
		void skipSpaces();
		void cleanUp();
		Token nextToken();
	};
}
#endif // LEXER_H