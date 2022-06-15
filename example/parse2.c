#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include "iniparser.h"

int main(int argc, char * argv[])
{
    // create variables for ini
    dictionary * ini ;
    char       * ini_name ;

    if (argc<2) {
        // default ini
        ini_name = "example2.ini";
    } else {
        ini_name = argv[1] ;
    }

    // load ini file
    ini = iniparser_load(ini_name);
    /*
    print all to console using provided function
    iniparser_dump(ini, stdout);
    */

    // get count of sectors
    int nsec = iniparser_getnsec(ini);

    // go through each sector
    for (int i = 0; i < nsec; ++i) {
        // get name of sector and print
        const char *sector = iniparser_getsecname(ini,i);
        printf("%s\n",sector);

        // get number of keys
        int nkeys = iniparser_getsecnkeys(ini,sector);
        // create array of keys using length from provided function
        const char* keys[nkeys];
        // get keys using provided function
        iniparser_getseckeys(ini,sector,keys);

        // go through each key
        for (int i = 0; i < nkeys; ++i) {
            // print key and value
            printf("%s=%s\n", keys[i],iniparser_getstring(ini,keys[i],""));
        }
        printf("--------------------\n");
    }

    
    iniparser_freedict(ini);

    return 0 ;
}
