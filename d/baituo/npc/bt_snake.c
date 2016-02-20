//Cracked by Roath
// baituo snake 白驼山蛇谷的蛇
// 注意：千万不可用在蛇谷以外的房间！
// by maco 
#include <ansi.h>

inherit NPC_TRAINEE;
void set_kind(int);

void create()
{
	set("race", "蛇类");
	set("age", 4);
	set("attitude", "peaceful");

	set("msg_fail", "$n冲$N嘶地一吐舌头");
	set("msg_succ", "$n嘶嘶做响，蛇头随着$N的手动了起来");
	set("msg_trained","$n悄无声息地游到$N的脚下不动了");
	set("wildness", 9);

	set("str", 26);
	set("cor", 30);

	set("combat_exp", 1000);

	set_temp("apply/attack", 15);
	set_temp("apply/damage", 6);
	set_temp("apply/armor", 2);
	set_kind(random(8));
	setup();
}

void set_kind(int poison)
{
	int s;

	if(poison > 7) poison = 7;

	s = random(40);

	switch( poison )
	{
	case 0:
		set_name("毒蛇", ({ "snake", "she" }) );
		set("long", "一只有着三角形脑袋的蛇，尾巴沙沙做响。\n");
		set("combat_exp", 1000);
		break;
	case 1:
		set_name("黑蛇", ({ "hei she", "snake" ,"she" }) );
		set("long", "这条黑蛇身子黑得发亮，身上白点也是闪闪发光，张开大口，露出四根獠牙。\n");
		break;
	case 2:
		set_name("竹叶青", ({ "zhuye qing", "snake" }) );
		set("long", "一只身体碧绿的蛇，显得特别细小。\n");
		break;
	case 3:
		set_name("百步蛇", ({ "baibu she", "she", "snake" }) );
		set("long", "一条青色长蛇，黄鳞覆体。据说被百步蛇咬了，走出一百步必死无疑。\n");
		break;
	case 4:
		set_name("青花蛇", ({ "qinghua she", "she", "snake" }) );
		set("long", "一条混身青黄相间的毒蛇，斑条鲜明，蛇头奇扁，作三角之形，显具剧毒。\n");
		break;
	case 5:
		set_name("蝮蛇", ({ "fu she", "she", "snake" }) );
		set("long", "一条细颈青身的蝮蛇。\n");
		break;
	case 6:
		set_name("赤练蛇", ({ "chilian she", "chilian", "she", "snake" }) );
		set("long", "一条尺许长的赤练蛇，青红斑斓，甚是可怖。\n");
		break;
	case 7:
		set_name("金线蛇", ({ "jinxian she", "she", "snake" }) );
		set("long", "一条方头小蛇，全身绿鳞覆体，一条金线由蛇腹而下。\n");
		break;
	}
	set_weight(poison*600 + 9000);
	set("str", 30 + poison );
	set("con", 30 + poison );
	set("int", 20);
	set("dex", 30 + poison );
	
	set("max_jing", 800 + poison*200);
	set("max_qi", 800 + poison*200);
	set("eff_jing", 800 + poison*200);
	set("eff_qi", 800 + poison*200);
	set("jing", 800 + poison*200);
	set("qi", 800 + poison*200);

	set("combat_exp", (poison + 1)*60000);

	set_temp("apply/attack", 30 + s + poison*10 );
	set_temp("apply/damage", 30 + s + poison*10 );
	set_temp("apply/armor", 30 + s + poison*10 );

	set("snake_poison", 60 + poison*40 +random(61));
	set("bt_snake", 1);
}

void init()
{
	object ob;
	::init();
	add_action("convert","bian");
	if (interactive(ob = this_player()) &&
	    ob->query("family/family_name") != "白驼山" &&
		random(ob->query_kar() + ob->query_per()) < 30) {
			remove_call_out("kill_ob");
			call_out("kill_ob", 1, ob); 
		return;
	}
	if ( query("frightened") && !query_lord() ) {
			remove_call_out("kill_ob");
			call_out("kill_ob", 1, ob); 
		return;
	}
}

void die()
{
	object ob;
	message_vision("$N全身扭曲，翻腾挥舞，全身软软地散了开来。\n", this_object());
	ob = new(DRUG_D("shedan"));
	ob->move(environment(this_object()));
	destruct(this_object());
}

mixed hit_ob(object me, object victim, int damage_bonus, int factor)
{
	victim->apply_condition("snake_poison", 10 + me->query("snake_poison")/10 +
		victim->query_condition("snake_poison"));
}

int convert(string arg)
{
	object me = this_player();
	object ob;

	if (arg!="snake" && arg!="she") return 0;
	if (me->query("family/family_name") != "白驼山") 
		return notify_fail("你不能化蛇为杖。\n");

	if (this_object()->query("name") != "毒蛇") 
		return notify_fail(this_object()->name()+"不适合化为蛇杖。\n");

	if (random(me->query_skill("training",1)) <20) {
		kill_ob(me);
		return 1;
	}
	message_vision("$N左手按住毒蛇的头，右手轻抚其七寸，口中念念有词，片刻间将蛇化为一根蛇杖。\n",
		me,);
		ob = new("/d/xingxiu/obj/shezhang");
	ob->move(environment(this_object()));
	destruct(this_object());
	return 1;
}
