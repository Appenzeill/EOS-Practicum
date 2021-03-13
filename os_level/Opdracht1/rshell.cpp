#include <iostream>
#include <string>
#include <fstream> 

#include <sys/syscall.h>
#include <syscall.h>
#include <fcntl.h>
#include <unistd.h>

using namespace std;

void new_file() { // ToDo: Implementeer volgens specificatie.
  string file_name, file_text;
 
  cout << "File naam: ";
  cin >> file_name;
  cout << "Inhoud: ";
  cin.ignore();
  getline (cin,file_text);

  const char *c_file_name = file_name.c_str();
  const char *c_file_text = file_text.c_str();

  int create_new_file = syscall(SYS_open, c_file_name, O_CREAT | O_RDWR | O_TRUNC, 0666);
  
  if (syscall(SYS_creat) == 0) {
     cout << "error" << endl;
  }
  
  int write_to_new_file = syscall(SYS_write, create_new_file, c_file_text, file_text.length());
  close(create_new_file);
  close(write_to_new_file);
}

void list() {
  int fork = syscall(SYS_fork);
  const string location = "/bin/ls";
  const char *arguments[] = {location.c_str(), "-la", NULL};
  
  if (fork == 0) {
    syscall(SYS_execve,location.c_str(), arguments, NULL);
  } else {
    cout << syscall(SYS_wait4, fork, NULL, NULL) << endl;
  }
}


void find() {
  string woord;
  int pipe_A[2];
  
  cout << "Woord: ";
  cin >> woord;
 
  syscall(SYS_pipe,pipe_A);
  
  pid_t pid_A, pid_B;
  
  if( !(pid_A = fork()) ) {
    const string find_location = "/bin/find";
    const char *find_arguments[] = {find_location.c_str(), ".", NULL};

    syscall(SYS_dup2,pipe_A[1], 1); /* redirect standard output to pipe_A write end */
    syscall(SYS_execve, find_location.c_str(), find_arguments, NULL);
  }
  
  if( !(pid_B = fork()) ) {
    const string grep_location = "/bin/grep";
    const char *grep_arguments[] = {grep_location.c_str(), woord.c_str(), NULL};

    syscall(SYS_dup2,pipe_A[0], 0); /* redirect standard input to pipe_A read end */
    syscall(SYS_execve, grep_location.c_str(), grep_arguments, NULL);
    syscall(SYS_close,pid_A);
    syscall(SYS_close,pid_B);
  }
}

void seek() { // ToDo: Implementeer volgens specificatie.
  cout << "ToDo: Implementeer hier seek()" << endl;
}

void src() {                                                // Voorbeeld: Gebruikt SYS_open en SYS_read om de source van de shell (shell.cc) te printen.
  int fd = syscall(SYS_open, "rshell.cpp", O_RDONLY, 0755); // Gebruik de SYS_open call om een bestand te openen.
  char byte[1];                                             // 0755 zorgt dat het bestand de juiste rechten krijgt (leesbaar is).
  while(syscall(SYS_read, fd, byte, 1))                     // Blijf SYS_read herhalen tot het bestand geheel gelezen is,
    std::cout << byte;                                      // zet de gelezen byte in "byte" zodat deze geschreven kan worden.
}                                 

int main() {
  string input, readprompt, prompt;

  // een hiden file zoals de meeste configuratie files van shells.
  ifstream readPrompt(".rshell");

  // lees het bestand uit.
  while (getline (readPrompt, readprompt)) {
    prompt = readprompt;
  }
  readPrompt.close();
  
  // Lege commandline 
  cout << "\033[2J\033[1;1H";
  
  while(true) {
    // begin van prompt komt uit config file .rshell.
    cout << prompt << " ";
    getline(std::cin, input);
    if (input == "exit") {
      return 0;
    } else if (input == "new_file") {
      new_file();
    } else if (input == "list" || input == "ls") {
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
