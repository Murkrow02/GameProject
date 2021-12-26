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
    const string savefile_name = "save.json"; 
    ifstream input_file;

    //Deserialize disk-saved file and save it in memory
    void reload_json();

public:
    json savefile;

    savedata();

    //Update disk-saved file with memory-saved one
    void save_changes();

};


#endif

