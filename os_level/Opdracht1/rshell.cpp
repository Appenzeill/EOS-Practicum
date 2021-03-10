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
  
  int write_new_file = syscall(SYS_write, create_new_file, c_file_text, file_text.length());
  close(create_new_file);
  close(write_new_file);
}

void list() {
    int pid = syscall(SYS_fork);                             
    const char* args[] = { "/bin/ls", "-l", "-a", NULL };                            
    if (pid == 0){
        syscall(SYS_execve, args[0], args, NULL);
    }
    else {
      cout << pid << syscall(SYS_wait4, pid, NULL, NULL) << endl;
    }
}       

void find() // ToDo: Implementeer volgens specificatie.
{
    string zoekwoord;
    int fd[2];
    
    cout << "Op welk woord wil je zoeken:";
    cin >> zoekwoord;
    syscall(SYS_pipe, &fd, NULL);
    int pid = syscall(SYS_fork);
    if (pid==0){
        int pid2 = syscall(SYS_fork);
        if (pid2==0){
            syscall(SYS_close, fd[0]);
            syscall(SYS_dup2, fd[1], 1);
            const char* args[] = { "/usr/bin/find", ".", NULL };
            int find = syscall(SYS_execve, args[0], args, NULL);
            
        } else{
            syscall(SYS_close, fd[1]);
            syscall(SYS_dup2, fd[0], 0);
            const char* args2[] = { "/bin/grep", zoekwoord.c_str(), NULL};
            syscall(SYS_execve, args2[0], args2, NULL);
            int exit = 0;
            cout << exit << "\n";    
            int exit_status = syscall(SYS_wait4, pid2, NULL);
            cout << "child died1," << exit << ", " << exit_status << "\n"; 
            }
        }
    else if (pid>0){
        int exit = 0;
        cout << exit << "\n";    
        int exit_status = syscall(SYS_wait4, pid, NULL);
        cout << "child died2," << exit << ", " << exit_status << " ," << pid << endl; 
        return;
    }
    else{
      cout << "fork_failed" << endl;
    }
}

void seek() { // ToDo: Implementeer volgens specificatie.
  cout << "ToDo: Implementeer hier seek()" << endl;
}

void src() {                                                // Voorbeeld: Gebruikt SYS_open en SYS_read om de source van de shell (shell.cc) te printen.
  int fd = syscall(SYS_open, "foo.txt", O_RDONLY, 0755);    // Gebruik de SYS_open call om een bestand te openen.
  char byte[1];                                             // 0755 zorgt dat het bestand de juiste rechten krijgt (leesbaar is).
  while(syscall(SYS_read, fd, byte, 1))                     // Blijf SYS_read herhalen tot het bestand geheel gelezen is,
    std::cout << byte;                                      // zet de gelezen byte in "byte" zodat deze geschreven kan worden.
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
  cout << "\033[2J\033[1;1H";
  while(true) {
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
