//Cracked by Roath
// lianhua.c 莲花石
// Shan: 96/06/22

inherit ROOM;

void create()
{
        set("short", "莲花石");
        set("long", @LONG
这是莲花石。此处岩石纹理纵横，形似莲花，颜如芙蓉，仿佛萼瓣层叠，
细蕊欲绽。上有一庵，叫「莲花社」。由此往西上直达洗象池，东下左通华严
顶，右通九老洞。
LONG
        );
        set("exits", ([
		"westup" : __DIR__"po1",
                "southeast" : __DIR__"jiulao1",
                "eastdown" : __DIR__"huayanding",
        ]));

        set("objects", ([
                "/kungfu/class/emei/zhao.c" :1,
                "/kungfu/class/emei/su.c" :1,
        ]));

	set("outdoors", "emei");

	set("cost", 2);
        setup();
}

int valid_leave(object me, string dir)
{
        int current_jingli, current_dodge;

        current_jingli = me->query("jingli");
        if (dir == "westup" && current_jingli >10)
        {
                me->set("jingli",current_jingli-random(20));
                me->improve_skill("dodge", random(8));
                write("你在钻天坡往上爬了一阵，好累人。\n");
        }

        else if (dir == "westup" && current_jingli <= 10)
        {
                write("你累得走不动了，忽然眼冒金星，晕了过去。\n");
                me->unconcious();
                return notify_fail("");
        }
        return ::valid_leave(me, dir);
}

