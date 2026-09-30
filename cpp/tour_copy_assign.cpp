import std;

using namespace std;


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



int main()
{
    copy_assignment_swap_version();

    return 0;
}
