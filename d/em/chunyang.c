//Cracked by Roath
// chunyang.c 纯阳殿
// by Shan

inherit ROOM;

void create()
{
        set("short", "纯阳殿");
        set("long", @LONG
纯阳殿海拔一千余米，四面古木苍翠，幽静宜人。殿前有一石，叫普贤石，
据说普贤菩萨登山时曾坐在这里休息过。在此可纵观峨嵋诸峰，仰望金顶，悬
崖峭壁，离天咫尺。这里西上至神水庵，东下是归云阁。
LONG
        );
        set("exits", ([
		"westup" : __DIR__"shenshui",
                "eastdown" : __DIR__"guiyun",
        ]));

//        set("objects", ([
//		__DIR__"npc/monkey" :3,
//        ]));

	set("outdoors", "emei");

	set("cost", 0);
        setup();
	replace_program(ROOM);
}
