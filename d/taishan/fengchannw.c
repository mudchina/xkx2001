//Cracked by Roath
// Room: /d/taishan/.c
// Date: CSWORD 96/03/25

inherit ROOM;

void create()
{
	set("short", "朱雀坛");
	set("long", @LONG
这里是封禅台西北角的朱雀坛。整个朱雀坛是个方形的广场，
四周角上各立着一竿血红的大旗。旗帜上绣着朱雀的标志，因其
得名自火鸟，坛中还燃烧着一堆熊熊烈火，与迎风而舞的大旗相
辉映。
LONG
	);

	set("exits", ([
		"southeast" : __DIR__"fengchan",
		"west" : __DIR__"zhengqi",
	]));

	set("outdoors", "taishan");
	setup();

	replace_program(ROOM);
}

