#include <iostream>

class Character {
public:
  Character() : Agility{5}{}
  Character(int Agility) : Agility{Agility}{}
  int Agility;
};

class Human : virtual public Character {
public:
  Human() : Character(8){}
};

class Elf : virtual public Character {
public:
  Elf() : Character(10){}
};

class HalfElf : public Elf, public Human {};

int main(){
  HalfElf Elrond;
  std::cout << "Elrond Agility: "
    << Elrond.Agility;
}
