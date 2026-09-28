#include <initializer_list>
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

void initializer_list_arg_ctor()
{
    println("=> {}", __func__);

    struct Bag
    {
        vector<int> marks;

        Bag(initializer_list<int> ms) : marks(ms) {}

        void print()
        {
            for (const auto& m: marks)
            {
                println("{} ", m);
            }
        }
    };

    Bag b {1, 2, 3};
    b.print();
}

void delegate_ctor()
{
    println("=> {}", __func__);

    struct Player
    {
        int id;

        Player() : Player {0} {}

        Player(int id): id(id) {}
    };

    Player p;
    println("Player p : {}", p.id);
}

void use_of_explicit()
{
    println("=> {}", __func__);

    struct Player
    {
        int id;

        // make it explicit and you get a compiler error
        Player(int id) : id(id) {}
    };

    // implicit construction
    Player p = 1;
    println("Player p : {}", p.id);
}

void copy_assignment()
{
    struct Player
    {
        int id;

        Player() : id(0) {}

        Player(int id) : id(id) {}

        Player& operator=(const Player& rhs)
        {
            if (this != &rhs) {
                id = rhs.id;
            }

            return *this;
        }
    };

    Player p(1);
    println("Player p : {}", p.id);

    Player x;
    println("Player x : {}", x.id);

    x = p;
    println("Player x : {}", x.id);
}


void copy_assignment_swap_version()
{
    struct Player
    {
        int id;

        Player() : id(0) {}

        Player(int id) : id(id) {}

        Player& operator=(const Player& rhs)
        {
            // lets use the copy ctor instead of repeating logic
            Player temp(rhs);
            using std::swap;
            swap(id, temp.id);

            return *this;
        }
    };

    Player p(1);
    println("Player p : {}", p.id);

    Player x;
    println("Player x : {}", x.id);

    x = p;
    println("Player x : {}", x.id);
}


void write_default_member_init()
{
    println("=> {}", __func__);

    struct Gadget {
        int i = 0;
        int score;

        Gadget(int s)
        {
            println("Gadget i = {}", i);
            println("Gadget score = {}", score);
            score = s;
            println("Gadget score = {}", score);
        }
    };

    Gadget g(100);
}


int main()
{
    // write_no_ctors();
    // write_only_zero_ctor();

    // init_list_in_ctor();
    // init_list_order();

    // write_only_copy_ctor();
    // write_only_custom_ctor();

    // initializer_list_arg_ctor();

    // delegate_ctor();
    // use_of_explicit();

    // copy_assignment();
    copy_assignment_swap_version();

    // write_default_member_init();

    return 0;
}
