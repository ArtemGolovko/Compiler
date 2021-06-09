#include <any>
#include <functional>
#include <regex>
#include "Token.h"

#ifndef TOKEN_DEFINITION_H
#define TOKEN_DEFINITION_H



namespace Compiler
{
	typedef std::string staticRepres;

	typedef std::regex dynamicRepres;

	typedef std::function<Token(std::string)> functionalRepres;

	enum class TokenDefinitionType
	{
		STATIC,
		DYNAMIC,
		FUNCTIONAL
	};

	class TokenDefinition
	{
	private:
		TokenType m_tokenType;
		std::any m_representation;
		TokenDefinitionType m_type;
	public:
		TokenDefinition(TokenType tokenType, std::any represantation, TokenDefinitionType type);

		TokenType getTokenType() const;
		std::any getRepres() const;
		TokenDefinitionType getType() const;
	};

	TokenDefinition make_staticDef(TokenType tokenType, std::string repres);
	TokenDefinition make_dynamicDef(TokenType tokenType, std::string repres);
	TokenDefinition make_functionalDef(TokenType tokenType, functionalRepres repres);
}
#endif // TOKEN_DEFINITION_H