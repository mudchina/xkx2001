//Cracked by Roath
// Room: baihe.c

inherit ROOM;

void create()
{
	set("short", "白河");
	set("long", @LONG
这里是长白山下的一个小村，只有四，五间粗陋的小木屋。这里并没有
固定的居民，木屋都是进山采参的参客所盖，为的是在进山前能在这里好好
的休息一下。东面就是巍峨耸立的长白大山。
LONG	);
	set("exits", ([ 
              "west" : __DIR__"gucd",
              "east" : __DIR__"milin1",
        ]));
	
        set("outdoors", "changbai");
        set("cost", 3);

	setup();
	replace_program(ROOM);
}
