// Copyright 2021 SovesT

#include <magic.hpp>

file filter(string st) {
  file temp;
  string st1 = st, st2;
  while (st1.find('/') != string::npos) {
    st2 = st1.substr(0, st1.find('/'));
    st1.erase(0, st1.find('/') + 1);
  }
  temp.fullname = st1;
  temp.account = st1.substr(8, 8);
  temp.broker = st2;
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

vector<file> walker(path p){
  vector<file> list;
  if (exists(p)) {
    for (directory_entry& x : directory_iterator(p)) {
      if (is_directory(x)) {
        for (directory_entry& z : directory_iterator(x)) {
          if (is_regular_file(z)) {
            file temp = filter(z.path().string());
            if (temp.fullname.size() == 29) {
              list.push_back(temp);
            }
          }
        }
      }
      if (is_regular_file(x)) {
        file temp = filter(x.path().string());
        if (temp.fullname.size() == 29) {
          list.push_back(temp);
        }
      }
    }
  }
  return list;
}
