#include <EEPROM.h>
#include "data.h"

Data::Data()
{
    unsigned int addr = 0;

    EEPROM.begin(512);
    EEPROM.get(addr, Data::data);
}

void Data::moduleLoop()
{
    
}
