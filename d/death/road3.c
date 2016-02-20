//Cracked by Roath
// Room: /d/death/road3.c

inherit ROOM;

void create()
{
	set("short", "路的尽头");
	set("long", @LONG

..... 还没想到 ....

LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "south" : "/d/death/road2",
]));

	set("no_fight", 1);
	set("cost", 0);
	setup();
//	replace_program(ROOM);
}

void init()
{
        add_action("do_suicide","suicide");

}

int do_suicide(string arg)
{
        object me = this_player();
        tell_object(me, "你还死着呢。\n");
        return 1;
}


