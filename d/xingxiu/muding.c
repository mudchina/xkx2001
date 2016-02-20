//Cracked by Roath
// 11/5/96. Ryu 
//1/20/98 Haowen
inherit F_UNIQUE;
inherit ITEM;
#include <ansi.h>
int do_open(string);
int do_suck(string);
int do_put(string);
void setup()
{}

void create()
{
        set_name(HIY "神木王鼎" NOR, ({"shenmu wangding", "wangding"}));
        set_weight(35000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "座");
		set("no_clean_up", 1);
                set("long", "一座雕琢精细的小木鼎，木质坚润似玉，木理之间隐隐泛出红丝。鼎侧\n"
			    "有五个铜钱大的圆孔，木鼎齐颈出有一道细缝，似乎上下分为两截。\n");
                set("value", 10000000);
		set("sucked", 500);
        }
//        ::create();
}
void init()
{
   add_action("do_put","put");
   add_action("do_suck", "suck");
   add_action("do_open", "open");
   add_action("do_hua","hua");	
}
int do_open(string arg)
{
        object  ob, me = this_player();
        if (!id(arg))
                return notify_fail("你要打开什么？\n");

               message_vision(HIG "$N以小指与无名指夹住鼎身，以大姆指与中指夹住上半截，向左转了几转，打开木鼎。\n"NOR, me);
	set_max_encumbrance(5000);
	set("opened", 1);
	set("long", "一座雕琢精细的小木鼎，木质坚润似玉，木理之间隐隐泛出红丝。鼎侧\n"
            "有五个铜钱大的圆孔，鼎盖被打开来放在一旁。\n");
        return 1;
}
int is_container() { return 1; }
int reject(object ob)
{
        if (ob && ob->query("name") == "香" 
	|| ob && ob->query("name") == "点燃的香") return 0;
        notify_fail("你不能把这样东西放进神木王鼎。\n");
        return 1;
}
int do_put(string arg)
{
	object ob, obj, me = this_player();
	string item, target;
        int amount;

	remove_call_out("open_up");
        if( !arg || sscanf(arg, "%s in %s", item, target) != 2 )
                return notify_fail("你要将什么东西放进哪里？\n");

        if( item == "all" ) {
                write("还是一样一样来吧。\n");
                return 1;
        }
	if(query("opened") < 1)
		return notify_fail("什么？\n");

        sscanf(item, "%d %s", amount, item);

        if( !objectp(obj = present(item, me)) )
                return notify_fail("你要给谁什么东西？\n");

	if( obj->query("no_drop") ) {
                write("这样东西不能离开你。\n");
                return 1;
        }
	if( obj->name()=="点燃的香") {
                message_vision( sprintf(HIY "$N将一%s%s放进%s。\n" NOR,
                        obj->query("unit"), obj->name(),
                        this_object()->name()),me );
		destruct(obj);
		me->add("combat_exp", 1+random(me->query_skill("poison")/3));

	if (NATURE_D->outdoor_room_event() == "event_dawn"
	&& interactive(me) && random(environment(this_object())->query("bing_can")) == 1){
	environment(this_object())->set("bing_can", 0);
	   remove_call_out("bing_can");
	   call_out("bing_can", random(30)+30, this_object());
	}

	else if ( interactive(me) && environment(this_object())->query("exits")) 
           call_out("open_up", random(20)+20, this_object());
	return 1;
	}
}

