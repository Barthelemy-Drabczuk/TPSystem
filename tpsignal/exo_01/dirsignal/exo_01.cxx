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

	/*
	cout << argv [1][0] << endl;
	system ("sleep 10");
	*/
	if (2 != argc) {
		cerr << "Ne rentrer qu'un seul parametre !" << endl;
	}
	if (!isalpha (argv [1][0])) {
		cerr << "Ne rentrer qu'un caractere !" << endl;
	}
	if (argv [1][0] != 'P' && argv [1][0] != 'I' && argv [1][0] != 'D') {
		cerr << "Le caractere ne peut être que P, I ou D !" << endl;
	}

	for (unsigned numSig = 1; numSig != 31; ++numSig){
		if (numSig != SIGKILL && numSig != SIGSTOP && numSig != SIGCONT) {
			switch (argv [1][0]) {
				case 'P':
					Signal (numSig, Derout);
					break;
				case 'I':
					Signal (numSig, SIG_IGN);
					break;
				case 'D':
					Signal (numSig, SIG_DFL);
					break;
				default:
					cerr << "wlh c'est chaud" << endl;
			}
		}
	}

	while (true) {}

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

