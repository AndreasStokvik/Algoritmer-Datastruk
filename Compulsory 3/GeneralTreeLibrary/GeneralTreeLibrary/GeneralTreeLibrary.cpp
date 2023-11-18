#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>


/**
 * @brief Represents a node in a tree.
 * @tparam T The type of data stored in the node.
 */
template <typename T>
class TreeNode {
public:
    T data;
    std::vector<TreeNode*> children;

    /**
     * @brief Constructor for the TreeNode class.
     * @param value The value to be stored in the node.
     */
    TreeNode(const T& value) : data(value) {}

    /**
     * @brief Destructor for the TreeNode class.
     * Deletes all child nodes.
     */
    ~TreeNode() {
        for (TreeNode* child : children) {
            delete child;
        }
    }

    /**
     * @brief Checks if the node is a leaf node (has no children).
     * @return True if the node is a leaf, false otherwise.
     */
    bool isLeaf() const {
        return children.empty();
    }
};


/**
 * @brief Represents a tree data structure.
 * @tparam T The type of data stored in the tree.
 */
template <typename T>
class Tree {
public:
    TreeNode<T>* root;

    /**
     * @brief Constructor for the Tree class.
     * Initializes the root to nullptr and seeds the random number generator.
     */
    Tree() : root(nullptr) {
        std::srand(static_cast<unsigned>(std::time(nullptr)));
    }

    /**
     * @brief Destructor for the Tree class.
     * Deletes the entire tree.
     */
    ~Tree() {
        delete root;
    }


    /**
     * @brief Inserts a new node with the given value into the tree.
     * @param value The value to be inserted.
     * @param parent The parent node under which the new node will be added as a child.
     */
    void insert(const T& value, TreeNode<T>* parent = nullptr) {

        TreeNode<T>* newNode = new TreeNode<T>(value);  // Creates a new node with a value

        if (!root) {
            root = newNode;     // If the root is yet to change from being a nullptr, the new node will be set as the root.
        }
        else {
            if (!parent) {
                std::cerr << "Parent is null. Cannot insert node." << std::endl;
                delete newNode;
                return;
            }

            parent->children.push_back(newNode);    // New node is added as a child of the specified parent.
        }
    }

    /**
    * @brief Prints the structure of the tree.
    */
    void print(TreeNode<T>* node, int depth = 0) const {
        if (!node) return;

        for (int i = 0; i < depth; ++i) {
            std::cout << "  ";  // This is just indentation
        }

        std::cout << node->data << std::endl;   // Prints data

        for (TreeNode<T>* child : node->children) {
            print(child, depth + 1);
        }
    }

    /**
    * @brief Initiates printing the structure of the tree.
    */
    void printTree() const {
        print(root);
    }

    /**
    * @brief Prints root data if root is found
    */
    void getRoot() const {
        if (!root) {
            std::cout << "No root found..." << std::endl;
            return;
        }

        std::cout << root->data << std::endl;   // Prints data
    }

    /**
    * @brief Checks if tree is empty and prints the answer.
    */
    void isEmpty() const {
        if (!root) {
            std::cout << "Tree is empty" << std::endl;
            return;
        }

        std::cout << "Tree is not empty" << std::endl;
    }

    /**
     * @brief Helper function to recursively find the parent of a node.
     * @param current The current node being examined.
     * @param value The value of the node whose parent is being searched.
     * @return Pointer to the parent node if found, nullptr otherwise.
     */
    TreeNode<T>* getParentHelper(TreeNode<T>* current, const T& value) const {
        if (!current) return nullptr;

        for (TreeNode<T>* child : current->children) {
            if (child->data == value) {
                return current;
            }

            TreeNode<T>* parent = getParentHelper(child, value);
            if (parent) {
                return parent;
            }
        }

        return nullptr;
    }

    /**
     * @brief Finds and returns the parent node of a node with the specified value.
     * @param value The value of the node whose parent is being searched.
     * @return Pointer to the parent node if found, nullptr otherwise.
     */
    TreeNode<T>* getParent(const T& value) const {
        return getParentHelper(root, value);
    }

    /**
     * @brief Initiates getParent and prints the result.
     * @param valueToFindParent The value of the node whose parent is being searched.
     */
    void searchForParent(int valueToFindParent) {
        TreeNode<int>* parentNode = getParent(valueToFindParent);

        if (parentNode) {
            std::cout << "Parent of node " << valueToFindParent << " is " << parentNode->data << std::endl;
        }
        else {
            std::cout << "Node " << valueToFindParent << " has no parent or is not found in the tree." << std::endl;
        }
    }


