//Cracked by Roath
// Room: /d/xiangyang/bingqidian.c

inherit ROOM;

void create()
{
	set("short", "兵器店");
        set("long", @LONG
这里是兵器库，到处银光闪闪，让人眼花缭乱。宝刀、宝剑、金箍棒，大
刀、长剑、哨棒，短刀、短剑、短棍，各色各样的兵器应有尽有，你一时不知
道挑什么好。
LONG );
	set("no_clean_up", 0);
	set("coordinates", ([ "x" : 4, "y" : 5 ]) );
	set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"jzjie3",
]));

	setup();
	replace_program(ROOM);
}
