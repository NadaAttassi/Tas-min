#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <queue>
#include <iomanip> // Pour aligner l'affichage

using namespace std;

template <typename T>
class MinHeap {
private:
    vector<T> heap;

    void heapifyUp(int index);
    void heapifyDown(int index);
    void inorder(int index);
    void preorder(int index);
    void postorder(int index);

    // Fonction pour afficher l'arbre de manière lisible
    void printTree(int index, int space);

public:
    MinHeap() {}

    T getMin() {
        if (heap.empty()) {
            throw runtime_error("Le tas est vide");
        }
        return heap[0];
    }

    void insert(T value);
    T removeMin();
    void display();
    void inorder();
    void preorder();
    void postorder();
    void levelOrder();
};

template <typename T>
void MinHeap<T>::heapifyUp(int index) {
    while (index > 0) {
        int parentIndex = (index - 1) / 2;
        if (heap[parentIndex] > heap[index]) {
            swap(heap[parentIndex], heap[index]);
            index = parentIndex;
        }
        else {
            break;
        }
    }
}

template <typename T>
void MinHeap<T>::heapifyDown(int index) {
    int size = heap.size();
    while (index < size) {
        int leftChild = 2 * index + 1;
        int rightChild = 2 * index + 2;
        int smallest = index;

        if (leftChild < size && heap[leftChild] < heap[smallest]) {
            smallest = leftChild;
        }

        if (rightChild < size && heap[rightChild] < heap[smallest]) {
            smallest = rightChild;
        }

        if (smallest != index) {
            swap(heap[index], heap[smallest]);
            index = smallest;
        }
        else {
            break;
        }
    }
}

template <typename T>
void MinHeap<T>::insert(T value) {
    heap.push_back(value);
    heapifyUp(heap.size() - 1);
}

template <typename T>
T MinHeap<T>::removeMin() {
    if (heap.empty()) {
        throw runtime_error("Le tas est vide");
    }

    T minElement = heap[0];
    heap[0] = heap.back();
    heap.pop_back();
    heapifyDown(0);

    return minElement;
}

template <typename T>
void MinHeap<T>::display() {
    printTree(0, 0);
}

template <typename T>
void MinHeap<T>::printTree(int index, int space) {
    if (index >= heap.size()) return;

    // Ajouter un espace pour une meilleure visualisation
    space += 5;

    // Appeler récursivement pour afficher les enfants à droite
    printTree(2 * index + 2, space);

    cout << endl;
    for (int i = 5; i < space; i++) {
        cout << " ";  // Espaces avant l'affichage de l'élément
    }
    cout << heap[index] << endl;

    // Appeler récursivement pour afficher les enfants à gauche
    printTree(2 * index + 1, space);
}

template <typename T>
void MinHeap<T>::inorder(int index) {
    if (index >= heap.size()) return;

    inorder(2 * index + 1);
    cout << heap[index] << " ";
    inorder(2 * index + 2);
}

template <typename T>
void MinHeap<T>::preorder(int index) {
    if (index >= heap.size()) return;

    cout << heap[index] << " ";
    preorder(2 * index + 1);
    preorder(2 * index + 2);
}

template <typename T>
void MinHeap<T>::postorder(int index) {
    if (index >= heap.size()) return;

    postorder(2 * index + 1);
    postorder(2 * index + 2);
    cout << heap[index] << " ";
}

template <typename T>
void MinHeap<T>::levelOrder() {
    cout << "Parcours Levelorder: ";
    if (heap.empty()) return;

    queue<int> q;
    q.push(0);

    while (!q.empty()) {
        int index = q.front();
        q.pop();

        cout << heap[index] << " ";

        int leftChild = 2 * index + 1;
        int rightChild = 2 * index + 2;

        if (leftChild < heap.size()) q.push(leftChild);
        if (rightChild < heap.size()) q.push(rightChild);
    }
    cout << std::endl;
}

template <typename T>
void MinHeap<T>::inorder() {
    cout << "Parcours Inorder: ";
    inorder(0);
    cout << endl;
}

template <typename T>
void MinHeap<T>::preorder() {
    cout << "Parcours Preorder: ";
    preorder(0);
    cout << endl;
}

template <typename T>
void MinHeap<T>::postorder() {
    cout << "Parcours Postorder: ";
    postorder(0);
    cout << endl;
}
