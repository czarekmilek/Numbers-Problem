#include <iostream>
#include <climits>

struct Node {
    long long key;
    Node* left;
    Node* right;
    int height;

    Node(long long k) : key(k), left(nullptr), right(nullptr), height(1) {}
};

int height(Node* n) {
    return n ? n->height : 0;
}

int balanceFactor(Node* n) {
    return n ? height(n->left) - height(n->right) : 0;
}

void updateHeight(Node* n) {
    if (n) {
        n->height = 1 + std::max(height(n->left), height(n->right));
    }
}

Node* rotateRight(Node* y) {
    Node* x = y->left;
    Node* T2 = x->right;

    x->right = y;
    y->left = T2;

    updateHeight(y);
    updateHeight(x);

    return x;
}

Node* rotateLeft(Node* x) {
    Node* y = x->right;
    Node* T2 = y->left;

    y->left = x;
    x->right = T2;

    updateHeight(x);
    updateHeight(y);

    return y;
}

Node* balance(Node* n) {
    updateHeight(n);
    int bf = balanceFactor(n);

    if (bf > 1) {
        if (balanceFactor(n->left) < 0) {
            n->left = rotateLeft(n->left);
        }
        return rotateRight(n);
    } else if (bf < -1) {
        if (balanceFactor(n->right) > 0) {
            n->right = rotateRight(n->right);
        }
        return rotateLeft(n);
    }

    return n;
}

Node* insert(Node* node, long long key) {
    if (!node) return new Node(key);

    if (key < node->key) {
        node->left = insert(node->left, key);
    } else if (key > node->key) {
        node->right = insert(node->right, key);
    } else {
        return node;
    }

    return balance(node);
}

Node* minValueNode(Node* node) {
    Node* current = node;
    while (current && current->left) {
        current = current->left;
    }
    return current;
}

Node* deleteNode(Node* root, long long key) {
    if (!root) return root;

    if (key < root->key) {
        root->left = deleteNode(root->left, key);
    } else if (key > root->key) {
        root->right = deleteNode(root->right, key);
    } else {
        if (!root->left || !root->right) {
            Node* temp = root->left ? root->left : root->right;
            if (!temp) {
                temp = root;
                root = nullptr;
            } else {
                *root = *temp;
            }
            delete temp;
        } else {
            Node* temp = minValueNode(root->right);
            root->key = temp->key;
            root->right = deleteNode(root->right, temp->key);
        }
    }

    if (!root) return root;

    return balance(root);
}

bool find(Node* root, long long key) {
    if (!root) return false;
    if (key < root->key) return find(root->left, key);
    if (key > root->key) return find(root->right, key);
    return true;
}

Node* upper(Node* root, long long key) {
    Node* current = root;
    Node* result = nullptr;
    while (current) {
        if (current->key >= key) {
            result = current;
            current = current->left;
        } else {
            current = current->right;
        }
    }
    return result;
}

Node* lower(Node* root, long long key) {
    Node* current = root;
    Node* result = nullptr;
    while (current) {
        if (current->key <= key) {
            result = current;
            current = current->right;
        } else {
            current = current->left;
        }
    }
    return result;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    std::cin >> n;
    Node* root = nullptr;

    while (n--) {
        char op;
        long long x;
        std::cin >> op >> x;
        if (op == 'I') {
            root = insert(root, x);
        } else if (op == 'D') {
            if (find(root, x)) {
                root = deleteNode(root, x);
                std::cout << "OK\n";
            } else {
                std::cout << "BRAK\n";
            }
        } else if (op == 'U') {
            Node* result = upper(root, x);
            if (result) {
                std::cout << result->key << "\n";
            } else {
                std::cout << "BRAK\n";
            }
        } else if (op == 'L') {
            Node* result = lower(root, x);
            if (result) {
                std::cout << result->key << "\n";
            } else {
                std::cout << "BRAK\n";
            }
        }
    }

    return 0;
}
