//Cracked by Roath
// santian.c 三天门 
// by Fang 8/20/96

inherit ROOM;

void create()
{
	set("short", "三天门");
	set("long", @LONG
这里是登山石阶的尽头“三天门”，再往上走就是武当绝顶了。
LONG
	);
        set("outdoors", "wudang");

	set("exits", ([
		"northdown" : __DIR__"ertian",
                "southup" : __DIR__"jinding",
	]));
	set("cost", 3);
	setup();
	replace_program(ROOM);
}

