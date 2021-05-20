#ifndef LAB7__EMPLOYER_H_
#define LAB7__EMPLOYER_H_

#include <string>
#include "applicant.h"

class employer {
  applicant ideal_candidate;
 public:
  employer(int city_id, int min_salary, int max_year_of_birth);;

  employer(applicant applicant) : ideal_candidate(applicant){}

  employer(std::string csv) : ideal_candidate(csv){}

  bool suits(applicant appl);
  std::string to_csv();
  std::string to_string();
};

#endif
