#include "Listener.h"

Listener::Listener(Button *modeButton, Button *powerButton, Controller *control, ClockCheck *clock)
{
    this->modeButton = modeButton;
    this->powerButton = powerButton;
    controller = control;
    clockcheck = clock;
}

Listener::~Listener()
{
}

void Listener::checkEvent()
{
    if (modeButton->getState() == RELEASE_ACTIVE)
    {
        controller->updateEvent("modeButton");
    }

    if (powerButton->getState() == RELEASE_ACTIVE)
    {
        controller->updateEvent("powerButton");
    }

    //시간 감시
    if (clockcheck->isUpdate())
    {
        controller->updateEvent("clockUpdate");
    }
}