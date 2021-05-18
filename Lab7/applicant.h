#ifndef LAB7__APPLICANT_H_
#define LAB7__APPLICANT_H_

#include <string>

class applicant {
 public:
  enum gender {
    MALE,
    FEMALE,
    TRANSGENDER,
    GENDER_NEUTRAL,
    NON_BINARY,
    AGENDER,
    PANGENDER,
    GENDERQUEER,
    TWO_SPIRIT,
    THIRD_GENDER,
    NONE
  };
  enum university {
    BSU,
    BSUIR,
    BSMU,
    GrSU
  };
  enum marital_status {
    MARRIED,
    SINGLE
  };
  enum city {
    BREST,
    VITEBSK,
    GRODNO,
    GOMEL,
    MINSK,
    MOGILEV
  };
 private:
//  int id;
  std::string _first_name, _second_name, _third_name;
  int _year_of_birth;

  gender _gender;
  marital_status _marital_status;
  std::string _mobile_phone;
  university _university;
  city _city;
  int _min_salary;
 public:
  applicant(
      std::string first_name,
      std::string second_name,
      std::string third_name,
      int year_of_birth,
      gender gend,
      marital_status status,
      university univ,
      std::string mobile_phone,
      city city_,
      int min_salary);

  applicant(std::string csv);

  ~applicant(){};

  std::string to_string(std::string divider = "\n");

  std::string to_csv();

  std::string get_name();
  int get_year_of_birth();
  gender get_gender();
  marital_status get_marital_status();
  university get_university();
  std::string get_mobile_phone();
  city get_city();
  int min_salary();

};

#endif
