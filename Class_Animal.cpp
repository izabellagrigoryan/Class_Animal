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
    ~Animal() { delete ex_o; delete in_o; }
};

class Mammal :public Animal {
public:
    virtual void sound() { cout << "I am a Mammal" << endl; }
};

class Cat :public Mammal {
public:
    Cat() {
        sound();
    }
    //copy constructor
    Cat(const Cat& an) {
        sound();
    }
    void sound() { cout << "I am a Cat" << endl; }
};

class Horse :public Mammal {
public:
    Horse() {
        sound();
    }
    //copy constructor
    Horse(const Horse& an) {
        sound();
    }
    void sound() { cout << "I am a Horse" << endl; }
};

class Wolf :public Mammal {
public:
    Wolf() {
        sound();
    }
    void sound() { cout << "I am a Wolf" << endl; }
};

class Fish :public Animal {
public:
    virtual void sound() { cout << "I am a Fish" << endl; }
};

class Whitefish:public Fish {
public:
    Whitefish() {
        sound();
    }
    //copy constructor
    Whitefish(const Whitefish& an) {
        sound();
    }
    void sound() { cout << "I am a Whitefish" << endl; }
};

class Crocodile : public Fish{
public:
    Crocodile() {
        sound();
    }
    //copy constructor
    Crocodile(const Crocodile& an) {
        sound();
    }
    virtual void sound() { cout << "I am a Crocodile" << endl; }
};

class Bird :public Animal {
public:
    virtual void sound() { cout << "I am a Bird" << endl; }
};

class Chicken :public Bird {
public:
    Chicken() {
        sound();
    }
    //copy constructor
    Chicken(const Chicken& an) {
        sound();
    }
    void sound() { cout << "I am a Chicken" << endl; }
};

class Eagle :public Bird {
public:
    Eagle() {
        sound();
    }
    //copy constructor
    Eagle(const Eagle& an) {
        sound();
    }
    void sound() { cout << "I am an Eagle" << endl; }
};

int main()
{
    Cat cat;
    Cat cat2 = cat;
    Cat cat3;
    cat3 = cat2;
  
    Animal *horse = new Horse;
    horse->sound();
    delete horse;
    Wolf wolf;

    Chicken chicken;
    Eagle eagle;

    Whitefish whitef;
    Crocodile croc;
}

