#include "employer.h"
employer::employer(int city_id, int min_salary, int max_year_of_birth)
    : ideal_candidate(
    "",
    "",
    "",
    max_year_of_birth,
    0,
    0,
    0,
    "88005553535",
    city_id,
    min_salary
){}
bool employer::suits(applicant appl) {
  return
      appl.get_city() == ideal_candidate.get_city() &&
          appl.min_salary() <= ideal_candidate.min_salary() &&
          appl.get_year_of_birth() <= ideal_candidate.get_year_of_birth();
}
std::string employer::to_csv() {
  return ideal_candidate.to_csv();
}
std::string employer::to_string() {
  return ideal_candidate.get_city() + "\n" + std::to_string(ideal_candidate.get_year_of_birth()) + "\n" + std::to_string(ideal_candidate.min_salary());
}
