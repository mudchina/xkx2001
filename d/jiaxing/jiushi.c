//Cracked by Roath
// Jay 8/9/96

inherit ROOM;

void create()
{
        set("short", "酒室");
        set("long", @LONG
室中琳琅满目，到处都是酒坛、酒瓶、酒葫芦、酒杯，一阵酒香
扑鼻而来。床脚摆着一张床(bed)。
LONG
        );
        set("exits", ([
		"east" : __DIR__"mzqianting",
	]));

	set("objects", ([
		__DIR__"npc/danqing" : 1,
		"/d/city/obj/hdjiudai" : 1,
		"/d/xingxiu/npc/obj/hu" : 1,
		"/d/city/obj/nuerhong" : 1,
	]));
        set("item_desc", ([
                "bed" : "普普通通的一张床。\n",
        ]));

        set("no_clean_up", 0);

	set("cost", 0);
	setup();
        replace_program(ROOM);
}
