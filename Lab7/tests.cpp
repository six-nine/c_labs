#include <iostream>
#include <cassert>
#include "applicant.h"
#include "employer.h"
#include "database_helper.h"

int main(){
  applicant app1("Ivanov", "Ivan", "Ivanovich", 2010, 1, 0, 0, "73673682361742687", 3, 1600);
  applicant app_from_csv("Ivanov,Ivan,Ivanovich,2010,1,0,0,73673682361742687,3,1600");
  assert(app1.get_name() == app_from_csv.get_name());
  assert(app1.get_city() == app_from_csv.get_city());
  assert(app1.get_mobile_phone() == app_from_csv.get_mobile_phone());
  assert(app1.get_university() == app_from_csv.get_university());
  assert(app1.get_marital_status() == app_from_csv.get_marital_status());
  assert(app1.get_gender() == app_from_csv.get_gender());
  assert(app1.get_year_of_birth() == app_from_csv.get_year_of_birth());
  assert(app1.min_salary() == app_from_csv.min_salary());
  assert(app1.to_string() == app_from_csv.to_string());
  assert(app1.to_csv() == "Ivanov,Ivan,Ivanovich,2010,1,0,0,73673682361742687,3,1600");
  return 0;
}