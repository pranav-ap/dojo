import std;

using namespace std;

class Player
{
    public:
        int id;

        Player() : id(0) { }

        virtual void show()
        {
            println("Player {}", id);
        }

        void shout()
        {
            println("PLAYER!!!");
        }

        void just_player()
        {
            println("just player");
        }
};

class Hero : public Player
{
    public:
        virtual void show() override
        {
            println("Hero : {}", id);
        }

        void shout()
        {
            println("HERO!!!");
        }

        void just_hero()
        {
            println("just hero");
        }
};

void static_binding()
{
    println("=> {}", __func__);

    Player p;
    p.show();
    p.shout();
    p.just_player();

    Hero h;
    h.show();
    h.shout();
    h.just_hero();
}


void cast_child_as_parent()
{
    println("=> {}", __func__);

    Hero h;
    // child is converted here
    Player p { h };

    p.show(); // should print player
    p.shout();
    p.just_player();

    // slicing compile error
    // p.just_hero();
}

void dynamic_binding()
{
    println("=> {}", __func__);

    Hero h;
    Player& p { h };

    p.show(); // should print hero from child class
    p.shout();
    p.just_player();

    // error - cannot access child-only functions
    // p.just_hero();
}

int main()
{
    static_binding();
    dynamic_binding();
    cast_child_as_parent();

    return 0;
}
