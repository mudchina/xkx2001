//Cracked by Roath
// Jay 7/12/96

inherit ROOM;

void create()
{
    int i;
        set("short", "闺房");
        set("long", @LONG
这里是萧家小姐的闺房，现在是她和新姑爷的洞房了。
LONG
        );

        set("objects", ([
	    __DIR__"npc/zhonghui" : 1,
	    __DIR__"npc/guannan" : 1,
	]));

        set("exits", ([
		"west": __DIR__"huayuan",
        ]));

	set("cost", 0);
        setup();
	replace_program(ROOM);
}

