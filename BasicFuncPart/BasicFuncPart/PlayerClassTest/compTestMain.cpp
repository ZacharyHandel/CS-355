#include <iostream>
using namespace std;

#ifndef ullItem
#define ullItem
	#include "ull.h"
	#include "Item.h"
#endif
#include "Area.h"
#include "areaNode.h"
#include "Player.h"


int main()
{
    Player p1;
    p1.inventory();
    p1.take();
    p1.leave();
    p1.examine();
    return 0;
}