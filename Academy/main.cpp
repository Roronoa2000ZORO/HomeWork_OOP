#include"academy.hpp"


int main() {
    setlocale(LC_ALL, "ru");

    Human* group[]
    {
        new Student("Ibragim", "Alikhanov", 23, "IT", "PV_211", 95, 99),
        new Teacher("Ishaq", "Aliev", 36, "IT", 12),
        new Graduate("Rauf", "Novikov", 27, "Cybersecurity", "CS_156", 97, 96, "Viruses"),
        new SeniorLecturer("Halid", "Validov", 46, "Cybersecurity", 20, "Scientist")
    };



    ofstream fout("group.txt");
    for (size_t i = 0; i < size(group); i++)
    {
        fout << typeid(*group[i]).name() << ":\t";
        fout << *group[i] << endl;
    }
    fout.close();

    for (int i = 0; i < sizeof(group) / sizeof(Human*); i++)
    {
        delete group[i];
    }



    
    int n = 0;
    Human** group1 = load("group.txt", n);
    cout << "\n-----------------------------------------\n";
    for (int i = 0; i < n; i++)
    {
        cout << *group1[i] << endl;
        cout << "\n-----------------------------------------\n";
    }
    for (int i = 0; i < n; i++)
    {
        delete group1[i];
    }
    delete[] group1;



    

    
    return 0;
}