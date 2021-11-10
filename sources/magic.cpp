// Copyright 2021 SovesT

#include <magic.hpp>

file filter(const string& st) {
  file temp;
  smatch parts;
  regex re(R"(/(\w+)/(balance_(\d){8}_(\d){8}\.txt))");
  if (regex_search(st, parts, re)) {
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

size_t exist(vector<account> acc, const file& f) {
  for (size_t i = 0; i < acc.size(); ++i) {
    if (f.account == acc[i].name) return i;
  }
  return acc.size();
}

void magic_print(const vector<account>& acc) {
  for (const account& i : acc) {
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
        if (!temp.fullname.empty()) {
          list.push_back(temp);
        }
      }
    }
  }
}
