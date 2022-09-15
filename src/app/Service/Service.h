#ifndef SERVICE_H
#define SERVICE_H

#include <string>
#include "View.h"
#include "LightState.h"


class Service
{
private:
    int lightState;
    View *view;


public:
    Service(View *viewer);
    ~Service();
    void updateState(std::string strState);

};

#endif