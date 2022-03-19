#include "savedata.hpp";


savedata::savedata(){
    reload_json();
}

void savedata::reload_json(){

    //Open savefile
    input_file.open(savefile_name);

    //Check if not found
    if(input_file.fail()){ 

        //Create new savefile
        ofstream new_savefile;
        new_savefile.open(savefile_name);
        new_savefile << "{}";
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

    //Convert text file to json file
    input_file >> savefile;
    input_file.close();
}

void savedata::save_changes(){

    //Create new file stream
    ofstream output;
    output.open(savefile_name, ofstream::trunc); //Replace original content

    //Serialize json to string
    string serialized = savefile.dump();
    output << serialized;

    output.close();

    //Update current file with disk-one
    reload_json();
}