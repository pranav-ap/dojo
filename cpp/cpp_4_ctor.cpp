import std;

using namespace std;


void write_no_ctors()
{
    println("=> {}", __func__);

    struct Player
    {
        int id;

        // as you did not write any ctors
    };

    // compiler provides a zero-arg ctor
    // - it calls zero-arg ctor of each object member
    // - primitives get garbage values
    Player p;
    println("Player p : {}", p.id);

    Player x = p; // and a copy ctor
    println("Player x : {}", x.id);
}

void write_only_zero_ctor()
{
    println("=> {}", __func__);

    struct Player
    {
        int id;

        Player()
        {
            println("Look at the default garbage init for id : {}", id);
            id = 0;
        }
    };

    Player p;
    println("Player p : {}", p.id);

    Player x = p; // compiler provides a copy ctor
    println("Player x : {}", x.id);
}

void init_list_in_ctor()
{
    println("=> {}", __func__);

    struct Player
    {
        int id;

        Player() : id(0)
        {
            println("Already created with proper init value : {}", id);
            println("No need to overwrite");
        }
    };

    Player p;
    println("Player p : {}", p.id);

    Player x = p; // compiler provides a copy ctor
    println("Player x : {}", x.id);
}

void init_list_order()
{
    println("=> {}", __func__);

    struct Hammer
    {
        int strength;

        Hammer() : strength(100)
        {
            println("Initial Hammer strength : {}", strength);
        }
    };

    struct Nail
    {
        int length;

        Nail() : length(10)
        {
            println("Initial Nail length : {}", length);
        }
    };

    struct Player
    {
        Nail nail;
        Hammer hammer;

        Player()
        {
            // nail then hammer get init. defn order matters.
            println("Player already constructed");
        }
    };

    Player p;
    println("Player p : {}, {} ", p.hammer.strength, p.nail.length);

    struct Coach
    {
        Nail nail;
        Hammer hammer;

        Coach() : hammer(), nail()
        {
            // nail then hammer get init. defn order matters. not init list order
            println("Coach already constructed");
        }
    };

    Coach c;
    println("Coach c : {}, {} ", c.hammer.strength, c.nail.length);
}

void write_only_copy_ctor()
{
    println("=> {}", __func__);

    struct Player
    {
        int id;

        // because you gave a copy ctor, you dont get a default zero-arg ctor
        Player(const Player& p) : id(p.id) {}

        // You must write a custom ctor to create objects
        Player (int id) : id(id) {}
    };

    // Player p;  // cannot create

    Player p(1);
    println("Player p : {}", p.id);

    Player x = p;
    println("Player x : {}", x.id);

}

void write_only_custom_ctor()
{
    println("=> {}", __func__);

    struct Player
    {
        int id;

        Player (int id) : id(id) {}
    };

    // Player p;  // cannot create by zero

    Player p(1);
    println("Player p : {}", p.id);

    // cpp gives you a copy ctor
    Player x = p;
    println("Player x : {}", x.id);

}

int main()
{
    write_no_ctors();
    write_only_zero_ctor();

    init_list_in_ctor();
    init_list_order();

    write_only_copy_ctor();
    write_only_custom_ctor();

    return 0;
}
