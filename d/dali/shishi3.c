//Cracked by Kafei
// Room: /dali/shishi3.c
// AceP

inherit ROOM;

void create()
{
	set("short", "石室");
	set("long", @LONG
这里又是一间石室。房中有张石床，床前有一个小小摇篮，墙上悬了一把七铉
琴，铉线均已断裂。床左有一石几，几上刻了十九道棋盘，布着二百余棋子，黑白
对恃，这一局(qiju)似乎并未下毕。石床床尾有一个门，门旁凿着四个字：琅寰福地。
LONG );

	set("item_desc", ([
		"qiju" : "这是一个很特别的珍珑棋局，看起来十分深奥，大有学问，你看了一会儿，觉得头昏眼花。\n",
	]));

	set("exits", ([
		"right" : __DIR__"shishi2",
		"in"    : __DIR__"shishi4",
	]));

	set("cost", 0);
	setup();
}
