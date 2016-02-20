//Cracked by Roath
#include <ansi.h>

inherit ROOM;

void create()
{
        set("short", "山路");
        set("long", @LONG
山路崎岖难行，遍布的石头使你走起来大费周折。走到这里
你已经觉得两臂酸麻快要支撑不住了，如果这时偷懒停下脚步的
话，马上就会有戒律院的僧兵抓你去见戒律院首座的。
LONG
        );

        set("exits", ([
                "southdown" : __DIR__"riverbank",
				"northeast" : __DIR__"xiaojing1",
        ]));

        set("outdoors", "shaolin");
        set("cost", 3);
        setup();
}
int valid_leave(object me, string dir)
{
        int current_jingli, current_dodge,bili,shenfa;
		string fam;
		object obj;
        current_jingli = me->query("jingli");
		bili = me->query("str");
		shenfa = me->query("dex");
		fam = me->query("family/family_name");
		obj = present("shui tong", me);
        if (dir == "northeast" && current_jingli >10 && (fam == "少林派") &&(obj) && (obj->query("full")))
        {
                me->set("jingli",current_jingli-random(20));
                me->improve_skill("dodge", random(shenfa));
				me->improve_skill("cuff",random(bili));
                write("你咬着牙爬上山坡，已经累得喘不过气了。\n");
        }

        else if (dir == "southeast" && current_jingli <= 10)
        {
                write("你累得实在走不动了，脚下一软，就什么也不知道了。\n");
                me->unconcious();
                return notify_fail("");
        }

        return ::valid_leave(me, dir);
}
