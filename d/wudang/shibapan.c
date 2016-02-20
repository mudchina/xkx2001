//Cracked by Roath
// shibapan.c 武当十八盘
// by Fang 8/19/96

inherit ROOM;

void create()
{
	set("short", "十八盘");
	set("long", @LONG
	这是一个很大的斜坡，俗称十八盘，大石阶一级一级笔直而上，颇费脚力。
这里坡坡有神，拐拐有祠，往上十里之后即是灵霄宫。
LONG
	);
        set("outdoors", "wudang");

	set("exits", ([
		"southup" : __DIR__"shijie2",
		"northdown" : __DIR__"shiliang",
	]));

	set("cost", 3);
	setup();
	replace_program(ROOM);
}