    /**
    * @brief Helper function to recursively find and collect children of a node with a specified value.
    * @param current The current node being examined.
    * @param value The value of the node whose children are being searched.
    * @return A vector containing pointers to the children nodes if found, an empty vector otherwise.
    * The vector may include children from multiple levels of the tree.
    * @tparam T Type of data stored in the nodes.
    */
    std::vector<TreeNode<T>*> getChildrenHelper(TreeNode<T>* current, const T& value) const {
        std::vector<TreeNode<T>*> result;

        if (!current) return result;

        if (current->data == value) {
            return current->children;
        }

        for (TreeNode<T>* child : current->children) {
            std::vector<TreeNode<T>*> childResult = getChildrenHelper(child, value);
            result.insert(result.end(), childResult.begin(), childResult.end());
        }

        return result;
    }

    /**
    * @brief Finds and returns the children of the node with the specified value.
    * @param value The value of the node whose children are being searched.
    * @return A vector containing pointers to the children nodes if found, an empty vector otherwise.
    * The vector may include children from multiple levels of the tree.
    * @tparam T Type of data stored in the nodes.
    */
    std::vector<TreeNode<T>*> getChildren(const T& value) const {
        return getChildrenHelper(root, value);
    }

    /**
     * @brief Initiates getParent and prints the result.
     * @param valueToFindChildren The value of the node whose children is being searched.
     */
    void searchForChildren(int valueToFindChildren) {
        std::vector<TreeNode<int>*> children = getChildren(valueToFindChildren);

        if (!children.empty()) {
            std::cout << "Children of node " << valueToFindChildren << ": ";
            for (TreeNode<int>* child : children) {
                std::cout << child->data << " ";
            }
            std::cout << std::endl;
        }
        else {
            std::cout << "Node " << valueToFindChildren << " has no children or is not found in the tree." << std::endl;
        }
    }

    /**
    * @brief Recursively calculates and returns the size (number of nodes) of the subtree rooted at the given node.
    * @param node Pointer to the root of the subtree for which the size is calculated.
    * @return The number of nodes in the subtree, including the current node.
    * Returns 0 if the input node is nullptr.
    * @tparam T Type of data stored in the nodes.
    */
    int size(TreeNode<T>* node) const {
        if (!node) {
            return 0;
        }

        int count = 1; // Count the current node

        for (TreeNode<T>* child : node->children) {
            count += size(child);
        }

        return count;
    }

    /**
     * @brief Initiates size and returns the result.
     */
    int size() const {
        return size(root);
    }

    /**
    * @brief Recursively calculates and returns the depth of the subtree rooted at the given node.
    * @param node Pointer to the root of the subtree for which the depth is calculated.
    * @return The depth of the subtree, which is the length of the longest path from the root to a leaf node.
    * Returns 0 if the input node is nullptr.
    * @tparam T Type of data stored in the nodes.
    */
    int depth(TreeNode<T>* node) const {
        if (!node) {
            return 0;
        }
        else {
            int maxChildDepth = 0;
            for (TreeNode<T>* child : node->children) {
                int childDepth = depth(child);
                if (childDepth > maxChildDepth) {
                    maxChildDepth = childDepth;
                }
            }
            return 1 + maxChildDepth;
        }
    }

    /**
     * @brief Initiates depth and returns the result.
     */
    int treeDepth() const {
        return depth(root);
    }

    /**
    * @brief Checks if a given value matches the data of the tree's root.
    * @param compareToRoot The value to compare with the root's data.
    * Prints a message indicating whether the comparison is successful or not.
    */
    void isRoot(int compareToRoot) {
        if (root != nullptr and compareToRoot == root->data) {
            std::cout << compareToRoot << " matches the Tree's root: " << root->data << std::endl;
        }
        else {
            std::cout << compareToRoot << " does not match the Tree's root: " << root->data << std::endl;
        }
    }

    /**
    * @brief Checks if a node with the specified value is a leaf node in the tree.
    * @param value The value of the node to check.
    * @return True if the node is a leaf, false otherwise.
    */
    bool isLeaf(const T& value) const {
        return isLeaf(root, value);
    }

    /**
    * @brief Recursively checks if a node with the specified value is a leaf node in the subtree.
    * @param node Pointer to the root of the subtree.
    * @param value The value of the node to check.
    * @return True if the node is a leaf, false otherwise.
    */
    bool isLeaf(TreeNode<T>* node, const T& value) const {
        if (!node) {
            return false;
        }

        if (node->data == value) {
            return node->isLeaf();
        }

        for (TreeNode<T>* child : node->children) {
            if (isLeaf(child, value)) {
                return true;
            }
        }

        return false;
    }

    /**
    * @brief Prints whether a node with a specified value is a leaf or not.
    * @param valueToCheck The value of the node to check.
    * Prints the result.
    */
    void checkIsLeaf(int valueToCheck) {
        std::cout << "Node with value " << valueToCheck << " is " << (isLeaf(valueToCheck) ? "" : "not ") << "a leaf" << std::endl;
    }

