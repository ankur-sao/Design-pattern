//
//  main.cpp
//  Command
//
//  Created by ansao on 1/15/20.
//  Copyright © 2020 ansao. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;


class command
{
public:
    virtual void execute() =0;
};

class fan
{
public:
    fan(){cout<<"fan ";}
    void off(){
        cout<< "off \n";
    }
    
    void on(){
        cout<<"on \n";
    }
    
};

class fanOn : public command
{
    fan *lFan;
public:
    fanOn(fan *aInFan)
    {
        lFan = aInFan;
    }
    void execute()
    {
        lFan->on();
    }
};

class fanOff:public command
{
    fan* lFan;
public:
    fanOff(fan *aInFan)
    {
        lFan = aInFan;
    }
    void execute()
    {
        lFan->off();
    }
};


class Remote
{
    command *slot;
public:
    void setCommand(command *aInCommand)
    {
        slot = aInCommand;
    }
    void buttonWasPressed()
    {
        slot->execute();
    }
};

int main(int argc, const char * argv[])
{
    Remote *lRemote = new Remote;
    fan *lFan = new fan();
    
    lRemote->setCommand(new fanOff(lFan));
    lRemote->buttonWasPressed();
    cout<<endl;
    
    return 0;
}
