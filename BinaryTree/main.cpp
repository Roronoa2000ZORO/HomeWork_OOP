#include"binaryTree.hpp"


#define HW_1
//#define DEEP_CHEK
int main()
{
    setlocale(LC_ALL, "");

#ifdef HW_1
    Tree tree;
    int n;
    cout << "������� ������ ������: "; cin >> n;
    clock_t c_start = clock();
    for (size_t i = 0; i < n; i++)
    {
        tree.insert(rand() % 100, tree.getRoot());
    }
    clock_t c_end = clock();
    //tree.print(tree.getRoot());
    cout << "  : " << double(c_end - c_start) / CLOCKS_PER_SEC << endl;
    cout << endl;

    c_start = clock();
    cout << "����������� �������� ��������� ������: " << tree.minValue(tree.getRoot()) << endl;
    c_end = clock();
    cout << "  : " << double(c_end - c_start) / CLOCKS_PER_SEC << endl;

    c_start = clock();
    cout << "������������ �������� ��������� ������: " << tree.maxValue(tree.getRoot()) << endl;
    c_end = clock();
    cout << "  : " << double(c_end - c_start) / CLOCKS_PER_SEC << endl;

    c_start = clock();
    cout << "���������� ��������� ��������� ������: " << tree.Count(tree.getRoot()) << endl;
    c_end = clock();
    cout << "  : " << double(c_end - c_start) / CLOCKS_PER_SEC << endl;

    c_start = clock();
    cout << "����� �������� ��������� ��������� ������: " << tree.Sum(tree.getRoot()) << endl;
    c_end = clock();
    cout << "  : " << double(c_end - c_start) / CLOCKS_PER_SEC << endl;

    c_start = clock();
    cout << "������� �������������� ��������� ������: " << tree.Avg(tree.getRoot()) << endl;
    c_end = clock();
    cout << "  : " << double(c_end - c_start) / CLOCKS_PER_SEC << endl;

    c_start = clock();
    cout << "������� ��������� ������: " << tree.Depth(tree.getRoot()) << endl;
    c_end = clock();
    cout << "  : " << double(c_end - c_start) / CLOCKS_PER_SEC << endl;
    UniqueTree u_tree;
    for (size_t i = 0; i < n; i++)
    {
        u_tree.insert(rand() % 100, u_tree.getRoot());
    }

    //u_tree.print(u_tree.getRoot());
    cout << endl;
    cout << "���������� ��������� ��������� ������: " << u_tree.Count(u_tree.getRoot()) << endl;
#endif // HW_1

#ifdef DEEP_CHEK
    Tree tree = { 50, 25, 75, 16, 32, 64, 90, 28 };
    tree.print(tree.getRoot());
    cout << "������� ��������� ������: " << tree.Depth(tree.getRoot()) << endl;
#endif // DEEP_CHEK



    return 0;
}