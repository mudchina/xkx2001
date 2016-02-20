//Cracked by Roath
// Room: /d/heimuya/nongshe2.c
// Date: fear 99/12/08

inherit ROOM;




void create()
{
        set("short", "农舍");
        set("long", @LONG
这里盖着一间小木屋，木屋内板壁上挂着耕犁，看
来是庄稼农人的房子。窗外可以望见对面的一面小湖，
还有旁边的一座菜园。
LONG
        );

        set("exits", ([
                "south" : __DIR__"lake",
        ]));

        set("objects", ([
                __DIR__"npc/kid" : 1,
        ]));

        set("cost", 1);
        setup();
        replace_program(ROOM);
}

