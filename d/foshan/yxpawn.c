//Cracked by Roath
// Jay 8/9/96

inherit ROOM;

void create()
{
        set("short", "英雄典当");
        set("long", @LONG
当铺里一张高高的柜台，柜台后面坐着当铺的朝奉。这家
当铺是凤老爷所开，十多年来从没人来闹过事，朝奉也就很放
心。柜台后面有五个大柜子，分别陈列着各式武器(weapon)、
护具穿戴(armor)、药物(drug)、书藉(book)、和其它各
式杂物(misc)。
LONG
        );
		set("no_sleep_room", "1");
        set("exits", ([
		"north" : __DIR__"street4",
	]));

	set("objects", ([
		"/d/qilian/npc/chaofeng" : 1,
	]));
	set("cost",1);
	set("no_beg", 1);
	setup();
        replace_program(ROOM);
}
