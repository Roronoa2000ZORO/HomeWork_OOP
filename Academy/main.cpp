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
       
        fout << *group[i] << endl;
    }
    fout.close();





    ifstream fin("group.txt");
    if (!fin.is_open())
    {
        cerr << "Error: file not found" << endl;
        return 0;
    }
    
    for (size_t i = 0; i < size(group); i++)
    {
        fin >> *group[i];
        cout << *group[i] << endl;
    }
    fin.close();



    for (int i = 0; i < sizeof(group) / sizeof(Human*); i++)
    {
        delete group[i];
    }

    return 0;
}