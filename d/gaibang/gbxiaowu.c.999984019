//Cracked by Roath
// Room: gbdixiaoshi.c
// by aji

#include <ansi.h>

inherit ROOM;

void create()
{
        set("short", "林间小屋");
        set("long", @LONG
你走进了一间小屋。四周墙壁都由青竹篾编成，窗外是一望无际的竹林。屋
里的桌椅、床铺均为竹制。但一阵扑鼻而来的狗肉香味，却显得与这清雅的气纷
格格不入。
LONG );

	set("exits", ([ /* sizeof() == 2 */
		"west" : __DIR__"zhulin2",
		"northwest" : __DIR__"zhulin3" ]));

	set("objects", ([
		CLASS_D("gaibang") + "/hong" : 1,
	]));

        set("valid_startroom", 1);
        set("no_clean_up", 0);
	set("cost", 0);
        setup();

//	"/clone/board/gaibang_r"->foo();
}
/*
void init()
{
	mapping fam;
	object me = this_player();

	if( !mapp(fam = me->query("family")) ) return;

	if( fam["family_name"] == "丐帮" && me->query_skill("staff", 1) > 5 && me->query_skill("stick", 1) < 5 ) {
		tell_object(me, HIY "\n\n" +
				"你是个丐帮弟子，又学了基本杖法，但是今後丐帮将使用基本棒法（stick）\n" +
				"取代基本杖法（staff），如果你愿意的话，系统将自动将你的杖法改为棒法，\n" + 
				"请键入“yes”进行改变。\n\n" NOR);
	
		add_action("do_yes", "yes");
	}

	if( fam["family_name"] == "丐帮" && me->query_skill("unarmed", 1) > 0 && me->query_skill("strike", 1) <= 0 ) {
		tell_object(me, HIY "\n\n" +
				"你是个丐帮弟子，又学了基本拳脚，但是今後丐帮将使用基本掌法（strike）取代基本拳脚\n" + 
				"（unarmed），以符合降龙十八掌的名称。 如果你愿意，系统将自动将你的基本拳脚改为掌法，\n" + 
				"请键入“ok”进行改变。\n\n" NOR);
	
		add_action("do_ok", "ok");
	}

        add_action("do_kill","kill");

}

int do_yes()
{
	mapping learned; 

	object me = this_player();
	learned = me->query_learned();

	me->set_skill("stick", me->query_skill("staff", 1));
	me->improve_skill("stick", learned["staff"]);
	if( me->query_skill("dagou-bang", 1) > 1)  me->map_skill("stick", "dagou-bang");
	me->map_skill("staff");
	me->delete_skill("staff");

	tell_object(me, HIY "\n技能更新完毕！ 有何问题，请向巫师报告。\n\n" NOR);	

	return 1;
}

int do_ok()
{
	mapping learned; 

	object me = this_player();
	learned = me->query_learned();

	me->set_skill("strike", me->query_skill("unarmed", 1));
	me->improve_skill("strike", learned["unarmed"]);
	if( me->query_skill("xianglong-zhang", 1) > 1)  { 
		me->map_skill("strike", "xianglong-zhang");
		me->prepare_skill("strike", "xianglong-zhang");
	}
	me->map_skill("unarmed");
	me->delete_skill("unarmed");

	tell_object(me, HIY "\n技能更新完毕！ 今後若想使用降龙十八掌，请于 enable strike xianglong-zhang 后，\n" + 
			"再键入 prepare xianglong-zhang 完成技能准备。 以後可键入 prepare none 取消技能准备等\n" + 
			"现在系统已自动帮你完成上述任务，今後有何问题，请向巫师报告。\n\n" NOR);	

	return 1;
}
*/
int do_kill(string arg)
{
        object ob, ob1, me = this_player();

        if ( !arg || arg == "" ) return 0;

        if ( !ob=present(arg, environment(me)) ) return 0;

//     	message_vision("$n对著$N喝道：「"+RANK_D->query_rude(ob)+"！今日不是你死就是我活！:)」\n", ob, me);

        if ( ob->query("family/family_name") == "丐帮" 
	&& me->query("family/family_name") != "丐帮"
        && ob1=present("hong qigong", environment(me)) ) {
                	message_vision("$N一声冷笑：大胆狂徒！你也太小看我老叫化了吧！\n", ob1);
                	ob1->kill_ob(me);
	}

       	return 0;
}
