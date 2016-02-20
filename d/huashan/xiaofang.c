//Cracked by Roath
// Room: taogu.c 小木屋
// qfy July 25, 1996.

inherit ROOM;

void reset();

void create()
{
    set("short", "小木屋");
    set("long", @LONG
一所摆设简单的小木屋。室内有一个香炉，墙上挂着一炳长剑。
当中坐着一位老者，穿著虽然朴素，却令人不由得心生敬仰。
LONG
    );

    set("exits", ([
	"out" : __DIR__"xiaojing2",
    ]));

    set("objects", ([
        "/clone/npc/feng" : 1,
    ]));

    set("no_clean_up", 0);

	set("cost", 0);
    setup();
    //replace_program(ROOM);
}
