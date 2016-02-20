//Cracked by Roath
// Room: /d/emei/lenshan1.c
// Date: xuy /09/19/96

inherit ROOM;

void create()
{
	set("short", "冷杉林");
	set("long", @LONG
这是一片遮天蔽日的冷杉林。数人也合抱不过来的冷杉树簇在一块，棵棵
枝繁叶茂，象一蓬蓬巨伞般伸向天空，把阳光遮得丝毫也无。看地上厚厚的枯
枝烂叶，显然游客很少踏足此处。
LONG
	);

	set("exits", ([
		"northdown" : __DIR__"lingyun",
		"west" : __DIR__"leidong",
		"southup" : __DIR__"lenshan2",
	]));

	set("cost", 3);
	setup();
//	replace_program(ROOM);
}

int valid_leave(object me, string dir)
{
        int current_jingli, current_dodge;

        current_jingli = me->query("jingli");
        if (dir == "southup" && current_jingli >10)
        {
                me->set("jingli",current_jingli-random(15));
                me->improve_skill("dodge", random(10));
                write("你在冷杉林里向上爬了一阵，有些累了。\n");
        }

        else if (dir == "southup" && current_jingli <= 10)
        {
                write("你累得走不动了，忽然眼冒金星，晕了过去。\n");
                me->unconcious();
                return notify_fail("");
        }
        return ::valid_leave(me, dir);
}

#include "lenshan.h"
