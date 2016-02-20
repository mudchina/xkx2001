//Cracked by Roath
// /d/emei/fushou1.c 灵文阁

#include <room.h>
inherit ROOM;

void create()
{
        set("short", "灵文阁");
	set("long", @LONG
这里是福寿庵的灵文阁，是主持静照师太传授佛法的地方。两名青衣小尼
随侍在旁，似乎在聆听师太的教晦。阁内布置简陋，靠墙放着几把竹椅，地上
放着几个蒲团。东首有一禅房。西面是一个斋厅。
LONG
	);
	set("exits", ([
		"out" : __DIR__"fushou",
		"west": __DIR__"fushou3",
		"east": __DIR__"chanfang_fs",
	]));

        set("objects", ([
                CLASS_D("emei") + "/jingzhao" :1,
        ]));

	set("cost", 0);
	setup();
//	replace_program(ROOM);
}

int valid_leave(object me, string dir)
{
        if ( me->query("gender") != "女性" && dir == "west" ) 
                return notify_fail("西面乃峨嵋女侠休息进餐之所，这位" + 
                        RANK_D->query_respect(me) + "还请留步。\n");

        return ::valid_leave(me, dir);
}

	
