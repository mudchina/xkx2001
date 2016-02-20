//Cracked by Roath
// Jay 8/9/96

inherit ROOM;

void create()
{
        set("short", "棋室");
        set("long", @LONG
只见好大一间房中，除了一张石几、两只软椅之外，空荡荡
地一无所有。床脚摆着一张床(bed)。
LONG
        );
        set("exits", ([
		"west" : __DIR__"mzqianting",
	]));

	set("objects", ([
		__DIR__"npc/heibai" : 1,
	]));
        set("item_desc", ([ 
                "bed" : "普普通通的一张床。\n",
        ]));

        set("no_clean_up", 0);

	set("cost", 0);
	setup();
        replace_program(ROOM);
}
