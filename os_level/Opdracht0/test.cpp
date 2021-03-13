#include <iostream>
#include <string>
#include <stdio.h>
using namespace std;

string translate(string line, string argument)
{     string result = ""; // implementeer dit
    cout << line << "\n";
    cout << argument << "\n\n";
      return result; }

int main(int argc, char *argv[])
{ string line;

  if(argc != 2)
  { cerr << "Deze functie heeft exact 1 argument nodig" << endl;
    return -1; }

  while(getline(cin, line))
  { cout << translate(line, argv[1]) << endl; } 

  return 0; }
