// Copyright 2021 SovesT

#ifndef INCLUDE_EXAMPLE_HPP_
#define INCLUDE_EXAMPLE_HPP_
//
//#define BOOST_NO_CXX11_SCOPED_ENUMS
#include <boost/filesystem.hpp>
//#undef BOOST_NO_CXX11_SCOPED_ENUMS
#include <iostream>
#include <string>
#include <vector>

//using namespace boost::filesystem;
using boost::filesystem::directory_entry;
using boost::filesystem::directory_iterator;
using boost::filesystem::exists;
using boost::filesystem::is_directory;
using boost::filesystem::is_regular_file;
using boost::filesystem::path;
using std::cout;
using std::endl;
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

file filter(string st);
void print(const vector<file>& list);
size_t exist(vector<account> acc, file f);
void magic(const vector<file>& list);
void magic_print(vector<account> acc);
vector<file> walker(const path& p);

#endif  // INCLUDE_EXAMPLE_HPP_
