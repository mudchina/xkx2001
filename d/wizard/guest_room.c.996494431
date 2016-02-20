// /d/wizard/guest_room.c

#include <room.h>
inherit ROOM;

void create()
{
	set("short", "巫师会客室");
	set("long", @LONG
这里是巫师和玩家交流的地方。如果你有什么问题需要向巫师请教，可以在
这里留言(post)。不过如果问题牵涉到解谜或者已经在帮助文件里有详细说明，
巫师们就不一定会回答。楼上是巫师休息室。
LONG
	);

	set("exits", ([
		"up": __DIR__"wizard_room",
		"west" : __DIR__"proom",
		"southeast": "/d/city/wumiao" ]));
	set("no_fight", "1");
        set("no_steal", 1);
        set("no_sleep_room", "1");
	create_door("southeast", "竹门", "northwest", DOOR_CLOSED);

	set("cost", 0);
	setup();
	call_other("/clone/board/towiz_b", "???");
}

int valid_leave(object me, string dir)
{
        if( dir=="up" && !wizardp(me) )
                return notify_fail("那里只有巫师才能进去。\n");
        return ::valid_leave(me, dir);
}

void init()
{
        add_action("do_exercise",  "exercise");
        add_action("do_exercise",  "dazuo");
        add_action("do_exercise",  "respirate");
        add_action("do_exercise",  "tuna");
        add_action("do_practice",  "practice");
        add_action("do_practice",  "lian");
        add_action("do_study",  "study");
        add_action("do_study",  "du");
}

int do_exercise(string arg)
{
        object me = this_player();
        tell_object(me, "你是来作客还是来练功啊？\n");
        return 1;
}

int do_practice(string arg)
{
        object me = this_player();
        tell_object(me, "在客厅里也想练功，太放肆了吧？\n");
        return 1;
}

int do_study(string arg)
{
        object me = this_player();
        tell_object(me, "作客还想读书，别这么认真好不好？\n");
        return 1;
}

