import std;

using namespace std;

void child_dtor_called_before_parent_dtor()
{
    class Player
    {
        public:
            Player()
            {
                println("Player Ctor");
            }

            virtual ~Player()
            {
                println("Player Dtor");
            }
    };

    class Hero : public Player
    {
        public:
            Hero()
            {
                println("Hero Ctor");
            }

            ~Hero()
            {
                println("Hero Dtor");
            }
    };


    Hero h;
    // look at the order of ctor and dtor
}


void reverse_order_of_attributes_defns()
{
    struct Item {
        string name;

        Item(string n) : name(n)
        {
            println("Item {} ctor", name);
        }

        ~Item()
        {
            println("Item {} dtor", name);
        }
    };

    struct Player
    {
        Item a = string("a");
        Item b = string("b");
    };

    Player p;

    /*
     Item a ctor
     Item b ctor
     Item b dtor
     Item a dtor
     */
}

int main()
{
    // child_dtor_called_before_parent_dtor();

    reverse_order_of_attributes_defns();

    return 0;
}
