#include <iostream>
#include <vector>
using namespace std;

struct stNode
{
	int iData = 0;
	int iLevel = 0;
	stNode *pParent = nullptr;
	stNode *pLeft = nullptr;
	stNode *pRigt = nullptr;
};

class CBtree
{
	
};


stNode* InsertNode(stNode *pNode, const int &iData, int iLevel)
{
	if(nullptr == pNode)
	{
		iLevel++;
		pNode = new stNode();
		pNode->iData = iData;
		pNode->iLevel = iLevel;
		
	}
	else
	{		
		if (iData <= pNode->iData)
		{
			pNode->pLeft = InsertNode(pNode->pLeft, iData, pNode->iLevel);
			pNode->pLeft->pParent = pNode;			
		}
		else 
		{
			pNode->pRigt = InsertNode(pNode->pRigt, iData, pNode->iLevel);
			pNode->pRigt->pParent = pNode;			
		}		
	}
	
	return pNode;
}

void PreOrder(stNode *pNode)
{
	if (nullptr != pNode)
	{
		PreOrder(pNode->pLeft);
		cout << pNode->iData << " ";;
		PreOrder(pNode->pRigt);
	}
}

stNode* GetLevel(stNode *pNode, const int &iData, bool &bFound)
{
	if (nullptr != pNode && false == bFound)
	{
		stNode *pNodeLocal = nullptr;
		pNodeLocal = GetLevel(pNode->pLeft, iData, bFound);
		if (nullptr != pNode && pNode->iData == iData)
		{
			bFound = true;					
		}
		if(nullptr != pNode && false == bFound)
			pNodeLocal = GetLevel(pNode->pRigt, iData, bFound);
		if (bFound && pNodeLocal)
		{
			return pNodeLocal;
		}
	}
	return pNode;
}

int PrintC(stNode *pNode, stNode *pParent, const int &iLevel)
{
	if (nullptr != pNode)
	{
		PrintC(pNode->pLeft, pParent, iLevel);
		if (pNode->iLevel == iLevel && pNode->pParent != pParent)
		{
			cout<< "Cousin"<< pNode->iData << " ";
			return 0;
		}
		PrintC(pNode->pRigt, pParent, iLevel);
	}
	return 0;
}

int main()
{
	int iInputData = 0;
	stNode *pRoot = nullptr;
	int ilevel = -1;
	vector<int> vecInp = {5, 7, 8, 6, 2, 1, 3};
	for (auto iter : vecInp)
	{
		//cin >> iInputData;
				
		pRoot = InsertNode(pRoot, iter, ilevel);
	}
	//PreOrder(pRoot);
	bool bfound = false;
	stNode *pNode = GetLevel(pRoot, 3, bfound);
	if(pNode)
		PrintC(pRoot, pNode->pParent, pNode->iLevel);

	return 0;
}