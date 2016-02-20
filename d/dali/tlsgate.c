//Cracked by Kafei
// AceP

inherit ROOM;

void create()
{
	set("short", "圣崇寺");
	set("long", @LONG
这里就是大理皇室的家庙----圣崇寺了，大理百姓叫惯了，都叫这
儿做天龙寺，大理的历代皇帝退位后都在这儿出家。此地背负苍山，面
临洱水，极占形胜。
LONG
	);

	set("exits", ([
		"south" : __DIR__"diancang.c",
	]));


	set("cost", 1);
	set("outdoors", "dali");
	setup();
}
