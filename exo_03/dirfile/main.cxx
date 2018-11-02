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
using namespace nsFctShell;
using namespace std;

size_t donneTailleEnOctets(const string &comment, const string &nomFichier) {
	struct stat S;
	Stat (nomFichier.c_str(), &S);
	if ("char" == comment) {
		return 1;
	}
	else if ("all" == comment) {
		return S.st_size;
	}
	else if ("blok" == comment) {
		return S.st_blksize;
	}
}

int main(int argc, char * argv [])
{

if (4 != argc) {
	cerr << "pas assez d'arguments" << endl;
	return -1;
}
else {
	try {
		size_t tailleTampon = ::donneTailleEnOctets (argv[1], argv[2]);
		FileCopy (argv[2], argv[3], tailleTampon);

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

}
}  //  main()

