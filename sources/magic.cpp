// Copyright 2021 SovesT

#include <magic.hpp>

file filter(string st) {
  file temp;

  std::smatch parts;
  std::regex re(R"(/(\w+)/(balance_(\d){8}_(\d){8}\.txt))");
  if (std::regex_search(st, parts, re)) {
    temp.fullname = parts[2];
    temp.account = temp.fullname.substr(8, 8);
    temp.broker = parts[1];
  }
  return temp;
}

void print(const vector<file>& list) {
  for (const file& i : list) {
    cout << i.broker << ' ' << i.fullname << endl;
  }
}

size_t exist(vector<account> acc, file f) {
  for (size_t i = 0; i < acc.size(); ++i) {
    if (f.account == acc[i].name) return i;
  }
  return acc.size();
}

void magic_print(vector<account> acc) {
  for (account i : acc) {
    cout << "broker: " << i.broker << " account: " << i.name
         << " files: " << i.count << " lastdate: " << i.date << endl;
  }
}

void magic(const vector<file>& list) {
  vector<account> acc;
  for (const file& i : list) {
    if (exist(acc, i) == acc.size()) {
      account temp;
      temp.name = i.account;
      temp.broker = i.broker;
      temp.date = stoi(i.fullname.substr(i.fullname.size() - 12, 8));
      temp.count++;
      acc.push_back(temp);
    } else {
      acc[exist(acc, i)].count++;
      if (acc[exist(acc, i)].date <
          stoi(i.fullname.substr(i.fullname.size() - 12, 8)))
        acc[exist(acc, i)].date =
            stoi(i.fullname.substr(i.fullname.size() - 12, 8));
    }
  }
  magic_print(acc);
}

void walker(const path& p, vector<file>& list) {
  if (exists(p)) {
    for (directory_entry& x : directory_iterator(p)) {
      if (is_directory(x)) {
        walker(x.path(), list);
      }
      if (is_regular_file(x)) {
        file temp = filter(x.path().string());
        if (temp.fullname != "") {
          list.push_back(temp);
        }
      }
    }
  }
}
