//Cracked by Roath
// minority or tribe village and suburban
// Room: /d/dali/minov26.c

inherit ROOM;

void create()
{
	set("short", "阳宗镇");
	set("long", @LONG
这里是强宗部的村镇，是么些蛮族的聚居区域，么些蛮族是摆夷的一支。此
处也是山间的小型平原，北面临着一片绿水，叫做明湖，这地方略微偏远些，但
有相当不少的摆夷人生活在附近。西南方有道路通向其它村镇。
LONG);
	set("objects", ([
		__DIR__"npc/byshang.c" : 1,
		]));
	set("exits", ([
		"northeast" : __DIR__"minov27",
		"southwest" : __DIR__"minov31",
		"southup" : __DIR__"minov30",
		"westup" : __DIR__"minov25",
		]));
	set("area", "阳宗镇");
	set("cost", 2);
	set("no_clean_up", 0);
	set("outdoors", "dali");
	setup();
	replace_program(ROOM);
}
