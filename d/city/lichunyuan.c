//Cracked by Roath
// Room: /city/lichunyuan.c
// YZC 1995/12/04 

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", GRN"丽春院"NOR);
	set("long", @LONG
你一走进来，一眼就看到大厅的墙上挂着一幅幅春宫图(tu)，一下子就明白
了这是什么地方。厅内到处张灯结彩，香气扑鼻。几名打扮得妖里妖气的女人分
站两旁对你发出媚笑。主人韦春芳上上下下、前前后后招呼着客人。从楼上传来
了阵阵打情骂俏的声音。
LONG
	);

	set("objects", ([
                CLASS_D("gaibang") + "/kongkong" : 1,
                __DIR__"npc/wei" : 1,
                __DIR__"npc/guinu" : 1,
//              "kungfu/class/shenlong/shou" : 1,
	]));

	set("item_desc", ([
		"tu" :
"                                      Ο        Ο          Ο             
                                    ┌│        │          │
      ┌—Ο┌—  —┬——Ο        │┤      ┌┘          └┐
    —┘Ο—┘    ————Ο  Ο——┘│  Ο—┼┴—  Ο——┴┼


   Ο       Ο    ΟΟΟ                 Ο                  ○
   │       │    │├┼       ┌—Ο  ┌┼                  │
   ├ Ο┬┐┤    ├└┼┐   —┘Ο——┘┤          ○┬—┐┤
   │   ┘└│    │  │                 └            │  ││
	\n"]));

	set("exits", ([
		"west" : __DIR__"nandajie3",
		"up" : __DIR__"lichun2",
	]));

	set("cost", 0);
	setup();
//	replace_program(ROOM);
}

void init()
{
	add_action("do_order", "order");
}


int do_order(string arg)
{
        object me = this_player();
        object victim;
        string arg1, arg2, arg3, msg;

        if (!arg)
                return notify_fail("你要命令什么人？\n");
/*
        if( sscanf(arg, "%s %s %s", arg1, arg2, arg3) < 2 )
                return notify_fail("指令错误！\n");
*/
        sscanf(arg, "%s %s %s", arg1, arg2, arg3);
        victim = present(arg1,environment(me));

        if (!victim)
                return notify_fail("这里并无此人！\n");

        if (!living(victim))
                return notify_fail("这不是活物！\n");

        if (victim == me) return notify_fail("何必多此一举？\n");

	if (!victim->query("hooker") )
		return notify_fail("她不是院子里的姑娘，先卖了她再说吧。\n");

	if (!me->query_temp("money_given"))
		return notify_fail("大爷您还没付钱呢！\n");

	if (!arg2) 
		return notify_fail("你要命令她做什么？\n");

	switch(random(3)) {
	case 0:
		msg = "$N嘿嘿淫笑了几声，嬉皮笑脸的对$n说：";
		break;
	case 1:
		msg = "$N哈哈大笑了几声，凶巴巴的对$n说：";
		break;
	case 2:
		msg = "$N呵呵笑了几声，轻轻的凑近$n说：";
		break;
	}

        message_vision(CYN+msg + arg2 + " " + arg3+"吧。\n"NOR, me, victim);
        
	if( !arg3 )
                EMOTE_D->do_emote(victim, arg2);
        else    EMOTE_D->do_emote(victim, arg2, arg3);

	me->delete_temp("money_given");
        return 1;
}

int valid_leave(object me, string dir)
{
    if (present("guinu",environment(me)) && 
                me->query("hooker")) {
       message_vision("龟奴一把揪住$N的裙边：你已经是丽春院的人了，不接客别想遛！\n",
                me);
       return notify_fail("\n");
    }
    else
        return :: valid_leave(me,dir);
}
 

