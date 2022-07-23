/*
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;

    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }

    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }

    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};
*/

class Solution {
public:
    Node* intersect(Node* quadTree1, Node* quadTree2) {
        if (quadTree1 == nullptr || quadTree2 == nullptr)
            return nullptr;
        Node* node = new Node(quadTree1->val || quadTree2->val, quadTree1->isLeaf && quadTree2->isLeaf);
        if (node->isLeaf)
            return node;
        node->topLeft = intersect(quadTree1->isLeaf ? quadTree1 : quadTree1->topLeft, quadTree2->isLeaf ? quadTree2 : quadTree2->topLeft);
        node->topRight = intersect(quadTree1->isLeaf ? quadTree1 : quadTree1->topRight, quadTree2->isLeaf ? quadTree2 : quadTree2->topRight);
        node->bottomLeft = intersect(quadTree1->isLeaf ? quadTree1 : quadTree1->bottomLeft, quadTree2->isLeaf ? quadTree2 : quadTree2->bottomLeft);
        node->bottomRight = intersect(quadTree1->isLeaf ? quadTree1 : quadTree1->bottomRight, quadTree2->isLeaf ? quadTree2 : quadTree2->bottomRight);
        if (node->topLeft->isLeaf && node->topRight->isLeaf && node->bottomLeft->isLeaf && node->bottomRight->isLeaf)
        {
            int leafsum = (int)node->topLeft->val + (int)node->topRight->val + (int)node->bottomLeft->val + (int)node->bottomRight->val;
            if (leafsum == 0 || leafsum == 4)
            {
                node->val = (bool)leafsum;
                node->isLeaf = true;
                delete node->topLeft; delete node->topRight; delete node->bottomLeft; delete node->bottomRight;
                node->topLeft = node->topRight = node->bottomLeft = node->bottomRight = nullptr;
            }
        }
        return node;
    }
};