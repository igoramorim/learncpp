#include <iostream>
#include <string>

enum class MonsterType
{
    ogre,
    dragon,
    orc,
    giantSpider,
    slime,
};

std::string getMonsterTypeString(MonsterType monsterType)
{
    switch (monsterType)
    {
        case MonsterType::ogre:
            return "Ogre";
        case MonsterType::dragon:
            return "Dragon";
        case MonsterType::orc:
            return "Orc";
        case MonsterType::giantSpider:
            return "Giant Spider";
        case MonsterType::slime:
            return "Slime";
        default:
            return "Unkown";
    }
}

struct Monster
{
    MonsterType type;
    std::string name;
    int health;
};

void printMonster(Monster monster)
{
    std::cout << "This " << getMonsterTypeString(monster.type) <<
        " is named " << monster.name <<
        " and has " << monster.health << " health." << '\n';
}

int main()
{
    Monster ogre{ MonsterType::ogre, "Torg", 145 };
    Monster slime{ MonsterType::slime, "Blurp", 23 };

    printMonster(ogre);
    printMonster(slime);

    return 0;
}
