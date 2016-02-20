//Cracked by Roath
// minority or tribe village and suburban
// Room: /d/dali/minov70.c

inherit ROOM;

void create()
{
	set("short", "青竹林");
	set("long", @LONG
一大片茂密的青竹林向西面山里蔓延出去。此间竹子青嫩，竹笋遍地，附近
卢鹿族的台夷妇女常前来采摘竹笋为食，另外也砍伐些青竹用来制做竹筒和编织
的竹篾筐篓。
LONG);
	set("objects", ([
		__DIR__"npc/tycaisun" : 1,
		]));
	set("exits", ([
		"north" : __DIR__"minov66",
		]));
	set("area", "武定镇");
	set("cost", 3);
	set("no_clean_up", 0);
	set("outdoors","dali");
	setup();
	replace_program(ROOM);
}
