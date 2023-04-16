#include"binaryTree.hpp"

int main()
{
    setlocale(LC_ALL, "");

    BinaryTree tree;
    int n;
    cout << "������� ������ ������: "; cin >> n;
    for (size_t i = 0; i < n; i++)
    {
        tree.insert(rand()%100, tree.getRoot());
    }

    tree.print(tree.getRoot());
    cout << endl;

    cout << "����������� �������� ��������� ������: " << tree.minValue(tree.getRoot()) << endl;

    cout << "������������ �������� ��������� ������: " << tree.maxValue(tree.getRoot()) << endl;

    cout << "���������� ��������� ��������� ������: " << tree.Count(tree.getRoot()) << endl;

    cout << "����� �������� ��������� ��������� ������: " << tree.Sum(tree.getRoot()) << endl;
    return 0;
}