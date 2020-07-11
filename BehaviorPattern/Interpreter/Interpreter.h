#pragma once
/*/////////////////////////////////////////////////
//说明：解释器模式实例
//文件：Interpreter.h
//日期：2020/7/1
//作者：coder
//QQ: 375187588
//修改:
//版本:
*//////////////////////////////////////////////////

typedef std::string Context;

//抽象表达
class CAbstractExpression
{
public:
	CAbstractExpression() {}
	virtual ~CAbstractExpression() {}
	//解释说话
	virtual void Interpreter(const Context& context) = 0;
};

//终止表达
class CTerminalExpression : public CAbstractExpression
{
public:
	CTerminalExpression(char c)
	{
		m_cKeyChar = c;
	}
	~CTerminalExpression()
	{
	}

	virtual void Interpreter(const Context& context)
	{
		int length = 0;
		while (context[length] != '\0')
		{
			length++;
		}
		int numberArray[100];
		int index = 0;
		for (int i = 0; i < length; i++)
		{
			if (m_cKeyChar == context[i])
			{
				numberArray[index++] = i;
			}
		}
		for (int i = 0; i < index; i++)
		{
			std::cout << numberArray[i];
		}

		std::cout << std::endl;
	}

private:
	char m_cKeyChar;
};

//不表达
class CNonterminalExpression : public CAbstractExpression
{
public:
	CNonterminalExpression(CAbstractExpression* pExpression)
	{
		m_pTerminalExpression = pExpression;
	}
	~CNonterminalExpression() 
	{
	}
	virtual void Interpreter(const Context& context)
	{
		std::cout << "CNonterminalExpression 说: ";
		m_pTerminalExpression->Interpreter(context);
	}

private:
	CAbstractExpression* m_pTerminalExpression;
};
