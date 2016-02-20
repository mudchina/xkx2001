//Cracked by Roath
// Ryu, 5/10/97

inherit ROOM;

void create()
{
	set("short", "冰川古道");
	set("long", @LONG
神秘的千年古道，终年积雪，云雾缭绕，杳无人烟，素以荒凉、
艰险而闻名於世，是古丝道上极难逾越的天险。不过时而有西域马
的长嘶、骆驼队的铃声由远而来，那是赶着满载丝绸、茶叶的马匹
骆驼的商队。
LONG
	);
	set("exits", ([
                "northup" : __DIR__"ertai",
                "eastdown" : __DIR__"gudao2",
        ]));
	set("objects", ([
		__DIR__"npc/trader": 1,
	]));
	set("cost", 3);
	set("outdoors", "tianshan");

	setup();
	replace_program(ROOM);
}
