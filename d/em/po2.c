//Cracked by Roath
// po2.c 钻天坡
// Shan: 96/06/22

inherit ROOM;

void create()
{
        set("short", "钻天坡");
        set("long", @LONG
莲花石与洗象池之间，道路陡绝，石栈若齿，直上蓝天，石蹬达一千三百
多级，是在陡峭山壁上开凿出来的坡道。人行其上，前后顶踵相接，一如登天。
这段路叫「鹁鸽钻天」，这段陡坡也因此而叫「钻天坡」。这里西上坡顶便到
洗象池，东下可达莲花石。
LONG
        );
        set("exits", ([
		"westup" : __DIR__"xixiang",
                "eastdown" : __DIR__"po1",
        ]));

	set("outdoors", "emei");

	set("cost", 5);
        setup();
//	replace_program(ROOM);
}

int valid_leave(object me, string dir)
{
        int current_jingli, current_dodge;

        current_jingli = me->query("jingli");
        if (dir == "westup" && current_jingli >10)
        {
                me->set("jingli",current_jingli-random(20));
                me->improve_skill("dodge", random(8));
                write("你在钻天坡往上爬了一阵，终于到了洗象池，好累人。\n");
        }

        else if (dir == "westup" && current_jingli <= 10)
        {
                write("你累得走不动了，忽然眼冒金星，晕了过去。\n");
                me->unconcious();
                return notify_fail("");
        }
        return ::valid_leave(me, dir);
}

