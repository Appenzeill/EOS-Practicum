#include <iostream>
#include <string>

using namespace std;

string gnuifier(string argument) {
  return "GNU/" + argument;
}

int main( int argc, char *argv[] ) {
   if ( argc != 2 ) {
     cerr << "Maar 1 argument nodig" << endl;
   } else {
     cout << gnuifier(argv[1]) << endl;
   }
   return 0;
}
