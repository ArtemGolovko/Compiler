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

	class Token
	{
	private:
		TokenType m_type;
		std::string m_value; // TODO: Make int to reference to row of char table
	public:
		Token(TokenType type, std::string value);
		TokenType getType() const;
		std::string getValue() const;
	};

	template<typename T>
	class TokenDefinition
	{
	private:
		TokenType m_type;
		T m_representation;
	public:
		TokenDefinition(TokenType type, T represantation)
			: m_type(type), m_representation(represantation)
		{
		};
		TokenType getType() const { return m_type; }
		T getRepres() const { return m_representation; }
	};

	class StaticTokenDefinition : public TokenDefinition<std::string>
	{
	public:
		StaticTokenDefinition(TokenType type, std::string represantation)
			: TokenDefinition<std::string>(type, represantation)
		{
		}
	};

	class DynamicTokenDefinition : public TokenDefinition<std::regex>
	{
	public:
		DynamicTokenDefinition(TokenType type, std::string represantation)
			: TokenDefinition<std::regex>(type, std::regex(represantation))
		{
		}
	};
}
#endif // TOKEN_H