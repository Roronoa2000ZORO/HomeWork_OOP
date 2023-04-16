#include"binaryTree.hpp"

int main()
{
    setlocale(LC_ALL, "");

    BinaryTree tree;
    int n;
    cout << "Введите размер дерева: "; cin >> n;
    for (size_t i = 0; i < n; i++)
    {
        tree.insert(rand()%100, tree.getRoot());
    }

    tree.print(tree.getRoot());
    cout << endl;

    cout << "Минимальное значения Бинарного дерева: " << tree.minValue(tree.getRoot()) << endl;

    cout << "Максимальное значения Бинарного дерева: " << tree.maxValue(tree.getRoot()) << endl;

    cout << "Количество элементов Бинарного дерева: " << tree.Count(tree.getRoot()) << endl;

    cout << "Сумма значений элементов Бинарного дерева: " << tree.Sum(tree.getRoot()) << endl;
    return 0;
}