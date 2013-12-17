#pragma once
class UnitTest
{
public:
	UnitTest(void);
	~UnitTest(void);

	virtual bool DoTest()=0;
};

class UnitTestGroup
{
public:
	UnitTestGroup(void);
	~UnitTestGroup(void);

	virtual bool DoTest()=0;
};

class UnitTester
{
public:
	UnitTester(void);
	~UnitTester(void);

};

//class Adder
//{
//public:
//	int DoAdd(int a_FirstValue, int a_SecondValue)
//	{
//		return a_FirstValue + a_SecondValue;
//	}
//};
//
//class AdderTestUnit
//{
//public:
//	void SetData(int a_FirstValue, int a_SecondValue, int a_ExpectedResult)
//	{
//		m_FirstValue = a_FirstValue;
//		m_SecondValue = a_SecondValue;
//		m_ExpectedResult = a_ExpectedResult;
//	}
//
//	virtual bool DoTest()
//	{
//		Adder add;
//		int iResult = add.DoAdd(m_FirstValue, m_SecondValue);
//		return (iResult == m_ExpectedResult);
//	}
//
//	int m_FirstValue;
//	int m_SecondValue;
//	int m_ExpectedResult;
//};