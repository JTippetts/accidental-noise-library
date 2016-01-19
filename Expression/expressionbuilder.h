#ifndef EXPRESSIONBUILDER_H
#define EXPRESSIONBUILDER_H

#include "parsing.h"
#include "../VM/kernel.h"
#include "../VM/random_gen.h"
#include <vector>
#include <string>

namespace anl
{
class CExpressionBuilder
{
public:
	CExpressionBuilder(CKernel &kernel);
	~CExpressionBuilder();

	CInstructionIndex eval(const std::string &expr);
	std::vector<Token> getPostfix(const std::string &expr);
	void setRandomSeed(unsigned int seed);

private:
	CKernel &kernel_;
	std::vector<CInstructionIndex> index_;
	std::map<std::string, int> f_;  // Functions
	std::vector<std::string> vars_;
	KISS prng_;

	void buildFunction(const std::string &token, std::stack<CInstructionIndex> &stk);
	void buildVar(const std::string &token, std::stack<CInstructionIndex> &stk);
};
};

#endif
