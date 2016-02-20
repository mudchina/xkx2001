//Cracked by Roath
//GU MU FROM SANTA
//shidao.c

inherit ROOM;

void create()
{
	set("short", "石道");
	set("long", @LONG
总算通过了玉蜂的包围，你舒了一口气，却发现脚下踏上了一条
极窄的石道

LONG
	);

	set("exits", ([
		"south" : __DIR__"shidao",
		"north" : __DIR__"fenglin1",
	]));
	set("cost", 1);

	setup();
	replace_program(ROOM);
}