    /**
    * @brief Inserts a new node with the specified value into the tree, choosing a random parent.
    * If the tree is empty, the new node becomes the root.
    * @param value The value to be inserted.
    */
    void insertRandom(const T& value) {
        if (!root) {
            root = new TreeNode<T>(value);
        }
        else {
            // Get a random parent node
            TreeNode<T>* randomParent = getRandomNode(root);

            // insert the new node as a child of the random parent
            insert(value, randomParent);
        }
    }
       
    /**
     * @brief Gets a random node from the tree.
     * @param node The root of the subtree to choose from.
     * @return A pointer to a randomly selected node from the tree.
     */
    TreeNode<T>* getRandomNode(TreeNode<T>* node) {
        std::vector<TreeNode<T>*> nodes;
        flattenTree(node, nodes);

        std::size_t randomIndex = std::rand() % nodes.size();

        return nodes[randomIndex];
    }

    /**
     * @brief Flattens the tree into a vector of nodes.
     * @param node The root of the subtree to flatten.
     * @param nodes The vector to store the flattened nodes.
     */
    void flattenTree(TreeNode<T>* node, std::vector<TreeNode<T>*>& nodes) {
        if (!node) return;

        nodes.push_back(node);

        for (TreeNode<T>* child : node->children) {
            flattenTree(child, nodes);
        }
    }

    /**
     * @brief Finds and returns a pointer to the node with the specified value in the tree.
     * @param node The root of the subtree to search.
     * @param value The value of the node to find.
     * @return A pointer to the node if found, nullptr otherwise.
     */
    TreeNode<T>* findNode(TreeNode<T>* node, const T& value) const {
        if (!node) return nullptr;

        if (node->data == value) {
            return node;
        }

        for (TreeNode<T>* child : node->children) {
            TreeNode<T>* result = findNode(child, value);
            if (result) {
                return result;
            }
        }

        return nullptr;
    }

    /**
     * @brief Deletes the node with the specified value from the tree.
     * @param value The value of the node to delete.
     * Prints an error message if the node is not found.
     */
    void deleteNode(const T& value) {
        TreeNode<T>* nodeToDelete = findNode(root, value);

        if (!nodeToDelete) {
            std::cerr << "Node with value " << value << " not found." << std::endl;
            return;
        }

        if (nodeToDelete == root) {
            // if the root is being deleted, update the root
            root = nullptr;
        }
        else {
            TreeNode<T>* parent = findParent(root, value);
            if (parent) {
                auto& siblings = parent->children;
                siblings.erase(std::remove(siblings.begin(), siblings.end(), nodeToDelete), siblings.end());
            }
        }

        delete nodeToDelete;
        nodeToDelete = nullptr;
    }

    /**
     * @brief Finds and returns the parent node of the node with the specified value.
     * @param node The root of the subtree to search.
     * @param value The value of the node whose parent is being searched.
     * @return A pointer to the parent node if found, nullptr otherwise.
     */
    TreeNode<T>* findParent(TreeNode<T>* node, const T& value) const {
        if (!node || node->children.empty()) {
            return nullptr;
        }

        for (TreeNode<T>* child : node->children) {
            if (child->data == value) {
                return node;
            }
            else {
                TreeNode<T>* result = findParent(child, value);
                if (result) {
                    return result;
                }
            }
        }

        return nullptr;
    }
};



int main() {
    Tree<int> tree;

    tree.insert(1);
    tree.insert(2, tree.root);
    tree.insert(3, tree.root);
    tree.insert(4, tree.root->children[0]);
    tree.insert(5, tree.root->children[0]);
    tree.insert(6, tree.root->children[1]);
    tree.insert(7, tree.root->children[1]->children[0]);
    tree.insert(10, tree.root->children[1]->children[0]->children[0]);
    tree.insert(17, tree.root->children[1]->children[0]->children[0]);

    std::cout << "Tree structure:" << std::endl;
    tree.printTree();           // print the tree

    std::cout << std::endl;
    std::cout << "Tree root:" << std::endl;
    tree.getRoot();             // get the root of the tree

    std::cout << std::endl;
    tree.searchForParent(5);    // find parent of number specified
    
    std::cout << std::endl;
    tree.searchForChildren(7);  // find children of number specified


    std::cout << std::endl;
    std::cout << "Size of the tree: " << tree.size() << " nodes." << std::endl;     // tree size
    std::cout << "Tree depth: " << tree.treeDepth() << std::endl;                   // tree depth

    tree.isEmpty();     // check if tree is empty

    tree.isRoot(2);

    tree.checkIsLeaf(66);

    std::cout << std::endl;
    std::cout << "Inserting randomly" << std::endl;

    // insert number at random spot in the tree
    tree.insertRandom(16);      

    tree.deleteNode(6);

    std::cout << "New tree structure:" << std::endl;
    tree.printTree();           // print the tree again

    return 0;
}
