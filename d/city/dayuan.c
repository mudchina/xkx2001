//Cracked by Roath
// Room: /city/dayuan.c
// YZC 1996/11/13 

inherit ROOM;

void create()
{
	set("short", "大院子");
	set("long", @LONG
这里是一块用篱笆围成的大院子，院子中立了一块用花岗岩制成的石碑，上
面雕刻了几行文字，好象是为了纪念什么人而立在这儿的。这里极其宁静，远处
传来的鸟叫声显得格外清脆，和扬州繁华的城里形成了一个鲜明的对比。向西便
又回到了破庙，向东远眺是一片绿油油的稻田。
LONG
	);

	set("exits", ([
		"west" : __DIR__"xiaomiao",
	]));

	set("objects", ([
	]));

	set("cost", 0);
	setup();
	replace_program(ROOM);
}

