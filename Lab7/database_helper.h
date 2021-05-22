#ifndef LAB7__DATABASE_HELPER_H_
#define LAB7__DATABASE_HELPER_H_

#include <fstream>
#include <ios>
#include <vector>
#include <map>

class database_helper {
 private:
  std::ofstream _out;
  std::ifstream _in;
  std::string _file_name;
  std::vector<std::string> records;
  static const std::string ERROR_MSG;
  void db_in_open();
  void db_out_open(bool rewrite = false);
  void rewrite();
  void add_record_to_file(std::string record);
 public:
  database_helper(std::string file_name);
  ~database_helper();
  void add_record(std::string record);
  void erase_record(int id);
  std::vector<std::string> &get_vector_of_records();

};

#endif
