//Cracked by Roath
// Jay 9/04/96

inherit ROOM;

void create()
{
        set("short", "黄河岸边");
        set("long", @LONG
这里是黄河岸边。黄河流淌到这里，已经泥沙浑浊了。黄色
的河水在河床里翻滚着，咆哮着，卷起一个个巨大的漩窝。西边
有个寨子。
LONG
        );

        set("exits", ([
		"east" : __DIR__"bank2",
		"west" : __DIR__"huanghebang1",
		"south" : "/d/forest/field4",
		"north" : __DIR__"weifen",
        ]));

	set("objects", ([
            __DIR__"npc/hou-tonghai" : 1,
	]));

	set("outdoors", "huanghe");
	set("cost", 2);
        setup();
	replace_program(ROOM);
}

