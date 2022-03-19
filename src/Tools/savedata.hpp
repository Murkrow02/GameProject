#ifndef SAVEDATA_H
#define SAVEDATA_H

#include "../libraries/json.hpp"
#include <stdio.h>
#include <string>
#include <fstream>
#include "utils.hpp"

using namespace std;
using json = nlohmann::json;

class savedata
{

private:

    //Disk-saved file name
    const string savefile_name = "save.json"; 

    //Serialized save file
    ifstream input_file;

    //Deserialize disk-saved file and save it in memory
    void reload_json();

public:

    //Deserialized save file
    json savefile;

    //Constructor
    savedata();

    //Update disk-saved file with memory-saved one
    void save_changes();

};


#endif