int do_suck(string arg)
{
        object me = this_player(), *ob;
	int i, tmp;

        if ( !arg || ( arg != "blood" ) )
                return notify_fail("什么？\n");

	if (query("suckable") < 1)
		return notify_fail("你要吸什么？\n");

	if( environment(me)->query("no_fight") )
                return notify_fail("你不能在这里做这件事。\n");

	if( me->is_fighting() )
                return notify_fail("你已经在战斗中了，学一点实战经验吧。\n");

	if ( me->query_skill("buddhism",1) || me->query_skill("taoism",1) 
	|| me->query_skill("lamaism", 1) || me->query_skill("mahayana", 1))
                return notify_fail("你练了秃驴牛鼻子们的心法，怎麽还能炼毒！\n");

	if ( me->query_skill("hunyuan-yiqi",1) || me->query_skill("lingji-zhuang", 1)
        || me->query_skill("huntian-qigong",1) || me->query_skill("xiaowuxiang", 1)
        || me->query_skill("taiji-shengong",1) || me->query_skill("zixia-gong",1)
	|| me->query_skill("dulong-dafa", 1) || me->query_skill("kurong-changong", 1))
                return notify_fail("你不先散了别派内功，怎能炼毒？！\n");
       

        if (me->query("neili") < 30 || me->query("jingli") < 30
        || me->query("qi") < 30 || me->query("jing") < 30)
                return notify_fail("你的真气不够练功所需。\n");

        me->add("jing", (-1)*random(15));
        me->add("qi", (-1)*random(15));
        me->add("jingli", (-1)*random(15));
        me->add("neili", (-1)*random(15));

	message_vision(RED "$N伸手将血液接住，盘膝运功。\n"NOR, me);
	add("sucked", -1);

	if ((int)me->query_skill("poison", 1) > 30 && (int)me->query_skill("poison", 1) < 51)
        me->set_temp("muding1", 1);
	if ((int)me->query_skill("poison", 1) > 50 && (int)me->query_skill("poison", 1) < 101
	&& me->query("body_poison") > (int)me->query_skill("poison",1)/10)
        me->set_temp("muding1", 1);

        switch( random(3) )
        {
            case 0:
                if ( (int)me->query_skill("chousui-zhang", 1) > 30)
                {
                        me->improve_skill("chousui-zhang", me->query_int());
                        write("你将血液吸入掌内，「抽髓掌」修为加深了。\n");
                        me->set_temp("muding_learned",1);
                        break;
                }
            case 1:
                if ( (int)me->query_skill("sanyin-zhua", 1) > 30)
                {
                        me->improve_skill("sanyin-zhua", me->query_int());
                        write("你的手指上隐隐罩上一层深紫色，「三阴蜈蚣爪」修为加深了。\n");
                        me->set_temp("muding_learned",1);
                        break;
                }
	    case 2:
		if (me->query_temp("muding1") || query("canblood") > 0 && me->query_skill("poison", 1) < 200)
                {
                        me->improve_skill("poison", me->query_int());
                        write("你手上的毒气似乎通入你的脑中，「基本毒技」修为加深了。\n");
			me->delete_temp("muding1");
                        me->set_temp("muding_learned",1);
			break;
                }
        }
        if ( !me->query_temp("muding_learned") )
        {
        write("你感觉一股寒气袭来，好象中毒了。\n");
        me->apply_condition("insect_poison", 15);
        }
	ob = all_inventory(environment(me));

        tmp = 0;
        for(i=0; i<sizeof(ob); i++)
        {
                if ((string)ob[i]->query("race") == "人类"  && ob[i] != me )
                {
                        message_vision(HIR "$N正用双手接住血液，盘膝运功，忽然瞥见周围有人，大叫一声！\n" NOR, me);
                        me->kill_ob(ob[i]);
                        ob[i]->fight_ob(me);
                        tmp = 1;
                }
        }
        if (tmp) return notify_fail("你想杀人灭口！\n");

	if(query("sucked") < 1){
        message_vision(RED "鼎中毒血渐渐滴干了。\n"NOR, me);
	set("sucked", 500);
	set("suckable", 0);
	set("canblood", 0);
	set("long", "一座雕琢精细的小木鼎，木质坚润似玉，木理之间隐隐泛出红丝。鼎侧\n"
            	    "有五个铜钱大的圆孔，木鼎齐颈出有一道细缝，似乎上下分为两截。\n");
	return 1;
	}
	return 1;
}
int open_up(object room)
{
	object ob, obj = this_object();
	switch( random(2) )
        {
        case 0:
	ob=new("/d/xingxiu/npc/centipede");
	break;

	case 1:
	ob=new("/d/xingxiu/npc/scorpion");
	break;

	case 2:
	ob=new("/d/xingxiu/npc/spider");
        break;
        }
	ob->move(obj);
	message_vision(RED "忽听得地上嗦嗦声响，却是一只$N爬了过来。那$N闻到鼎中散出的香气，径身游向木鼎，从鼎下的孔中钻进去，便不再出来。\n" NOR, ob, room);
	call_out("close_up", 20, obj, ob);
	return 1;
}
int bing_can(object room)
{
        object ob, obj = this_object(), me = this_player();
	message_vision(HIW "忽觉寒风袭体，只见东北角上一条火线烧了过来，一到近处，看得清楚，不是火线，\n"
			   "而是一条白蚕，所到之处，草木皆枯。这蚕虫纯白如玉，微戴青色，比寻常的蚕儿\n"
			   "大了一倍有余，便如一条蚯蚓，身子透明直如水晶。这虫儿闻到鼎中散出的香气，\n"
			   "径身从鼎下孔中爬进去，便不再出来。\n"NOR, room);
	ob=new("/d/xingxiu/npc/bingcan");
	ob->move(obj);
	if (!me->query("wormbite")){ 
	me->set_skill("poison", me->query_skill("poison", 1) + 10);
	me->set("wormbite", 1);
	}
	set("canblood", 1);
	call_out("close_up", 20, obj, ob);
	return 1;
}
int close_up(object room, object ob)
{
        message_vision(RED "过了一会儿，鼎里的虫子化成了一滩脓血。\n" NOR, room);
        remove_call_out("open_up");
	set("long", "一座雕琢精细的小木鼎，木质坚润似玉，木理之间隐隐泛出红丝。鼎侧\n"
    		    "有五个铜钱大的圆孔。鼎盖被打开来放在一旁，只见里面有一滩什么虫\n"
		    "子化成的血，一滴滴从孔中滴下来。\n");
	set("suckable", 1);
	destruct(ob);
        return 1;
}
int do_hua(string arg)
{
        object me = this_player(), *ob;
	int i, tmp;

        if ( !arg || ( arg != "blood" ) )
                return notify_fail("什么？\n");

	if (query("suckable") < 1)
		return notify_fail("你要化什么？\n");

	if( environment(me)->query("no_fight") )
                return notify_fail("你不能在这里做这件事。\n");

	if( me->is_fighting() )
                return notify_fail("你已经在战斗中了，学一点实战经验吧。\n");

	if ( me->query_skill("buddhism",1) || me->query_skill("taoism",1) 
	|| me->query_skill("lamaism", 1) || me->query_skill("mahayana", 1))
                return notify_fail("你练了秃驴牛鼻子们的心法，怎麽还能化毒！\n");

	if ( me->query_skill("hunyuan-yiqi",1) || me->query_skill("lingji-zhuang", 1)
        || me->query_skill("huntian-qigong",1) || me->query_skill("xiaowuxiang", 1)
        || me->query_skill("taiji-shengong",1) || me->query_skill("zixia-gong",1)
	|| me->query_skill("dulong-dafa", 1) || me->query_skill("kurong-changong", 1))
                return notify_fail("你不先散了别派内功，怎能化毒？！\n");
	
	if ( me->query_skill("huagong-dafa",1)*me->query_skill("huagong-dafa",1)*me->query_skill("huagong-dafa",1)/10 > me->query("combat_exp"))
		{
		 me->apply_condition("hua_du",0);
		 me->apply_condition("huadu_poison",0);
		 return notify_fail("你目前的经验无法支持更高的化功大法！\n");

		}
			       
	if ( me->query_skill("huagong-dafa",1) <120 )
		return notify_fail("你化功大法功力不够，不能通过化毒来提升！\n");
	

        if (me->query("neili") < 30 || me->query("jingli") < 30
        || me->query("qi") < 30 || me->query("jing") < 30)
                return notify_fail("你的真气不够练功所需。\n");

        me->add("jing", (-1)*random(15));
        me->add("qi", (-1)*random(15));
        me->add("jingli", (-1)*random(15));
        me->add("neili", (-1)*random(15));

	message_vision(RED "$N伸手将血液接住，盘膝运功将手中毒血化入筋脉,运内力一个周天。\n"NOR, me);
	add("sucked", -2);
	me->improve_skill("huagong-dafa", me->query_skill("poison",1)/10);
//	me->set_temp("muding_learned",1);
	me->apply_condition("huadu_poison",0);
	me->apply_condition("hua_du",237);

//	me->start_busy(1);	
	
/*	if ( !me->query_temp("muding_learned") )
        {
        write("你感觉一股寒气袭来，好象中毒了。\n");
        me->apply_condition("insect_poison", 15);
        }*/
	ob = all_inventory(environment(me));

        tmp = 0;
        for(i=0; i<sizeof(ob); i++)
        {
                if ((string)ob[i]->query("race") == "人类"  && ob[i] != me )
                {
                        message_vision(HIR "$N正用双手接住血液，盘膝运功，忽然瞥见周围有人，大叫一声！\n" NOR, me);
                        me->kill_ob(ob[i]);
                        ob[i]->fight_ob(me);
                        tmp = 1;
                }
        }
        if (tmp) return notify_fail("你想杀人灭口！\n");

	if(query("sucked") < 1){
        message_vision(RED "鼎中毒血渐渐滴干了。\n"NOR, me);
	tell_object(me,HIR"你体内毒性靠化功大法压制，七日之内必须再来化毒，否则毒力反攻，性命悠关！\n");

	set("sucked", 500);
	set("suckable", 0);
	set("canblood", 0);
	set("long", "一座雕琢精细的小木鼎，木质坚润似玉，木理之间隐隐泛出红丝。鼎侧\n"
            	    "有五个铜钱大的圆孔，木鼎齐颈出有一道细缝，似乎上下分为两截。\n");
	return 1;
	}
	return 1;
}
