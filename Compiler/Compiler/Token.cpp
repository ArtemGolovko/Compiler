#include "Token.h"

namespace Compiler
{

	TokenType::TokenType(std::string type)
		: m_type(type)
	{
	}

	std::string TokenType::getStrType() const
	{
		return m_type;
	}

	bool TokenType::operator==(const TokenType& other)
	{
		return m_type == other.m_type;
	}

	bool TokenType::operator!=(const TokenType& other)
	{
		return m_type != other.m_type;
	}

	bool TokenType::operator>(const TokenType& other)
	{
		return m_type > other.m_type;
	}

	bool TokenType::operator<(const TokenType& other)
	{
		return m_type < other.m_type;
	}

	Token::Token(TokenType type, std::string value)
		: m_type(type), m_value(value)
	{
	}

	TokenType Token::getType() const
	{
		return m_type;
	}

	std::string Token::getValue() const
	{
		return m_value;
	}

	bool Token::isInvalid()
	{
		return m_type == INVALID_TOKEN;
	}
}