//
//  main.cpp
//  DecoratorXYZ
//
//  Created by ansao on 1/15/20.
//  Copyright © 2020 ansao. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>

using namespace std;


class I
{
public:
    virtual ~I() {}
    virtual void beh() = 0;
};

class A : public I
{
public:
    ~A()
    {
        cout<< "dtor A";
    }
    void beh()
    {
        cout<< "A";
    }
};



class D:public I
{
    I *iObj;
public:
    D(I *core)
    {
        iObj = core;
    }
    void beh()
    {
        iObj->beh();
    }
    
    ~D()
    {
        delete iObj;
    }
};

class X : public D
{
public:
    X(I *iObj) : D(iObj){}
    void beh()
    {
        D::beh();
        cout<<"X";
    }
};

class Y : public D
{
public:
    Y(I *iObj) : D(iObj){}
    void beh()
    {
        D::beh();
        cout<<"Y";
    }
};


class Z : public D
{
public:
    Z(I *iObj) : D(iObj){}
    void beh()
    {
        D::beh();
        cout<<"Z";
    }
};



int main(int argc, const char * argv[])
{
    I *an = new A;
    I *anX = new X (new A);
    I *anXY = new Y (new X (new A));
    I *anXYZ = new Z(new Y (new X (new A)));
    
    an->beh();
    cout<<endl;
    anX->beh();
    
    cout<<endl;
    anXY->beh();
    
    cout<<endl;
    anXYZ->beh();
    
    cout<< "\nMain Decorator \n";
    return 0;
}
