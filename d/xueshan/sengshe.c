//Cracked by Roath
// Summer 9/25/96
#include "room.h"

inherit ROOM;

void create()
{
        set("short", "僧舍");
        set("long", @LONG
这里是一般僧侣居住的地方，一律为木构平顶小屋组成的小院。僧侣大
多集中在一处。小院内洁净朴素，清静幽雅。小院之间有小巷相通，每座僧
舍通常有三、五僧侣。北面是时伦院。
LONG
        );
	set("no_fight", "1");
        set("no_steal", "1");
	set("sleep_room",1);
        set("exits", ([
                "east" : __DIR__"zoulang",
                "north" : __DIR__"shilun",
		"south" : __DIR__"jingtang",
        ]));


	set("cost", 1);
        setup();
}
void init()
{
add_action("do_get", "get");
}
int do_get(string arg)  
{
        object obj;

        if( arg
        && objectp(obj = present(arg, environment(this_player())))
        && obj->is_character() ) {
                write("你不能搬动玩家的身体。\n");
                return 1;
        }
        else
                return 0;
} 

