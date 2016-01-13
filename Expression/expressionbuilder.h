#ifndef EXPRESSIONBUILDER_H
#define EXPRESSIONBUILDER_H

#include "parsing.h"
#include "../VM/kernel.h"
#include <vector>
#include <string>

namespace anl
{
class ExpressionBuilder
{
public:
	ExpressionBuilder(CKernel &kernel);
	~ExpressionBuilder();

	CInstructionIndex eval(const std::string &expr);
	std::vector<Token> getPostfix(const std::string &expr);

private:
	CKernel &kernel_;
	std::vector<CInstructionIndex> index_;
	std::map<std::string, int> f_;  // Functions
	std::vector<std::string> vars_;

	void buildFunction(const std::string &token, std::stack<CInstructionIndex> &stk);
	void buildVar(const std::string &token, std::stack<CInstructionIndex> &stk);
};
};

#endif
