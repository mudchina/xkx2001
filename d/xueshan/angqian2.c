//Cracked by Roath
// Summer 9/25/96
#include "room.h"
#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "昂欠二楼");
        set("long", @LONG
这里是法王的寝宫。进门是一张铺着红色刺绣软垫的乌檀木大床，四壁
全是堆满了佛经的书架。
LONG
        );
        set("exits", ([
                "down" : __DIR__"angqian",
        ]));
	set("objects", ([
		"/kungfu/class/xueshan/jiumo" : 1,
	]));

	replace_program(ROOM);
	set("cost", 1);
        setup();
}
/*void init()
{
        object me = this_player();

	if (me->query_skill("xiaowuxiang", 1) >= 20
	&& me->query_skill("longxiang-banruo", 1) >=60
	&& me->query("family/master_id") == "jiumozhi" ){
                tell_object(me, "\n\n" +
        "鸠摩智查探了一下你的武功，突然说：好徒儿，进展果然不错。让我再\n" +
        "指点指点你。练我密宗的火焰刀功夫，最看重的是小无相的修为，虽然\n" +
	"你的龙象般若已有一定功底，但是没有必要再继续修练。如果你愿意，\n" +
	"我可以把你的已练成的龙象般若功化成小无相功。\n" +
        "如果愿意，键入“yes”。\n\n");
	add_action("do_yes", "yes");
	}
}
int do_yes()
{
        mapping learned;

        object me = this_player();
        learned = me->query_learned();

        me->set_skill("xiaowuxiang", me->query_skill("longxiang-banruo", 1));
        me->improve_skill("xiaowuxiang", learned["longxiang-banruo"]);
	if( me->query_skill("xiaowuxiang", 1) > 1)  me->map_skill("force", "xiaowuxiang");
        me->map_skill("longxiang-banruo");
        me->delete_skill("longxiang-banruo");

        tell_object(me, HIY "\n鸠摩智轻声告诉你如何运起小无相周天，并把手心贴在你的命门大穴，\n" +
		            "徐徐注入真气。。。你觉得你的各个周天逐渐打通了！你的小无相进步了！\n\n" NOR);

        return 1;
}
*/
