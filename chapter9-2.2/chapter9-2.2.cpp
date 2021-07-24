#include <iostream>

enum class MonsterRace
{
    orc,
    goblin,
    troll,
    ogre,
    skeleton
};

int main()
{
    MonsterRace monsterRace{ MonsterRace::skeleton };

    std::cout << static_cast<int>(monsterRace) << '\n';

    return 0;
}
