//Cracked by Roath
// /d/emei/emroad6.c 小路
// Shan: 96/06/22

inherit ROOM;

void create()
{
        set("short", "小路");
        set("long", @LONG
这里是陕西境内的一条静悄悄的黄土路，两旁有些小土屋，疏疏落落的。路
上行人很少，都行色匆匆地向前赶路。北边有一座小村庄，过了小村就是西岳华
山了。
LONG
        );
        set("exits", ([
                "southeast" : "/d/wudang/wdroad5",
                "west" : __DIR__"emroad5",
                "north" : "/d/village/hsroad3",
                "south" : __DIR__"house1",
        ]));

        set("no_clean_up", 0);

        set("outdoors", "emei");

        set("cost", 1);
        setup();
        replace_program(ROOM);
}
