#include "Tree.h"

Tree::Tree()
	: Start(nullptr)
{
}

Tree::~Tree()
{
	Clear();
}

void Tree::Insert(int value)
{
	if (Start == nullptr) {
		Start = new TreeNode(value);
	}
	else
	{
		TreeNode* Current = Start;
		while (true)
		{
			if (value < Current->NodeValue) {
				if (Current->Left == nullptr) {
					Current->Left = new TreeNode(value);
					break;
				}
				else {
					Current = Current->Left;
				}
			}
			else if (value > Current->NodeValue) {
				if (Current->Right == nullptr) {
					Current->Right = new TreeNode(value);
					break;
				}
				else {
					Current = Current->Right;
				}
			}
			else {
				break;
			}
		}
	}
}

void Tree::Erase(int value)
{
	TreeNode* temp = Start, * parent = Start, * marker;
	if (temp == NULL)
	{
		throw std::exception("Tree is empty");
	}
	else {
		while (temp != NULL && temp->NodeValue != value) {
			parent = temp;
			if (temp->NodeValue < value) {
				temp = temp->Right;
			}
			else {
				temp = temp->Left;
			}
		}
	}
	marker = temp;
	if (temp == NULL){}
	else if (temp == Start) {
		if (temp->Right == NULL && temp->Left == NULL) {
			Start = NULL;
		}
		else if (temp->Left == NULL) {
			Start = temp->Right;
		}
		else if (temp->Right == NULL) {
			Start = temp->Left;
		}
		else {
			TreeNode* temp1;
			temp1 = temp->Right;
			while (temp1->Left != NULL) {
				temp = temp1;
				temp1 = temp1->Left;
			}
			if (temp1 != temp->Right) {
				temp->Left = temp1->Right;
				temp1->Right = Start->Right;
			}
			temp1->Left = Start->Left;
			Start = temp1;
		}
	}
	else {
		if (temp->Right == NULL && temp->Left == NULL) {
			if (parent->Right == temp) parent->Right = NULL;
			else parent->Left = NULL;
		}
		else if (temp->Left == NULL) {
			if (parent->Right == temp) parent->Right = temp->Right;
			else parent->Left = temp->Right;
		}
		else if (temp->Right == NULL) {
			if (parent->Right == temp) parent->Right = temp->Left;
			else parent->Left = temp->Left;
		}
		else {
			TreeNode* temp1;
			parent = temp;
			temp1 = temp->Right;
			while (temp1->Left != NULL) {
				parent = temp1;
				temp1 = temp1->Left;
			}
			if (temp1 != temp->Right) {
				temp->Left = temp1->Right;
				temp1->Right = parent->Right;
			}
			temp1->Left = parent->Left;
			parent = temp1;
		}
	}
	delete marker;
}

void Tree::Clear()
{
	DeleteNodeAfterChildren(Start);
	Start = nullptr;
}

bool Tree::Find(int value)
{
	TreeNode* Current = Start;
	while (Current != nullptr) {
		if (Current->NodeValue == value) {
			return true;
		}
		else if (Current->NodeValue > value) {
			Current = Current->Left;
		}
		else {
			Current = Current->Right;
		}
	}
	return false;
}

std::ostream& Tree::Print(std::ostream& ostr, TreeNode* rhs) const
{
	if (rhs != nullptr) {
		Print(ostr, rhs->Left);
		std::cout << " " << rhs->NodeValue;
		Print(ostr, rhs->Right);
	}
	return ostr;
}

void Tree::DeleteNodeAfterChildren(TreeNode* Node)
{
	if (Node != nullptr)
	{
		DeleteNodeAfterChildren(Node->Left);
		DeleteNodeAfterChildren(Node->Right);
		delete Node;
	}
}

std::ostream& operator<<(std::ostream& ostr, const Tree& rhs)
{
	return rhs.Print(ostr, rhs.Start);
}
