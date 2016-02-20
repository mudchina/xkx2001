//Cracked by Roath
// Room: /city/beidajie2.c
// YZC 1995/12/04 

inherit ROOM;

void create()
{
	set("short", "北集市");
	set("long", @LONG
这里是扬州城的北集市。一到庙会时节这里往往都被人挤得水泻不通，东边
是一座两层的楼阁，挂着“太白遗风”的招帘，门额上悬挂一方横匾，“醉仙楼”
三字擦得闪闪发亮，乃是苏学士的手笔。阵阵酒肉酒香让你垂涎欲滴。西边是一
座古朴的庙宇，香火缭绕，那就是天下习武之人所共同敬仰的武庙了。
LONG
	);
        set("outdoors", "city");

	set("exits", ([
		"east" : __DIR__"zuixianlou",
		"south" : __DIR__"beidajie1",
		"west" : __DIR__"wumiao",
		"north" : __DIR__"beimen",
	]));

	set("objects", ([
                CLASS_D("shaolin") + "/xingzhe" : 1,
	]));

	set("cost", 1);
	setup();
}
int valid_leave(object me, string dir)
{
        if (dir =="west" && this_player()->query("PKS") > 100
	&& this_player()->query_condition("killer") > 0
        && (int)this_player()->query("sg/exp") < 1000 )
	return notify_fail("你的脚步到这突然挪不动了。\n");
        return ::valid_leave(me, dir);
}

