#include"binaryTree.hpp"


//#define HW_1
#define DEEP_CHEK
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
        tree.insert(rand() % 100);
    }
    clock_t c_end = clock();
    tree.print();
    cout << "  : " << double(c_end - c_start) / CLOCKS_PER_SEC << endl;
    cout << endl;

    c_start = clock();
    cout << "����������� �������� ��������� ������: " << tree.minValue() << endl;
    c_end = clock();
    cout << "  : " << double(c_end - c_start) / CLOCKS_PER_SEC << endl;

    c_start = clock();
    cout << "������������ �������� ��������� ������: " << tree.maxValue() << endl;
    c_end = clock();
    cout << "  : " << double(c_end - c_start) / CLOCKS_PER_SEC << endl;

    c_start = clock();
    cout << "���������� ��������� ��������� ������: " << tree.Count() << endl;
    c_end = clock();
    cout << "  : " << double(c_end - c_start) / CLOCKS_PER_SEC << endl;

    c_start = clock();
    cout << "����� �������� ��������� ��������� ������: " << tree.Sum() << endl;
    c_end = clock();
    cout << "  : " << double(c_end - c_start) / CLOCKS_PER_SEC << endl;

    c_start = clock();
    cout << "������� �������������� ��������� ������: " << tree.Avg() << endl;
    c_end = clock();
    cout << "  : " << double(c_end - c_start) / CLOCKS_PER_SEC << endl;

    c_start = clock();
    cout << "������� ��������� ������: " << tree.Depth() << endl;
    c_end = clock();
    cout << "  : " << double(c_end - c_start) / CLOCKS_PER_SEC << endl;
    UniqueTree u_tree;
    for (size_t i = 0; i < n; i++)
    {
        u_tree.insert(rand() % 100);
    }

    u_tree.print();
    cout << endl;
    cout << "���������� ��������� ��������� ������: " << u_tree.Count() << endl;
#endif // HW_1

#ifdef DEEP_CHEK
    Tree tree = { 50, 25, 75, 16, 32, 64, 90, 28 };
    tree.print();
    cout << "������� ��������� ������: " << tree.Depth() << endl;
    
#endif // DEEP_CHEK

    //tree.balance();
    tree.print_tree(tree.getRoot(), 0);

    return 0;
}