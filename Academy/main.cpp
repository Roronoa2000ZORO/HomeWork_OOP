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


    ofstream fout;
    fout.open("group.txt");
    for (size_t i = 0; i < size(group); i++)
    {
        fout << typeid(*group[i]).name() << endl;
        fout << *group[i] << endl << endl;
    }
    
    for (int i = 0; i < sizeof(group) / sizeof(Human*); i++)
    {
        delete group[i];
    }
    fout.close();

    ifstream fin("group.txt");
    if (!fin.is_open())
    {
        cerr << "Error: file not found" << endl;
        return 0;
    }
    //Осталось реализовать загрузку группы из файла
   

    fin.close();

    return 0;
}