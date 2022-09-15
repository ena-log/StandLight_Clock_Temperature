#include <iostream>
#include <wiringPi.h>
#include "Button.h"
#include "Led.h"
#include "Listener.h"
#include "Controller.h"
#include "View.h"
#include "Service.h"
#include "LCD.h"
#include "ClockView.h"
#include "ClockService.h"
#include "ClockCheck.h"
#include "I2C.h"

// #include <time.h>


// func. main
// 1. 프로그램의 시작점을 알려줌
// 2. 초기화 및 로딩

int main()
{
    std::cout << "Hello World!" << std::endl;
    //<time test>
    // time_t timeSec;
    // struct tm *timeData;
    
    Button modeButton(27);
    Button powerButton(28);  
    ClockCheck clockCheck;
    Led led1(21);
    Led led2(22);
    Led led3(23);
    Led led4(24);
    Led led5(25);
    LCD lcd(new I2C("/dev/i2c-1", 0x27));
    View view(&led1, &led2, &led3, &led4, &led5, &lcd);
    ClockView clockView(&lcd);
    Service service(&view);
    ClockService clockService(&clockView);
    Controller control(&service, &clockService);
    Listener listener(&modeButton, &powerButton, &control, &clockCheck);
    
    while (1)
    {
        listener.checkEvent();
        view.lightView();

        //<time test>
        // timeSec = time(NULL);
        // timeData = localtime(&timeSec);

        // std::cout << "timeSec : " << timeSec << std::endl;
        // std::cout << timeData->tm_hour << ":" 
        //            << timeData->tm_min << ":"
        //            << timeData->tm_sec << std::endl;
        delay(50);
    }

    return 0;
}