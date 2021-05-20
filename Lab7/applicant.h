#ifndef LAB7__APPLICANT_H_
#define LAB7__APPLICANT_H_

#include <string>
#include <vector>

class applicant {
 public:
  std::vector<std::string> gender = {
      "MALE",
      "FEMALE",
      "TRANSGENDER",
      "GENDER_NEUTRAL",
      "NON_BINARY",
      "AGENDER",
      "PANGENDER",
      "GENDERQUEER",
      "TWO_SPIRIT",
      "THIRD_GENDER",
      "NONE"
  };
  std::vector<std::string> university = {
      "BSU",
      "BSUIR",
      "BSMU",
      "GrSU"
  };
  std::vector<std::string> marital_status = {
      "MARRIED",
      "SINGLE"
  };
  std::vector<std::string> city = {
      "BREST",
      "VITEBSK",
      "GRODNO",
      "GOMEL",
      "MINSK",
      "MOGILEV"
  };

 private:
//  int id;
  std::string _first_name, _second_name, _third_name;
  int _year_of_birth;

  int _gender;
  int _marital_status;
  int _university;
  int _city;
  std::string _mobile_phone;
  int _min_salary;
 public:
  applicant(
      std::string first_name,
      std::string second_name,
      std::string third_name,
      int year_of_birth,
      int gend,
      int status,
      int univ,
      std::string mobile_phone,
      int city_,
      int min_salary);

  applicant(std::string csv);

  ~applicant() {};

  std::string to_string(std::string divider = "\n", bool save_id = false, bool include_description = true);

  std::string to_csv();

  std::string get_name();
  int get_year_of_birth();
  std::string get_gender();
  std::string get_marital_status();
  std::string get_university();
  std::string get_mobile_phone();
  std::string get_city();
  int min_salary();

};

#endif
