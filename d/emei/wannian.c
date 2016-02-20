//Cracked by Roath
// wannian.c 万年庵
// Shan: 96/06/22

inherit ROOM;

void create()
{
        set("short", "万年庵");
	set("long", @LONG
万年庵建在一座突起的山峰上，周围古木森森，清泉淙淙，闲步无坎，吟
游无坷，景色非常迷人。由此西上过十二盘可达华严顶，南下至白龙洞。
LONG
	);
	set("exits", ([
		"westup" : __DIR__"pan15",
		"southdown" : __DIR__"bailong",
		"enter" : __DIR__"wannian1",
	]));

        set("outdoors", "emei" );

	set("cost", 1);
	setup();
}

int valid_leave(object me, string dir)
{
        int current_jingli, current_dodge;

        current_jingli = me->query("jingli");
        if (dir == "westup" && current_jingli >10)
        {
                me->set("jingli",current_jingli-random(10));
                me->improve_skill("dodge", random(6));
                write("你爬上了十二盘，觉得上山的路又陡又弯，好累人。\n");
        }

        else if (dir == "westup" && current_jingli <= 10)
        {
                write("你累得走不动了，忽然眼冒金星，晕了过去。\n");
                me->unconcious();
                return notify_fail("");
        }
        return ::valid_leave(me, dir);
}

