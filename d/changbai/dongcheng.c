//Cracked by Roath
// Room: dongcheng.c

inherit ROOM;

void create()
{
	set("short", "东城");
	set("long", @LONG
这里是用黄土铺就的街道，街上的行人不多，看起来很冷清。偶尔有几
个身着异域服饰的行人走过，看起来是满族，鲜祖的居民。西面传来嘈杂的
叫卖声。南面是一排黄泥垒成的土房，里面有嬉笑的声音。
LONG
	);

	set("exits", ([
		"south" : __DIR__"tuyao",
                "east" : __DIR__"xuedi1",
                "west" : __DIR__"jishi",
                "northeast" : __DIR__"huanglu1",
	]));

        set("outdoors", "changbai");
        set("cost", 1);

	setup();
	replace_program(ROOM);
}

