// Copyright 2021 SovesT

#ifndef INCLUDE_MAGIC_HPP_
#define INCLUDE_MAGIC_HPP_

#include <boost/filesystem.hpp>
#include <iostream>
#include <regex>
#include <string>
#include <vector>

using boost::filesystem::directory_entry;
using boost::filesystem::directory_iterator;
using boost::filesystem::exists;
using boost::filesystem::is_directory;
using boost::filesystem::is_regular_file;
using boost::filesystem::path;
using std::cout;
using std::endl;
using std::regex;
using std::regex_search;
using std::smatch;
using std::string;
using std::vector;

struct file {
  string broker;
  string account;
  string fullname;
};

struct account {
  string broker;
  string name;
  int count = 0;
  int date = 0;
};

file filter(const string& st);
void print(const vector<file>& list);
size_t exist(vector<account> acc, const file& f);
void magic(const vector<file>& list);
void magic_print(const vector<account>& acc);
void walker(const path&, vector<file>&);

#endif  // INCLUDE_MAGIC_HPP_
