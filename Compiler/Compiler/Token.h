#include <string>
#include <regex>

#ifndef TOKEN_H
#define TOKEN_H

namespace Compiler
{
	class TokenType
	{
	private:
		std::string m_type;
	public:
		TokenType(std::string type);
		std::string getStrType() const; // for Debug

		bool operator==(const TokenType& other);
		bool operator!=(const TokenType& other);
		bool operator>(const TokenType& other);
		bool operator<(const TokenType& other);
	};

	const TokenType INVALID_TOKEN = TokenType("INVALID_TOKEN");

	class Token
	{
	private:
		TokenType m_type;
		std::string m_value; // TODO: Make int to reference to row of char table
	public:
		Token(TokenType type, std::string value);
		TokenType getType() const;
		std::string getValue() const;
		bool isInvalid();
	};
}
#endif // TOKEN_H