#include <iostream>
#include <string>
#include <syscall.h>
#include <fcntl.h>
#include <unistd.h>
#include <fstream> 

using namespace std;

void new_file() { // ToDo: Implementeer volgens specificatie.
  std::cout << "ToDo: Implementeer hier new_file()" << std::endl;
}

void list() { // ToDo: Implementeer volgens specificatie.
  std::cout << "ToDo: Implementeer hier list()" << std::endl;
}

void find() {// ToDo: Implementeer volgens specificatie.
 std::cout << "ToDo: Implementeer hier find()" << std::endl;
}

void seek() { // ToDo: Implementeer volgens specificatie.
  std::cout << "ToDo: Implementeer hier seek()" << std::endl;
}

void src() { // Voorbeeld: Gebruikt SYS_open en SYS_read om de source van de shell (shell.cc) te printen.
  int fd = syscall(SYS_open, "rshell.cpp", O_RDONLY, 0755); // Gebruik de SYS_open call om een bestand te openen.
  char byte[1];                                          // 0755 zorgt dat het bestand de juiste rechten krijgt (leesbaar is).
  while(syscall(SYS_read, fd, byte, 1))                  // Blijf SYS_read herhalen tot het bestand geheel gelezen is,
    std::cout << byte;                                   // zet de gelezen byte in "byte" zodat deze geschreven kan worden.
}                                 

int main() {
  string input;
  string readprompt;
  string prompt;

  // een hiden file zoals de meeste configuratie files van shells.
  ifstream readPrompt(".rshell");

  while (getline (readPrompt, readprompt)) {
    prompt = readprompt;
  }
  readPrompt.close(); 
  
  while(true) {
    cout << prompt << " ";
    getline(std::cin, input);
    if (input == "exit") {
      return 0;
    } else if (input == "new_file") {
      new_file();
    } else if (input == "list") {
      list();
    } else if (input == "find") {
      find();
    } else if (input == "src") {
      src();
    } else if (input == "clear") {
      cout << "\033[2J\033[1;1H";
    } else {
      cout << "Programma niet gevonden." << "\n";
    }
  }
  cin >> input; 
  
  return 0;
}
