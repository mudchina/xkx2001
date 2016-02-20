//Cracked by Roath

inherit ROOM;

void create()
{
	set("short", "山路");
	set("long", @LONG
这里是一片农田。不远处有一些村庄，炊烟袅袅升起。村庄周围
是一块块的田地，田里有一些正在耕作的农人。
LONG
	);

	set("exits", ([
                "southeast" : "/d/jiaxing/qzroad2",
		"northeast" : __DIR__"taihu",
                "north" : "/d/forest/clforest4",
	]));

	set("outdoors", "taihu");
	set("cost", 3);
	setup();
	replace_program(ROOM);
}

