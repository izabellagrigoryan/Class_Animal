// Class_Animal.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

struct external_organs { string skin, body, head, tail, limbs, teeth, eye, nostril; };
struct internal_organs { string skeleton, skull, heart, lung; };

class Animal {

protected:
    external_organs  ex_o;
    internal_organs in_o;

    string name;

    void sound(string name){}
    void eat(string name){}
    void sleep(string name) {}
    void fly(string name){}
    void reproduction(string name){}

};

class Mammal :public Animal {
public:
    Mammal(){}
    Mammal(string name) {
        this->name = name;
        body_structure();
        eat();
    }
    void body_structure()
    {
        ex_o.limbs = "four foot";
        ex_o.skin = "fur";
        cout << this->name << "  has  " << ex_o.limbs << "  and  " << ex_o.skin << endl;
    }
    void eat()
    {
        cout << this->name << "  drinks milk" << endl;
    }
    void sleep(){}
};

class Herbivore_Mammal :public Mammal {
public:
    Herbivore_Mammal(string name):Mammal(name)
    {
        this->name = name;
        eat();
    }
    void eat()
    {
        cout << this->name << "  eats grass" << endl;
    }
};

class Predator_Mammal :public Mammal {
public:
    Predator_Mammal(string name) :Mammal(name)
    {
        this->name = name;
        eat();
    }
    void eat()
    {
        cout << this->name << "  eats meat" << endl;
    }
};

class Fish :public Animal {
public:
    Fish() {}
    Fish(string name) {
        this->name = name;
        body_structure();
    }
    void body_structure()
    {
        in_o.lung = "grunt";
        ex_o.skin = "scale";
        cout << this->name << "  has  " << in_o.lung << " and  " << ex_o.skin << endl;
    }
    virtual void reproduction()
    {
        cout << this->name << "  reproduce by spawn.  " << endl;
    }
};

class Non_Amphibious :public Fish {
public:
    Non_Amphibious(string name) :Fish(name) {
        this->name = name;
        reproduction();
    }
};

class Amphibious :public Fish {
public:
    Amphibious(string name) :Fish(name) {
        this->name = name;
        reproduction();
    }
    void reproduction()
    {
        cout << this->name << "  reproduce by eggs.  " << endl;
    }
};

class Bird :public Animal {
public:
    Bird() {}
    Bird(string name) {
        this->name = name;
        body_structure();
        reproduction();
    }
    void body_structure()
    {
        ex_o.limbs = "two foot and two wings";
        ex_o.skin = "feather";
        cout << this->name << "  has  " << ex_o.limbs << " and  " << ex_o.skin << endl;
    }
    void reproduction()
    {
        cout << this->name << "  reproduce by eggs.  " << endl;
    }
};

class Herbivore_Bird :public Bird {
public:
    Herbivore_Bird(string name) : Bird(name) {
        this->name = name;
        eat();
    }
    void eat()
    {
        cout << this->name << "  eats grass" << endl;
    }
};

class Predator_Bird :public Bird {
public:
    Predator_Bird(string name) : Bird(name) {
        this->name = name;
        eat();
    }
    
    void eat()
    {
        cout << this->name << "  eats meat" << endl;
    }
};

int main()
{
    Herbivore_Mammal herb("Cow");
    Predator_Mammal pred("Wolf");

    Herbivore_Bird chick("Chicken");
    Predator_Bird eagle("Eagle");

    Non_Amphibious whitef("Whitefish");
    Amphibious croc("Crocodile");
}

