#include <iostream>
#include <cassert>
#include "applicant.h"
#include "employer.h"
#include "database_helper.h"

int main(){
  database_helper db("database.csv");
  applicant app1("Kozlov,Vadim,Aleksandrovich,2002,0,0,1,23321jneknf,3,1000");
  applicant app2("Kozlov", "Vadim", "Aleksandrovich", 2002, applicant::MALE, applicant::MARRIED, applicant::BSUIR, "23321jneknf", applicant::GOMEL, 1000);
  assert(app2.to_csv() == "Kozlov,Vadim,Aleksandrovich,2002,0,0,1,23321jneknf,3,1000");
  employer amp1(app1);
  employer amp2("Kozlov,Vadim,Aleksandrovich,2002,0,0,1,23321jneknf,3,1000");

  assert(app1.get_name() == "Kozlov Vadim Aleksandrovich");
  assert(app1.get_year_of_birth() == 2002);
  assert(app1.get_gender() == applicant::MALE);
  assert(app1.get_marital_status() == applicant::MARRIED);
  assert(app1.get_university() == applicant::BSUIR);
  assert(app1.get_mobile_phone() == "23321jneknf");
  assert(app1.get_city() == applicant::GOMEL);
  assert(app1.min_salary() == 1000);


  return 0;
}