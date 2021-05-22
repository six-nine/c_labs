#include "database_helper.h"
void database_helper::db_in_open() {
  _in.open(_file_name);
  if (!_in.is_open()) {
    throw std::runtime_error("Error opening database.");
  }
}
void database_helper::db_out_open(bool rewrite) {
  _out.open(_file_name, rewrite ? std::ios_base::out : std::ios_base::app);
  if (!_out.is_open()) {
    throw std::runtime_error("Error opening database.");
  }
}
void database_helper::rewrite() {
  db_out_open(true);
  for (const auto& i: records) { _out << i << std::endl; }
  _out.close();
}
void database_helper::add_record_to_file(std::string record) {
  db_out_open();
  _out << record << std::endl;
  _out.close();
}
database_helper::database_helper(std::string file_name) {
  _file_name = file_name;
  db_out_open();
  _out.close();
  db_in_open();
  while (!_in.eof()){
    std::string str;
    getline(_in, str);
    if (!str.empty()) records.push_back(str);
  }
  _in.close();
}
database_helper::~database_helper() {
  db_out_open();
  rewrite();
  _out.close();
}
void database_helper::add_record(std::string record) {
  records.push_back(record);
  add_record_to_file(record);
}
void database_helper::erase_record(int id) {
  records.erase(records.begin() + id);
  rewrite();
}
std::vector<std::string> &database_helper::get_vector_of_records() { return records; }
