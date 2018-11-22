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

#include <unistd.h>     // getdtablesize()
#include <sys/time.h>   // fd_set

#include "nsSysteme.h"
#include "CExc.h"

using namespace nsSysteme;
using namespace std;

void Derout (int numSig) {
	cout << "mon pid est : "  << getpid () << endl;
	cout << "le signal est : "  << strsignal (numSig) << endl;
	cout << "le num du signal est : " << numSig << endl;
}//Derout

int main(int argc, char * argv [])
{
  try {

	nsFctShell::DerouterSignaux (Derout);

	pid_t pidFils;
	pidFils = Fork ();
	/*
	if (pidFils > 0) {
		cout << "PAPA" <<endl;
		cout << "mon pid est : "  << getpid () << endl;
	}
	else {
		cout << "ENFANT" << endl;
		cout << "mon pid est : " << getpid () << endl;
		cout << "le pid de mon père est : " << getppid () << endl;
	}

	if (pidFils > 0) {
		Signal (SIGINT, SIG_DFL);
		while (true) {}
	}
	else {
		Signal (SIGTSTP, SIG_DFL);
		while (true) {};
	}
	*/

	

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

