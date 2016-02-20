//Cracked by Roath
// pan12.c 十二盘
// Shan: 96/06/22

inherit ROOM;

void create()
{
        set("short", "十二盘");
        set("long", @LONG
这里石阶陡折多弯，号称「十二盘」。由此西上可达华严顶，东下则到万
年庵。
LONG
        );
        set("exits", ([
		"up" : __DIR__"huayanding",
                "northeast" : __DIR__"pan13",
        ]));


	set("outdoors", "emei");

	set("cost", 4);
        setup();
}

int valid_leave(object me, string dir)
{
        int current_jingli, current_dodge;

        current_jingli = me->query("jingli");
        if (dir == "up" && current_jingli >10)
        {
                me->set("jingli",current_jingli-random(10));
                me->improve_skill("dodge", random(5));
                write("你沿十二盘又往上爬了一阵，终于到了华严顶，好累人。\n");
        }

        else if (dir == "up" && current_jingli <= 10)
        {
                write("你累得走不动了，忽然眼冒金星，晕了过去。\n");
                me->unconcious();
                return notify_fail("");
        }
        return ::valid_leave(me, dir);
}

