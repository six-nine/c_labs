#include <iostream>

#include "applicant.h"
#include "employer.h"
#include "database_helper.h"

using namespace std;

int main() {
  bool end = false;
  database_helper employers_db("employers.csv");
  database_helper applicants_db("applicants.csv");

  vector<string> &db1 = applicants_db.get_vector_of_records();
  vector<string> &db2 = employers_db.get_vector_of_records();
  vector<employer> employers;
  vector<applicant> applicants;

  for (auto i: db1){
    applicants.push_back(applicant(i));
  }

  for (auto i: db2){
    employers.push_back(employer(i));
  }

  while (!end){
    cout << "MENU" << endl
         << "1 Add applicant\n"
         << "2 Add employer\n"
         << "3 Select vacancies for applicant\n"
         << "4 Select candidates for employer\n"
         << "5 Show list of vacancies\n"
         << "6 Show list of applicants\n"
         << "7 Quit\n";
    int command;
    cin >> command;
    if (command == 1) {
      string first_name, second_name, third_name;
      int birth_year;
      int gender;
      int status;
      int university;
      int city;
      int min_salary;
      string mobile_phone;
      cout << "Enter full name: ";
      cin >> first_name >> second_name >> third_name;
      cout << "Birth year: ";
      cin >> birth_year;
      cout << "Gender? 0 - male, 1 - female, 2-8 - random";
      int g = -1;
      while (g < 0 || g > 8){
        cin >> g;
      }
      gender = g;
      cout << "Marital status? 0 - married, 1 - single";
      g = -1;
      while (g < 0 || g > 1){
        cin >> g;
      }
      status = g;
      cout << "Education? 0 - BSU, 1 - BSUIR";
      g = -1;
      while (g < 0 || g > 1){
        cin >> g;
      }
      university = g;
      cout << "City?\n"
              "0 BREST,\n"
              "1 VITEBSK,\n"
              "2 GRODNO,\n"
              "3 GOMEL,\n"
              "4 MINSK,\n"
              "5 MOGILEV";
      g = -1;
      while (g < 0 || g > 5){
        cin >> g;
      }
      city = g;
      cout << "Minimal salary? ($) :";
      cin >> min_salary;
      cout << "And leave mobile phone, please: ";
      cin >> mobile_phone;
      applicant new_applicant(first_name, second_name, third_name, birth_year, gender, status, university, mobile_phone, city, min_salary);
      applicants.push_back(new_applicant);
      applicants_db.add_record(new_applicant.to_csv());
    } else if (command == 2){
      int city;
      int min_salary;
      int max_birth_year;
      cout << "Where is vacation located?\n"
              "0 BREST,\n"
              "1 VITEBSK,\n"
              "2 GRODNO,\n"
              "3 GOMEL,\n"
              "4 MINSK,\n"
              "5 MOGILEV";
      int g = -1;
      while (g < 0 || g > 5){
        cin >> g;
      }
      city = g;
      cout << "Salary?\n";
      cin >> min_salary;
      cout << "Max birth year?\n";
      cin >> max_birth_year;
      employer new_employer(city, min_salary, max_birth_year);
      employers.push_back(new_employer);
      employers_db.add_record(new_employer.to_csv());
    } else if (command == 3){
      int id = -1;
      cout << "Enter number of applicant: ";
      while (id < 0 || id >= applicants.size()){
        cin >> id;
      }
      for (int i = 0; i < employers.size(); i++){
        if (employers[i].suits(applicants[id])){
          cout << employers[i].to_string();
          cout << endl;
        }
      }
    } else if (command == 4){
      int id = -1;
      cout << "Enter number of employer: ";
      while (id < 0 || id >= employers.size()){
        cin >> id;
      }
      for (int i = 0; i < applicants.size(); i++){
        if (employers[id].suits(applicants[i])){
          cout << applicants[i].to_string();
          cout << endl;
        }
      }
    } else if (command == 5){
      for (int i = 0; i < employers.size(); i++){
        cout << "---" << i << "---" << endl;
        cout << employers[i].to_string();
        cout << endl;
      }
    } else if (command == 6){
      for (int i = 0; i < applicants.size(); i++){
        cout << "---" << i << "---" << endl;
        cout << applicants[i].to_string();
        cout << endl;
      }
    } else if (command == 7){
      end = true;
    }
  }

  return 0;
}
