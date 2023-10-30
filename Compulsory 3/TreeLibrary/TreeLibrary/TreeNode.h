#pragma once

class TreeNode
{
public:
	TreeNode(int data, TreeNode* left = nullptr, TreeNode* right = nullptr);

	int NodeValue;
	TreeNode* Left;
	TreeNode* Right;
};