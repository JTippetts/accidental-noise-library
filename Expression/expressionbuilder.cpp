#include "expressionbuilder.h"

#include <iostream>
namespace anl
{
	ExpressionBuilder::ExpressionBuilder(CKernel &kernel) : kernel_(kernel)
	{
		f_["valueBasis"]=2;
        f_["gradientBasis"]=2;
        f_["simplexBasis"]=1;
        f_["cellularBasis"]=10;
        f_["max"]=2;
        f_["min"]=2;
        f_["abs"]=1;
        f_["bias"]=2;
        f_["gain"]=2;
        f_["scaleX"]=2;
        f_["scaleY"]=2;
        f_["scaleZ"]=2;
        f_["scaleW"]=2;
        f_["scaleU"]=2;
        f_["scaleV"]=2;
        f_["translateX"]=2;
        f_["translateY"]=2;
        f_["translateZ"]=2;
        f_["translateW"]=2;
        f_["translateU"]=2;
        f_["translateV"]=2;
        f_["rotateDomain"]=5;
        f_["blend"]=3;
        f_["select"]=5;
        f_["clamp"]=3;
        f_["cos"]=1;
        f_["sin"]=1;
        f_["tan"]=1;
        f_["acos"]=1;
        f_["asin"]=1;
        f_["atan"]=1;
        f_["tiers"]=2;
        f_["smoothTiers"]=2;
        f_["dx"]=1;
        f_["dy"]=1;
        f_["dz"]=1;
        f_["dw"]=1;
        f_["du"]=1;
        f_["dv"]=1;
        f_["index"]=1;

        // Build vars
        vars_.push_back("rand");
        vars_.push_back("rand01");
        vars_.push_back("x");
        vars_.push_back("y");
        vars_.push_back("z");
        vars_.push_back("w");
        vars_.push_back("u");
        vars_.push_back("v");
        vars_.push_back("radial");

	}
	ExpressionBuilder::~ExpressionBuilder(){}

	std::vector<Token> ExpressionBuilder::getPostfix(const std::string &expr)
	{
		ExpressionToPostfix e(expr, f_, vars_);
		return e.ToPostfix();
	}

	CInstructionIndex ExpressionBuilder::eval(const std::string &expr)
	{
		ExpressionToPostfix e(expr, f_, vars_);

		auto p=e.ToPostfix();
		std::stack<CInstructionIndex> stk;

		for(auto i : p)
		{
			if(i.GetType()==Token::NUMBER)
			{
				stk.push(kernel_.constant(std::stod(i.GetToken())));
			}
			else if(i.GetType()==Token::OPERATOR)
			{
				CInstructionIndex right=stk.top();
				stk.pop();
				CInstructionIndex left=stk.top();
				stk.pop();
				if(i.GetToken()=="+") stk.push(kernel_.add(left,right));
				else if(i.GetToken()=="-") stk.push(kernel_.subtract(left,right));
				else if(i.GetToken()=="*") stk.push(kernel_.multiply(left,right));
				else if(i.GetToken()=="/") stk.push(kernel_.divide(left,right));
				else if(i.GetToken()=="^") stk.push(kernel_.pow(left,right));
			}
			else if(i.GetType()==Token::UNARYOPERATOR)
			{
				CInstructionIndex o=stk.top();
				stk.pop();
				stk.push(kernel_.multiply(o, kernel_.constant(-1.0)));
			}
			else if(i.GetType()==Token::FUNCTION)
			{
				buildFunction(i.GetToken(), stk);
			}
			else if(i.GetType()==Token::VAR)
			{
			    buildVar(i.GetToken(), stk);
			}
		}

		return stk.top();
	}

	void ExpressionBuilder::buildVar(const std::string &token, std::stack<CInstructionIndex> &stk)
	{
	    if(token=="rand")
        {

        }
        else if (token=="rand01")
        {

        }
        else if (token=="x")
        {
            stk.push(kernel_.x());
        }
        else if (token=="y")
        {
            stk.push(kernel_.y());
        }
        else if (token=="z")
        {
            stk.push(kernel_.z());
        }
        else if (token=="w")
        {
            stk.push(kernel_.w());
        }
        else if (token=="u")
        {
            stk.push(kernel_.u());
        }
        else if (token=="v")
        {
            stk.push(kernel_.v());
        }
        else if (token=="radial")
        {
            stk.push(kernel_.radial());
        }
	}

