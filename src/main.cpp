#include <iostream>
#include <sstream>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>

using namespace std;

int main() {
  string input;
  cout << "$ ";
  while (getline(cin, input)) {
    istringstream sin(input);
    sin >> input;

    if (input == "exit") { exit(0); }

    char** argv = new char*[2];
    argv[1] = 0;

    argv[0] = new char[input.size() + 1];
    strcpy(argv[0], input.c_str());

    if (fork() == 0) {
      execvp(argv[0], argv);
      perror(argv[0]);
      exit(1);
    } else {
      int ret;
      wait(&ret);
    }
    cout << "$ ";
  }

  cout << endl;

  return 0;
}



