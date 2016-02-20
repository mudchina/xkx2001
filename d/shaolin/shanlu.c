//Cracked by Roath
#include <ansi.h>

inherit ROOM;

void create()
{
        set("short", "山路");
        set("long", @LONG
这里是少林僧人们为了挑水专门开凿出的一条小路，整个山
路只能容一个人行走。寺里为了让这些武僧能够更好地练功就规
定挑水的人必须平举双臂提桶而行。山路极陡，而且又湿又滑，
一不小心就会摔个跟头。

LONG
        );

        set("exits", ([
                //"eastup" : __DIR__"pinglu",
                "southdown" : __DIR__"riverbank",
        ]));
	switch( random(3) ){
	case 0 : 
		set("exits/up", __DIR__"shanlu1");
		break;
	case 1 :
		set("exits/westup", __DIR__"shanlu1");
		break;
	case 2 :
		set("exits/northwest", __DIR__"shanlu1");
		break;
	default :
		set("exits/northup", __DIR__"shanlu1");
		break;
	}

        set("outdoors", "shaolin");
        set("cost", 5);
        setup();
}

int valid_leave(object me, string dir)
{
        object ob;
	ob = present("shui tong", me);
	if( random((int)me->query("kar")) <= 3){
		me->receive_damage("qi", 30, "在山上摔死了");
                me->receive_wound("qi",  20, "在山上摔死了"); 
		if (ob){
			if (random(30) == 1) {
			message_vision(HIB"$N突然脚下一滑，打了个趔趄，还好没摔倒！\n"NOR, me);
			message_vision(HIR"$N却发现水桶不小心撞到了路边的石头上，撞了个粉碎！\n"NOR, me);
			destruct(ob);
			}
		else{	     
            message_vision(HIG"$N脚下一滑，不小心摔了个跟头！\n"NOR, me);
			message_vision(HIG"结果桶里的水全部洒出去了！\n"NOR, me);
			ob->delete("full");
			ob->set("water_level",0);
			
		}
		}
		else			
				{
                message_vision(HIR"$N脚下一滑，踩了个空！\n"NOR, me);
				me->move("/d/shaolin/riverbank");
                return notify_fail(HIR"你从山上滚了下来，只觉得浑身无处不疼，还受了几处伤。\n"NOR);
        }
	}
        return ::valid_leave(me, dir);
}
                
