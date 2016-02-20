//Cracked by Roath
// Room: /city/xiting.c
// YZC 1995/12/04 

inherit ROOM;

void create()
{
	set("short", "西厅");
	set("long", @LONG
这里是衙门的西厅，乃是提督的书房。书案上凌乱地放着几本发黄的古籍。
引起你的注意的是墙上挂着一幅很大的地图(ditu)。
LONG
	);
	set("item_desc", ([
		"ditu" : "这是一幅扬州市区和市郊的地图，上面有各种颜色的圈圈点点，显见主人经常\n"
		"看它，而且看得颇为仔细，似乎在寻找一个特别的地点。\n",	
	]));
	set("exits", ([
		"east" : __DIR__"ymzhengting",
	]));
	set("objects", ([
		__DIR__"obj/lingpai" : 1,
	]));

	set("cost", 0);
	setup();
	replace_program(ROOM);
}

