#include <iostream>
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
  assert(amp1.suits(app2) == true);

  return 0;
}