//Cracked by Roath
//Chaos, Ryu, 3/10/97

inherit ROOM;

void create()
{
	set("short", "树丛");
	set("long", @LONG
这是一片花树繁密的树丛，枝叶密密重重，一眼望去，除了花树还是花树，完全
看不清对面。突然，前面约莫两丈远处一对眼睛碧莹莹的闪闪发光。你大吃一惊，往
后跳开几步，那眼睛却一闪就不见了。你有点害怕，还是回去吧。
LONG
	);
         set("exits", ([
                "north" : __DIR__"shidong",
     		"east" : __DIR__"caodi",
                "west" : __DIR__"harbor",
	   ]));

         set("objects", ([
                __DIR__"obj/taoshu" : 1,
        ]));

	set("cost", 2);
	set("outdoors", "taohua");

	setup();
	replace_program(ROOM);
}
