//Cracked by Roath
// Jay 8/9/96

inherit ROOM;

void create()
{
        set("short", "佛山镇街");
        set("long", @LONG
凤家在佛山是首屈一指的大户，凤家的家丁常牵着狼狗鱼肉
乡里。一般的百姓只好忍辱偷生。路北有家烧饼油条铺，里面传
出阵阵香气。
LONG
        );
        set("exits", ([
		"east" : __DIR__"street4",
		"west" : __DIR__"street2",
		"north" : __DIR__"shaobing",
	]));

	set("objects", ([
		__DIR__"npc/zhong2" : 1,
		"/d/city/npc/wolfdog" : 2,
	]));
	set("cost",1);
	set("outdoors", "wudang");
	setup();
        replace_program(ROOM);
}
