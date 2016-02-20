//Cracked by Roath
// road: /zhongnan/nyuqinshi.c

inherit ROOM;

void create()
{
        set("short","女厢房");

        set("long",@LONG
这ㄦ是女厢房。虽然全真教的女弟子不多，但在清净散人孙不二的
指导下，也能不让须眉。这ㄦ和男弟子寝室布置的大同小异，几张木床
和一张桌子，床上的被子折的整整齐齐，并且还有一股香香的味道。
LONG);
                       
        set("exits",([ "south" : __DIR__"liangong2",
                      ])
           );
  	set("cost",0);
        set("sleep_room", 1);
        set("no_fight", 1);
        setup();
}

int valid_leave(object me, string dir)
{
        object *inv;
        int i;


        inv = all_inventory(me);

        if ( dir == "west" || dir == "north" ) {
                for (i=0; i<sizeof(inv); i++) {
                        if (inv[i]->is_character())
                        return notify_fail("你不能带着其他玩家离开休息室。\n");
                }
        }

        return ::valid_leave(me, dir);
}



