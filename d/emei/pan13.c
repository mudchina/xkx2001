//Cracked by Roath
// pan13.c 十二盘
// Shan: 96/06/22

#include <ansi.h>;
inherit ROOM;

void create()
{
        set("short", "十二盘");
        set("long", @LONG
这里石阶陡折多弯，号称「十二盘」。你见路边有个八音池，有人正在向
池中击掌(clap)。由此西上可达华严顶，东下则到万年庵。
LONG
        );
        set("exits", ([
		"southwest" : __DIR__"pan12",
                "eastdown" : __DIR__"pan14",
        ]));

	set("outdoors", "emei");

	set("cost", 4);
        setup();
}

void init()
{
    add_action("do_clap", "clap");
}

int do_clap(string arg)
{
    object me = this_player();

	if (me->query("jing") < 30)
                return notify_fail("你已经没有精力击掌了耶。\n");

    message_vision(
"池内忽然有蛙大鸣一声，接着群蛙次第相合，最后又是一蛙大鸣，群蛙便嘎然
而止，其数正好为八。\n", this_player());

    if (me->query_skill("strike", 1) < 30) {
	me->receive_damage("jing", 25, "失足掉进八音池淹死了");
	me->improve_skill("strike", me->query_str());
	tell_object(me, HIY"你的基本掌法进步了。\n"NOR);
    }
    return 1;
}

int valid_leave(object me, string dir)
{
        int current_jingli, current_dodge;

        current_jingli = me->query("jingli");
        if (dir == "southwest" && current_jingli >10 
	&& me->query_skill("dodge", 1) < 100)
        {
                me->set("jingli",current_jingli-random(10));
                me->improve_skill("dodge", random(5));
                write("你爬上了十二盘，觉得上山的路又陡又弯，好累人。\n");
        }

        else if (dir == "southwest" && current_jingli <= 10)
        {
                write("你累得走不动了，忽然眼冒金星，晕了过去。\n");
                me->unconcious();
                return notify_fail("");
        }
        return ::valid_leave(me, dir);
}

