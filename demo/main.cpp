#include <magic.hpp>

int main(int argc, char* argv[]) {
  path p;
  if (argc >= 2) p = argv[1];
  else p = boost::filesystem::current_path();
  vector<file> list{walker(p)};
  print(list);
  magic(list);
}