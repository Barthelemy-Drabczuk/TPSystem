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

int main(int argc, char * argv [])
{
  try {

	int pipeFd [2];
	Pipe (pipeFd);
	//dans le pere
	if (Fork () > 0) {
		Close (pipeFd [0]);
		for (unsigned i (0); i < 2; ++i)
			Write (pipeFd [1], "les messages", strlen ("les messages"));
		//determination de la taille de pipeFd [1]
		struct stat buf;
		fstat (pipeFd [1], &buf);
		size_t size = buf.st_size;
		//ecriture de la taille de pipeFd [1]
		Write (pipeFd [1], "#" + st_size);
	}
	//dans le fils
	else {
		Close (pipeFd [1]);
		char buff [10];
		while (Read (pipeFd [0], &buff, 10))
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

