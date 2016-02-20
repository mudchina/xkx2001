//Cracked by Roath
// 白驼改版
// maco 2/17/2000
#include <room.h>

inherit ROOM;

void create()
{
        set("short", "灵蛇阁");
        set("long", @LONG
这是“西毒”欧阳锋的起居室，也是练功之地，空荡荡的房中弥漫
着一股肃杀之气。床头木案上摆着一具铁筝，正对房门的石墙上绘了一
条张口吐舌的双头怪蛇，形象十分诡异。铺地石板的缝隙中不绝传出嗤
嗤之声，似有大群虫蛇在地板下蠕蠕而动。
LONG
        );
        set("exits", ([ 
	    "east" : __DIR__"changlang2",
	    "down" : __DIR__"base1",
        ]));

        set("objects", ([ 
            CLASS_D("baituo")+"/feng" : 1,
	    "/d/xingxiu/npc/snake" : 2,
         ]) );
	set("cost", 1);
	create_door("down", "密窖石门", "up", DOOR_CLOSED);
        
        setup();
}

int valid_leave(object me, string dir)
{
	object feng;

    if (dir == "down") {
	if (feng = present("ouyang feng", environment(me)) ) {
	if (me->query("family/family_name")!="白驼山"){ 
		feng->kill_ob(me);
		return notify_fail("欧阳锋怒喝道：哪里来的野种，胆敢私闯老夫的密室？！\n");
	}
	if (me->query("family/generation")>3) {
		command("pat "+me->query("id"));
		return notify_fail("欧阳锋说道：等你在我庄里呆得长些我再让你下去练功吧。\n");
	}
	}
    }
    return ::valid_leave(me,dir);
}
 
	

