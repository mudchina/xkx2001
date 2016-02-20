//Cracked by Roath
// Jay 7/11/96
inherit ROOM;


void create()
{
    int i;
        set("short", "山洞");
        set("long", @LONG
山洞里有一些简单的生活用具，显示出这里的主人过着简朴的
生活。洞角有张床可以睡觉。
LONG
        );

        set("exits", ([
                "west" : __DIR__"mty1",
        ]));
	set("objects", ([
                "/clone/weapon/tieguo" : 1
        ]));
        set("sleep_room", "1");
        set("no_fight", "1");

	set("cost", 1);
        setup();
        replace_program(ROOM);
}


