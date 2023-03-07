#include"academy.hpp"


int main() {
    setlocale(LC_ALL, "ru");

    Human* group[]
    {
        new Student("Ibragim", "Alikhanov", 23, "IT", "PV_211", 95, 99),
        new Teacher("Ishaq", "Aliev", 36, "IT", 12),
        new Graduate("Rauf", "Novikov", 27, "Cybersecurity", "CS_156", 97, 96, "Viruses"),
        new Qualification("Halid", "Validov", 46, "Cybersecurity", 20, "Scientist")
    };

    for (size_t i = 0; i < size(group); i++)
    {
        group[i]->info();
        cout << "\n------------------------------------------------\n";
    }

    return 0;
}