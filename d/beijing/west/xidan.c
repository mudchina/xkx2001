//Cracked by Roath
// Room: /d/beijing/west/xidan.c

inherit ROOM;

void create()
{
	set("short", "西单");
	set("long", @LONG
这是北京城里各大商号最密集的地方，京城里许多上百年的老
字号都开在这里，而富商大贾，宗室大臣也大多喜欢在这里置办房
产。西边是宣武大街，东边就是西长安街了。
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "west" : __DIR__"xuanwudajie2",
  "north" : __DIR__"yangliu",
  "east" : "/d/beijing/zijin/xichangan",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
