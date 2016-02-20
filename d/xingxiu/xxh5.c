//Cracked by Roath
// Room: /d/xingxiu/xxh5.c
// Jay 3/18/96

inherit ROOM;

void create()
{
        set("short", "星宿海");
        set("long", @LONG
这里是星宿海的尽头。因为附近有野羊出没，所以星宿派弟子常常在此烤羊肉串
吃。当打不到野羊时，他们就抢山下牧人的羊。
LONG
        );

        switch(random(3)){
        case 0:
                set("objects", ([ "/d/xingxiu/npc/scorpion" : 1,
                                  __DIR__"npc/boshou"       : 1,
                                 __DIR__"npc/obj/yangrou.c" : 2]));
                break;
        case 1:
                set("objects", ([ "/d/xingxiu/npc/spider"   : 1,
                                  __DIR__"npc/boshou"       : 1,
                                 __DIR__"npc/obj/yangrou.c" : 2]));
                break;
        case 2:
                set("objects", ([ "/d/xingxiu/npc/centipede" :1,
                                  __DIR__"npc/boshou"       : 1,
                                 __DIR__"npc/obj/yangrou.c" : 2]));
                break;
        }       

        set("exits", ([
	     "north" : __DIR__"forest1",	
             "southeast" : __DIR__"xxh3",
             "southwest" : __DIR__"xxh4",
        ]));
 
        set("no_clean_up", 0);
        set("outdoors", "xingxiuhai");

        set("cost", 2);
        setup();
        replace_program(ROOM);

}

