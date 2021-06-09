#include "Lexer.h"

namespace Compiler
{
	Lexer::Lexer(std::vector<TokenDefinition> tokenDefs)
		: m_tokenDefs(tokenDefs), m_offset{ 0 }
	{
	}

	std::vector<Token> Lexer::tokenize(const std::string& source)
	{
		m_source = std::string_view(source);
		std::vector<Token> lexems;

		skipSpaces();
		while (inBounds())
		{
			Token token(nextToken());
			if (token.isInvalid())
				throw  std::exception((std::string("Lexer: Unexpected char \"") + m_source[m_offset] + "\" at " + std::to_string(m_offset + 1)).c_str());

			lexems.push_back(token);
			skipSpaces();
		}
		cleanUp();
		return lexems;
	}

	Token Lexer::nextToken()
	{
		for (const auto& tokenDef : m_tokenDefs)
		{
			if (tokenDef.getType() == TokenDefinitionType::STATIC)
			{
				staticRepres repres = std::any_cast<staticRepres>(tokenDef.getRepres());

				if (m_source.substr(m_offset, repres.length()) != repres)
					continue;

				m_offset += repres.length();

				return Token(tokenDef.getTokenType(), repres);
			}
			if (tokenDef.getType() == TokenDefinitionType::DYNAMIC)
			{
				dynamicRepres repres = std::any_cast<dynamicRepres>(tokenDef.getRepres());
				std::smatch match;
				std::string substr(m_source.substr(m_offset));

				if (!std::regex_search(substr, match, repres) || match.position(0) != 0)
					continue;

				std::string value(match[0].str());
				m_offset += value.length();

				return Token(tokenDef.getTokenType(), value);
			}
			if (tokenDef.getType() == TokenDefinitionType::FUNCTIONAL)
			{
				functionalRepres repres = std::any_cast<functionalRepres>(tokenDef.getRepres());
				Token token(repres(std::string(m_source.substr(m_offset))));
				if (token.isInvalid())
					continue;

				return token;
			}
		}
		return Token(INVALID_TOKEN, "");
	}

	/*
	Token* Lexer::staticToken()
	{
		for (const auto& tokenDef : m_statics)
		{
			std::string repres(tokenDef.getRepres());
			if (m_source.substr(m_offset, repres.length()) != repres)
				continue;

			m_offset += repres.length();

			return new Token(tokenDef.getType(), "");
		}
		return nullptr;
	}

	Token* Lexer::dynamicToken()
	{
		for (const auto& tokenDef : m_dynamics)
		{
			std::regex repres(tokenDef.getRepres());
			std::smatch match;
			std::string substr(m_source.substr(m_offset));

			if (!std::regex_search(substr, match, repres) || match.position(0) != 0)
				continue;

			std::string value(match[0].str());
			m_offset += value.length();

			return new Token(tokenDef.getType(), value);
		}
		return nullptr;
	}
	*/

	void Lexer::skipSpaces()
	{
		while (inBounds() && std::find(m_spaces.begin(), m_spaces.end(), m_source[m_offset]) != m_spaces.end())
		{
			m_offset++;
		}
	}

	bool Lexer::inBounds()
	{
		return m_offset < m_source.length();
	}

	void Lexer::cleanUp()
	{
		m_offset = 0;
	}
}