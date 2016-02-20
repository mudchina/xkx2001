//Cracked by Roath
// 陷阱  /d/shenlong/xianjing
// ywz 09/30/96
// Mongol: All non shelong people die at once, that's not reasonable.
//         Just disabled, and needs more polishments.

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "陷阱");
	set("long", @LONG
突然，四周的墙壁冒出许多锋利的钢板，向你扎了过来。完了。。。
LONG
	);

	set("exits", ([
              "up" : __DIR__"tingkou",
	]));
	set("cost", 2);

//      set("objects", ([
//              __DIR__"obj/changjian" : 3,
//              __DIR__"obj/duanjian" : 2,
//              __DIR__"obj/blade" : 1,
//              __DIR__"obj/blade" : 1,
//      ]));

	setup();
}

void init()
{
	object me = this_player();

	if( interactive(me = this_player()) ) {
	    remove_call_out("dropping");
	    call_out("dropping", 1);
	}

}

void dropping()
{
	object me = this_player();
	int f, d, p, s;
	float sn;
	sn = me->query("shen",1)*9/10;
//      s = int(sn);
	f = me->query_skill("force",1);
	d = me->query_skill("dodge",1);
	p = me->query_skill("parry",1);
	if( interactive(me = this_player()) ) {
		message_vision( HIR "$N的眼前突然出现一个无底的深渊...$N掉入了陷阱之中。\n" NOR, me);
		message_vision( HIR "陷阱中的钢板突然冒出许多锋利的钢针，深深地扎入了$N的身体中...\n" NOR, me);
//		message_vision( HIR "一声惨嚎，$N被扎死在陷阱中。\n" NOR, me);
//              if (f>=2)
//              me->set_skill("force",f-2);
//              if (d>=2)
//              me->set_skill("dodge",d-2);
//              if (p>=2)
//              me->set_skill("parry",p-2);
//              me->set("shen",sn);
//		me->receive_wound("qi", me->query("max_qi")+10, "掉入陷阱死了。");
		me->unconcious();

	}
}





