//Cracked by Roath
// Room: zoulang1.c 走廊１
// qfy July 7, 1996.

inherit ROOM;

void reset();
int valid_leave();

void create()
{
    set("short", "走廊");
    set("long", @LONG
走廊两旁都有矮墙，将后院间隔起来。北边是「刀刃部」，可在那里学刀
法。南院是「棒杖部」，可学棒法和杖法。
LONG
    );

    set("exits", ([
	"north" : __DIR__"daobu",
	"south" : __DIR__"bangbu",
	"east" : __DIR__"qianting",
	"west" : __DIR__"zoulang2",
    ]));

    set("no_clean_up", 0);

	set("cost", 1);
    setup();
    //replace_program(ROOM);
}
