#pragma once
#include "iostream"
#include "TreeNode.h"


class Tree 
{
public:
	Tree();
	~Tree();

	void Insert(int value);
	void Erase(int value);
	void Clear();
	bool Find(int value);

	friend std::ostream& operator <<(std::ostream& ostr, const Tree& rhs);
private:
	TreeNode* Start;

	std::ostream& Print(std::ostream& ostr, TreeNode* rhs) const;
	void DeleteNodeAfterChildren(TreeNode* Node);
};