//Cracked by Roath
// Jay 9/04/96

inherit ROOM;

void create()
{
    int i;
        set("short", "黄河岸边");
        set("long", @LONG
这里是黄河岸边。黄河流淌到这里，已经泥沙浑浊了。黄色
的河水在河床里翻滚着，咆哮着，卷起一个个巨大的漩窝。
LONG
        );

        set("exits", ([
		"east" : __DIR__"bank3",
		"west" : __DIR__"bank1",
        ]));

	set("outdoors","forest");
	set("cost", 2);
        setup();
	replace_program(ROOM);
}

