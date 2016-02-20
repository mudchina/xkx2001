//Cracked by Kafei
// road: /zhongnan/nyudiziqinshi.c

inherit ROOM;

void create()
{
        set("short", "弟子休息室");

        set("long",@LONG
由於古墓派只收女弟子，墓中也只有此一间休息室。室中几张石床上
铺了些被褥，打埽的挺是干净的。墙边有个小桌子，上面放了个铜镜和一
些胭脂，有个弟子正在打扮。从北的小门出去是一条走道。
LONG);

        set("exits",([ "north" : __DIR__"zoudao4",

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

        if ( dir == "north" ) {
                for (i=0; i<sizeof(inv); i++) {
                        if (inv[i]->is_character())
                        return notify_fail("你不能带着其他玩家离开休息室。\n");
                }
        }
        return ::valid_leave(me, dir);
}

