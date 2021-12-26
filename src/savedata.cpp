#include "libraries/json.hpp"
#include <stdio.h>
#include <string>
#include <fstream>
#include "headers/utils.h"

using namespace std;
using json = nlohmann::json;

class savedata
{
private:
    const string savefile_name = "save.json"; 
    ifstream input_file;
    json savefile;

public:

    savedata(){
        
        //Open savefile
        input_file.open(savefile_name);

        //Check if savefile is valid
        if(input_file.fail()){

            //Create new savefile
            ofstream new_savefile;
            new_savefile.open(savefile_name);
            new_savefile << "";
            new_savefile.close();

            //Open new savefile
            input_file.open(savefile_name);

            //Check if new file is valid
            if(input_file.fail())
            {
                //Cannot create file, report error to user
                fatal_error("Non è stato possibile creare il file di salvataggio, controlla che il gioco abbia i permessi necessari per scrivere nella directory corrente");
            }
        }
    }
   
};

