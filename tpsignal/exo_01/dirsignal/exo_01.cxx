/**
 *
 * @File : 
 *
 * @Author : A. B. Dragut
 *
 * @Synopsis : modelmain
 **/

#include <string>
#include <exception>
#include <iostream>
#include "string.h"

#include <unistd.h>     // getdtablesize()
#include <sys/time.h>   // fd_set

#include "nsSysteme.h"
#include "CExc.h"

using namespace nsSysteme;
using namespace std;

void Derout (int sig){
	cout << "le nom du signal est : " << strsignal (sig) << endl 
	     << "et son numéro est : " << sig << endl;
}

int main(int argc, char * argv [])
{
  try {

	if (1 != argc) {
		cerr << "Ne rentrer qu'un seul parametre !" << endl;
	}
	if (!argv [1].isChar ()) {
		cerr << "Ne rentrer qu'un caractere !" << endl;
	}
	if (argv [1] != 'P' || avrg [1] != 'I' || argv [1] != 'D') {
		cerr << "Le caractere ne peut être que P, I ou D !" << endl;
	}

	for (unsigned i = 1; i != 31; ++i){
		switch (argv [1]) {

		}
	}

///code
    return 0;
  }
  catch (const CExc & Exc) {
        cerr <<Exc<< endl;
        return errno;
  }
  catch (const exception & Exc) {
        cerr << "Exception : " << Exc.what () << endl;
        return 1;
  }
  catch (...) {
        cerr << "Exception inconnue recue dans la fonction main()" 
             << endl;
        return 1;
  }


}  //  main()

