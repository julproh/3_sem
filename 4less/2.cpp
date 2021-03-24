#include <iostream>

using namespace std;

struct Monster
{
    string name;
    int hp;
    bool fireRes;
    bool MagicRes;
    bool slashinRes;
    bool bluntRes;
};

void delDemage(int demage, Monster &monster, bool isfire, bool ismagic, bool isslashing, bool isblunt) {
    if(isfire && monster.fireRes) {
        monster.hp = demage/2.0;
    }
}
int main () {
    short fireResOption = 1;
    short magicResOption = 2;
    short slashResOption = 4;
    return 0;
}