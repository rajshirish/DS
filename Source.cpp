#include <iostream>

class CMyClass
{
	int m_iNum = 0;
	char *m_pText = nullptr;

public:
	CMyClass(const int &iNum, const char* pText):m_iNum(iNum), m_pText(new char[strlen(pText) + 1])
	{		
		strcpy_s(m_pText, strlen(pText)+1, pText);
	}

	CMyClass(const CMyClass &objThat):m_iNum(objThat.m_iNum)
	{		
		if (nullptr != objThat.m_pText)
		{
			this->m_pText = new char[strlen(objThat.m_pText)];
			strcpy_s(this->m_pText, strlen(objThat.m_pText)+1, objThat.m_pText);
		}
	}
};

class CBase
{
public:
	virtual void fun()
	{
		std::cout << "base" <<std::endl;
	}
};

class CDerived : public CBase
{
public:
	void fun()
	{
		std::cout << "derived" << std::endl;
	}
};

int main()
{
	char pText[] = "test";
	CMyClass obj(1, pText);
	CMyClass obj2 = obj;

	CDerived d1;
	CBase &b1 = d1;
	CBase *pb = &d1;

	b1.fun();

	pb->fun();

	int i = 1;
	while(i)
	{
		i++;
	}
	std::cout << "i = " <<i;

	return 0;
}