	void ExpressionBuilder::buildFunction(const std::string &token, std::stack<CInstructionIndex> &stk)
	{
		if(token=="valueBasis")
		{
			CInstructionIndex right=stk.top();
			stk.pop();
			CInstructionIndex left=stk.top();
			stk.pop();
			stk.push(kernel_.valueBasis(left,right));
		}
        else if(token=="gradientBasis")
		{
			CInstructionIndex right=stk.top();
			stk.pop();
			CInstructionIndex left=stk.top();
			stk.pop();
			stk.push(kernel_.gradientBasis(left,right));
		}
        else if(token=="simplexBasis")
		{
			CInstructionIndex o=stk.top();
			stk.pop();
			stk.push(kernel_.simplexBasis(o));
		}
        else if(token=="cellularBasis")
		{
			CInstructionIndex c9=stk.top();
			stk.pop();
			CInstructionIndex c8=stk.top();
			stk.pop();
			CInstructionIndex c7=stk.top();
			stk.pop();
			CInstructionIndex c6=stk.top();
			stk.pop();
			CInstructionIndex c5=stk.top();
			stk.pop();
			CInstructionIndex c4=stk.top();
			stk.pop();
			CInstructionIndex c3=stk.top();
			stk.pop();
			CInstructionIndex c2=stk.top();
			stk.pop();
			CInstructionIndex c1=stk.top();
			stk.pop();
			CInstructionIndex c0=stk.top();
			stk.pop();
			stk.push(kernel_.cellularBasis(c0,c1,c2,c3,c4,c5,c6,c7,c8,c9));
		}
        else if(token=="max")
		{
			CInstructionIndex right=stk.top();
			stk.pop();
			CInstructionIndex left=stk.top();
			stk.pop();
			stk.push(kernel_.maximum(left,right));
		}
        else if(token=="min")
		{
			CInstructionIndex right=stk.top();
			stk.pop();
			CInstructionIndex left=stk.top();
			stk.pop();
			stk.push(kernel_.minimum(left,right));
		}
        else if(token=="abs")
		{
			CInstructionIndex o=stk.top();
			stk.pop();
			stk.push(kernel_.abs(o));
		}
        else if(token=="bias")
		{
			CInstructionIndex right=stk.top();
			stk.pop();
			CInstructionIndex left=stk.top();
			stk.pop();
			stk.push(kernel_.bias(left,right));
		}
        else if(token=="gain")
		{
			CInstructionIndex right=stk.top();
			stk.pop();
			CInstructionIndex left=stk.top();
			stk.pop();
			stk.push(kernel_.gain(left,right));
		}
        else if(token=="scaleX")
		{
			CInstructionIndex right=stk.top();
			stk.pop();
			CInstructionIndex left=stk.top();
			stk.pop();
			stk.push(kernel_.scaleX(left,right));
		}
        else if(token=="scaleY")
		{
			CInstructionIndex right=stk.top();
			stk.pop();
			CInstructionIndex left=stk.top();
			stk.pop();
			stk.push(kernel_.scaleY(left,right));
		}
        else if(token=="scaleZ")
		{
			CInstructionIndex right=stk.top();
			stk.pop();
			CInstructionIndex left=stk.top();
			stk.pop();
			stk.push(kernel_.scaleZ(left,right));
		}
        else if(token=="scaleW")
		{
			CInstructionIndex right=stk.top();
			stk.pop();
			CInstructionIndex left=stk.top();
			stk.pop();
			stk.push(kernel_.scaleW(left,right));
		}
        else if(token=="scaleU")
		{
			CInstructionIndex right=stk.top();
			stk.pop();
			CInstructionIndex left=stk.top();
			stk.pop();
			stk.push(kernel_.scaleU(left,right));
		}
        else if(token=="scaleV")
		{
			CInstructionIndex right=stk.top();
			stk.pop();
			CInstructionIndex left=stk.top();
			stk.pop();
			stk.push(kernel_.scaleV(left,right));
		}
        else if(token=="translateX")
		{
			CInstructionIndex right=stk.top();
			stk.pop();
			CInstructionIndex left=stk.top();
			stk.pop();
			stk.push(kernel_.translateX(left,right));
		}
        else if(token=="translateY")
		{
			CInstructionIndex right=stk.top();
			stk.pop();
			CInstructionIndex left=stk.top();
			stk.pop();
			stk.push(kernel_.translateY(left,right));
		}
        else if(token=="translateZ")
		{
			CInstructionIndex right=stk.top();
			stk.pop();
			CInstructionIndex left=stk.top();
			stk.pop();
			stk.push(kernel_.translateZ(left,right));
		}
        else if(token=="translateW")
		{
			CInstructionIndex right=stk.top();
			stk.pop();
			CInstructionIndex left=stk.top();
			stk.pop();
			stk.push(kernel_.translateW(left,right));
		}
        else if(token=="translateU")
		{
			CInstructionIndex right=stk.top();
			stk.pop();
			CInstructionIndex left=stk.top();
			stk.pop();
			stk.push(kernel_.translateU(left,right));
		}
        else if(token=="translateV")
		{
			CInstructionIndex right=stk.top();
			stk.pop();
			CInstructionIndex left=stk.top();
			stk.pop();
			stk.push(kernel_.translateV(left,right));
		}
        else if(token=="rotateDomain")
		{
			CInstructionIndex c4=stk.top();
			stk.pop();
			CInstructionIndex c3=stk.top();
			stk.pop();
			CInstructionIndex c2=stk.top();
			stk.pop();
			CInstructionIndex c1=stk.top();
			stk.pop();
			CInstructionIndex c0=stk.top();
			stk.pop();
			stk.push(kernel_.rotateDomain(c0,c1,c2,c3,c4));
		}
        else if(token=="blend")
		{
			CInstructionIndex c2=stk.top();
			stk.pop();
			CInstructionIndex c1=stk.top();
			stk.pop();
			CInstructionIndex c0=stk.top();
			stk.pop();
			stk.push(kernel_.blend(c0,c1,c2));
		}
        else if(token=="select")
		{
			CInstructionIndex c4=stk.top();
			stk.pop();
			CInstructionIndex c3=stk.top();
			stk.pop();
			CInstructionIndex c2=stk.top();
			stk.pop();
			CInstructionIndex c1=stk.top();
			stk.pop();
			CInstructionIndex c0=stk.top();
			stk.pop();
			stk.push(kernel_.select(c0,c1,c2,c3,c4));
		}
        else if(token=="clamp")
		{
			CInstructionIndex c2=stk.top();
			stk.pop();
			CInstructionIndex c1=stk.top();
			stk.pop();
			CInstructionIndex c0=stk.top();
			stk.pop();
			stk.push(kernel_.clamp(c0,c1,c2));
		}
        else if(token=="cos")
		{
			CInstructionIndex o=stk.top();
			stk.pop();
			stk.push(kernel_.cos(o));
		}
        else if(token=="sin")
		{
			CInstructionIndex o=stk.top();
			stk.pop();
			stk.push(kernel_.sin(o));
		}
        else if(token=="tan")
		{
			CInstructionIndex o=stk.top();
			stk.pop();
			stk.push(kernel_.tan(o));
		}
        else if(token=="acos")
		{
			CInstructionIndex o=stk.top();
			stk.pop();
			stk.push(kernel_.acos(o));
		}
        else if(token=="asin")
		{
			CInstructionIndex o=stk.top();
			stk.pop();
			stk.push(kernel_.asin(o));
		}
        else if(token=="atan")
		{
			CInstructionIndex o=stk.top();
			stk.pop();
			stk.push(kernel_.atan(o));
		}
        else if(token=="tiers")
		{
			CInstructionIndex right=stk.top();
			stk.pop();
			CInstructionIndex left=stk.top();
			stk.pop();
			stk.push(kernel_.tiers(left,right));
		}
        else if(token=="smoothTiers")
		{
			CInstructionIndex right=stk.top();
			stk.pop();
			CInstructionIndex left=stk.top();
			stk.pop();
			stk.push(kernel_.smoothTiers(left,right));
		}
        else if(token=="dx")
		{
			CInstructionIndex right=stk.top();
			stk.pop();
			CInstructionIndex left=stk.top();
			stk.pop();
			stk.push(kernel_.dx(left,right));
		}
        else if(token=="dy")
		{
			CInstructionIndex right=stk.top();
			stk.pop();
			CInstructionIndex left=stk.top();
			stk.pop();
			stk.push(kernel_.dy(left,right));
		}
        else if(token=="dz")
		{
			CInstructionIndex right=stk.top();
			stk.pop();
			CInstructionIndex left=stk.top();
			stk.pop();
			stk.push(kernel_.dz(left,right));
		}
        else if(token=="dw")
		{
			CInstructionIndex right=stk.top();
			stk.pop();
			CInstructionIndex left=stk.top();
			stk.pop();
			stk.push(kernel_.dw(left,right));
		}
        else if(token=="du")
		{
			CInstructionIndex right=stk.top();
			stk.pop();
			CInstructionIndex left=stk.top();
			stk.pop();
			stk.push(kernel_.du(left,right));
		}
        else if(token=="dv")
		{
			CInstructionIndex right=stk.top();
			stk.pop();
			CInstructionIndex left=stk.top();
			stk.pop();
			stk.push(kernel_.dv(left,right));
		}
        else if(token=="index")
		{
		}
	}
};
