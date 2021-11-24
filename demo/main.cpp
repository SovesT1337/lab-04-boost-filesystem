#include <magic.hpp>

int main() {
  // int main(int argc, char* argv[]) {
  path p = "/home/sovest/CLionProjects/lab-04-boost-filesystem/misc";
  // if (argc >= 2)
  //   p = argv[1];
  // else
  //   p = boost::filesystem::current_path();
  vector<file> list;
  walker(p, list);
  print(list);
  magic(list);
}