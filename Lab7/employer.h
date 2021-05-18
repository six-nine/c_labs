#ifndef LAB7__EMPLOYER_H_
#define LAB7__EMPLOYER_H_

#include <string>
#include "applicant.h"

class employer {
  applicant ideal_candidate;
 public:
  employer(applicant::city city_, int min_salary, int max_year_of_birth)
    : ideal_candidate(
        "",
        "",
        "",
        max_year_of_birth,
        applicant::NONE,
        applicant::SINGLE,
        applicant::BSUIR,
        "88005553535",
        city_,
        min_salary
        ){};

  employer(applicant applicant) : ideal_candidate(applicant){}

  employer(std::string csv) : ideal_candidate(csv){}

  bool suits(applicant appl){
    return
      appl.get_city() == ideal_candidate.get_city() &&
      appl.min_salary() <= ideal_candidate.min_salary() &&
      appl.get_year_of_birth() <= ideal_candidate.get_year_of_birth();
  }

  std::string to_csv(){
    return ideal_candidate.to_csv();
  }

  std::string to_string(){
    return std::to_string(ideal_candidate.get_city()) + "\n" + std::to_string(ideal_candidate.get_year_of_birth()) + "\n" + std::to_string(ideal_candidate.min_salary());
  }

};

#endif
