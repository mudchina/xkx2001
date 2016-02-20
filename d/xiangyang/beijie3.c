//Cracked by Roath
// Room: /d/xiangyang/beijie3.c

inherit ROOM;

void create()
{
	set("short", "北街");
	set("long", @LONG
你走在襄阳的北街上，这离奇胜门已相距不远。路上不时可以看到江湖人
士擦肩而过，也常见到一些叫化子走动，却不是坐在地上乞讨。东面是一条窄小
的矮巷，不见有人来往。西上不远，可以望见襄阳闻名的子城“夫人城”。
LONG
	);
	set("no_clean_up", 0);
        set("coordinates", ([ "x" : 0, "y" : 5 ]) );
	set("exits", ([ /* sizeof() == 4 */
  "north" : __DIR__"qisheng",
  "east" : __DIR__"chexiang",
  "westup" : __DIR__"furenche",
  "south" : __DIR__"beijie2",
]));
	set("outdoors", "xiangyang");

	setup();
	replace_program(ROOM);
}
