#include "applicant.h"
applicant::applicant(std::string first_name,
                     std::string second_name,
                     std::string third_name,
                     int year_of_birth,
                     applicant::gender gend,
                     applicant::marital_status status,
                     applicant::university univ,
                     std::string mobile_phone,
                     applicant::city city_,
                     int min_salary) {
  _first_name = first_name;
  _second_name = second_name;
  _third_name = third_name;
  _year_of_birth = year_of_birth;
  _gender = gend;
  _marital_status = status;
  _university = univ;
  _mobile_phone = mobile_phone;
  _city = city_;
  _min_salary = min_salary;
}
applicant::applicant(std::string csv) {
  std::string strs[10];
  csv.push_back(',');
  int j = 0;
  for (int i = 0; i < 10; i++) {
    while (j < csv.size() && csv[j] != ',') {
      strs[i].push_back(csv[j]);
      j++;
    }
    j++;
  }

  _first_name = strs[0];
  _second_name = strs[1];
  _third_name = strs[2];
  _year_of_birth = atoi(strs[3].c_str());
  _gender = static_cast<gender>(atoi(strs[4].c_str()));
  _marital_status = static_cast<marital_status>(atoi(strs[5].c_str()));
  _university = static_cast<university>(atoi(strs[6].c_str()));
  _mobile_phone = strs[7];
  _city = static_cast<city>(atoi(strs[8].c_str()));
  _min_salary = atoi(strs[9].c_str());
}
std::string applicant::to_string(std::string divider) {
  return
      _first_name + divider +
          _second_name + divider +
          _third_name + divider +
          std::to_string(_year_of_birth) + divider +
          std::to_string(_gender) + divider +
          std::to_string(_marital_status) + divider +
          std::to_string(_university) + divider +
          _mobile_phone + divider +
          std::to_string(_city) + divider +
          std::to_string(_min_salary);
}
std::string applicant::to_csv() {
  return to_string(",");
}
std::string applicant::get_name() {
  return _first_name + " " + _second_name + " " + _third_name;
}
int applicant::get_year_of_birth() {
  return _year_of_birth;
}
applicant::gender applicant::get_gender() {
  return _gender;
}
applicant::marital_status applicant::get_marital_status() {
  return _marital_status;
}
applicant::university applicant::get_university() {
  return _university;
}
std::string applicant::get_mobile_phone() {
  return _mobile_phone;
}
applicant::city applicant::get_city() {
  return _city;
}
int applicant::min_salary() {
  return _min_salary;
}
