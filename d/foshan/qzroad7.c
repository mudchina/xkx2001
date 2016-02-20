//Cracked by Roath
// Jay 8/9/96

inherit ROOM;

void create()
{
        set("short", "林间道");
        set("long", @LONG
这里是一条林间小道，在树丛中蜿蜒。东面就是泉州城的
西门吊桥，向西南可达岭南广东。
LONG
        );
        set("exits", ([
		"east" : "/d/quanzhou/xiqiao",
		"southwest" : __DIR__"qzroad6",
	]));

	set("objects", ([
                "/d/emei/obj/flower" : 1,
            "/d/shaolin/obj/caoliao" : 2,
	]));
	set("cost",1);
	set("outdoors", "wudang");
	setup();
        replace_program(ROOM);
}
