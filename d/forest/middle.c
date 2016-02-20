//Cracked by Roath
// Jay 7/11/96

#include "tree.h"

void create()
{
    int i;
        set("short", "半山腰");
        set("long", @LONG
这里是摩天崖的山腰。摩天崖高耸如云，石壁上光秃秃的，没有
道路。白云在周围飘来飘去，山上的枣树枝桠参差，与山下的连成一
片。
LONG
        );

        set("exits", ([
                "down" : __DIR__"foot",
		"up" : __DIR__"mty",
        ]));

	set("climbup",__DIR__"tree_m1");
	set("cost", 8);
	set("outdoors", "city");
        setup();
}


