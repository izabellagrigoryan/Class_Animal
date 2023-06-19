// Class_Animal.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

class external_organs { public: string skin, body, limbs, teeth; };
class internal_organs { public: string skeleton, heart, lung; };

class Animal {
public:
    external_organs* ex_o;
    internal_organs* in_o;

    Animal() {
        this->ex_o = new external_organs;
        this->in_o = new internal_organs;
    }
    virtual void sound() { cout << "I am an Animal" << endl; }
    virtual void move() { cout << "I am not moving" << endl; }
    //copy constructor
    Animal(const Animal& an) {
        this->ex_o = new external_organs;
        this->in_o = new internal_organs;
        this->ex_o->skin = an.ex_o->skin;
        this->ex_o->body = an.ex_o->body;
        this->ex_o->limbs = an.ex_o->limbs;
        this->ex_o->teeth = an.ex_o->teeth;
        this->in_o->skeleton = an.in_o->skeleton;
        this->in_o->heart = an.in_o->heart;
        this->in_o->lung = an.in_o->lung;
    }
    //operator assignment
    Animal& operator=(const Animal& an) {
        if (this != &an) {
            delete this->ex_o;
            delete this->in_o;

            this->ex_o = new external_organs;
            this->in_o = new internal_organs;
            this->ex_o->skin = an.ex_o->skin;
            this->ex_o->body = an.ex_o->body;
            this->ex_o->limbs = an.ex_o->limbs;
            this->ex_o->teeth = an.ex_o->teeth;
            this->in_o->skeleton = an.in_o->skeleton;
            this->in_o->heart = an.in_o->heart;
            this->in_o->lung = an.in_o->lung;
        }
        return *this;
    }
    virtual ~Animal() { delete ex_o; delete in_o; cout << "I'm destructor" << endl; }
};

class Mammal :public Animal {
public:
    virtual void sound() { cout << "I am a Mammal" << endl; }
    void move() override 
    { cout << "I am walking" << endl; } 
    
    virtual ~Mammal() { }
};

class Cat :public Mammal {
public:   
    virtual void sound() { cout << "I am a Cat" << endl; }
    void move() override
    {
        cout << "I am clawing" << endl;
    }

    virtual ~Cat() { }
};

class Horse :public Mammal {
public:
    virtual void sound() { cout << "I am a Horse" << endl; }
    void move() override
    {
        cout << "I am running" << endl;
    }

    virtual ~Horse() { }
};

class Wolf :public Mammal {
public:
    virtual void sound() { cout << "I am a Wolf" << endl; }
    
    virtual ~Wolf() { }
};

class Fish :public Animal {
public:
    virtual void sound() { cout << "I am a Fish" << endl; }
    virtual void move() final
    {
        cout << "I am swimming" << endl;
    }

    virtual ~Fish() { }
};

class Whitefish:public Fish {
public:
    virtual void sound() { cout << "I am a Whitefish" << endl; }

    virtual ~Whitefish() { }
};

class Crocodile : public Fish{
public:
    virtual void sound() { cout << "I am a Crocodile" << endl; }

    virtual ~Crocodile() { }
};

class Bird :public Animal {
public:
    virtual void sound() { cout << "I am a Bird" << endl; }
    void move() final
    {
        cout << "I am flying" << endl;
    }

    virtual ~Bird() { }
};

class Chicken :public Bird {
public:
    void sound() { cout << "I am a Chicken" << endl; }

    virtual ~Chicken() { }
};

class Eagle :public Bird {
public:
    void sound() { cout << "I am an Eagle" << endl; }

    virtual ~Eagle() { }
};

int main()
{ 
    Animal* animals[7];
    animals[0] = new Cat; 
    animals[1] = new Horse;
    animals[2] = new Wolf; 
    animals[3] = new Crocodile; 
    animals[4] = new Whitefish; 
    animals[5] = new Chicken; 
    animals[6] = new Eagle;   

    for (int i = 0; i < 7; i++)
         animals[i]->sound();
    cout << endl;
    for (int i = 0; i < 7; i++)
        animals[i]->move();

    for(int i = 0; i < 7; i++)
        delete animals[i];

}

