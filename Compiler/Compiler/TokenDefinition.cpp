#include "TokenDefinition.h"

namespace Compiler
{
	TokenDefinition::TokenDefinition(TokenType tokenType, std::any represantation, TokenDefinitionType type)
		: m_tokenType(tokenType), m_representation(represantation), m_type(type)
	{};

	TokenType TokenDefinition::getTokenType() const
	{
		return m_tokenType;
	}

	std::any TokenDefinition::getRepres() const
	{
		return m_representation;
	}

	TokenDefinitionType TokenDefinition::getType() const
	{
		return m_type;
	}

	TokenDefinition make_staticDef(TokenType tokenType, std::string repres)
	{
		return TokenDefinition(tokenType, repres, TokenDefinitionType::STATIC);
	}

	TokenDefinition make_dynamicDef(TokenType tokenType, std::string repres)
	{
		return TokenDefinition(tokenType, std::regex(repres), TokenDefinitionType::DYNAMIC);
	}

	TokenDefinition make_functionalDef(TokenType tokenType, functionalRepres repres)
	{
		return TokenDefinition(tokenType, repres, TokenDefinitionType::FUNCTIONAL);
	}
}