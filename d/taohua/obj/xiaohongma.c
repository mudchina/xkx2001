//Cracked by Roath
// Modified by kane, 05/9/97

#include <ansi.h>
inherit NPC_TRAINEE;
//inherit NPC;

int return_home(object home);
void create()
{
	set_name(HIR"小红马"NOR, ({ "xiaohong ma", "ma", "horse" }) );
        set("race", "家畜");
        set("age", 10);
	set("long", 
"这是一匹神骏非凡的汗血宝马，传说是天马下凡，但实际上是大宛山中野马\n"
"与五色母马交配的后代。\n"
"汉武帝曾为此种良马大发兵卒，劳师远征西域。\n");

/*	set("msg_fail", "$n冲着$N怒嘶一声，竖立起来！");
        set("msg_succ", "$n摇着头打转，蹄子击打着地面，似乎打不定主意");
        set("msg_trained","$n低嘶一声，走到$N身边挨挨擦擦，显得十分高兴！");
 */
       set("attitude", "peaceful");
	set("wildness", 20000);
	set("value", 1000);
	set("ability", 10);

	set("ridable", 2);
	set("str", 200);
        set("con", 200);
	set("dex", 200);
        set("int", 20);
	set("max_qi", 2000);
	set("qi", 2000);
	set("max_jingli", 1200);
	set("combat_exp", 100000);
        set_weight(200000);
	//call_out("checking", 1, this_object() );

        setup();
}

void init()
{
        object *ob, lord, me = this_object();
        int my_jingli, my_mj, i, addjing;

        add_action("do_duhe","duhe");
        my_jingli  = (int)me->query("jingli");
        my_mj = (int)me->query("max_jingli");
        addjing = (my_mj - my_jingli)/2;
        if(my_jingli <= my_mj/3){
        say(me->name() +"大口大口地喘着粗气。\n");
        return;
        }
        if(my_jingli <=30 && my_jingli > 20){
        say(me->name() +"只在喘气，渐渐地快跑不动了！\n");
        return;
        }
        if(my_jingli <=10){
        ob = all_inventory(environment(me));
        for(i=0; i<sizeof(ob); i++){
        if (ob[i]->query("rided") == me);
        ob[i]->delete("rided");
        }
        me->delete("rider");
        me->unconcious();
        return;
        }
        if( environment(me)->query("resource/grass") &&
        me->query("food") < (me->max_food_capacity()*2/3)){
        me->set("food", (int)me->max_food_capacity());
        me->add("jingli", addjing);
        say(me->name() +"低下头在草地上吃起草来。\n");
        return;
        }
        if( objectp(lord = me->query_lord())
        && environment(lord) == environment(me) 
	&& (lord->query("qi") < lord->query("max_qi")/10)) {
	message_vision(HIW"小红马把$N叼起来往自己背上一扔，放蹄狂奔绝尘而去！！！\n"NOR,lord);
	lord->move("/d/taihu/matou");
	me->move("/d/taihu/matou");
	}
	add_action("do_tame", "train");
	add_action("do_tame", "tame");
	add_action("do_gen", "gen");
        add_action("do_gen", "come");
        add_action("do_ting", "ting");
        add_action("do_ting", "stay");
        add_action("do_fang", "fang");
        add_action("do_fang", "release");
}


int return_home(object home) {
	return 1;
}

int do_tame()
{
        return notify_fail("小红马已脱兽籍，不再受驭兽术控制了。\n");
}

int do_duhe()
{
	object me = this_object();
	object who = this_player();
	string dest;
	if (me->query("rider") != who) return 0;
	switch ((string)environment(who)->query("short")) {
	case "汉水南岸":
		dest = "/d/shaolin/hanshui2";
		break;
	case "汉水北岸":
                dest = "/d/shaolin/hanshui1";
                break;
        case "古长城":
                dest = "/d/xixia/xhbao";
                break;
        case "宣和堡":
                dest = "/d/xixia/oldwall";
                break;
	case "解脱坡":
                dest = "/d/emei/baoguoxi";
                break;
        case "报国寺西墙":
                dest = "/d/emei/jietuo";
                break;
	case "太湖":
		dest = "/d/taihu/matou";
		break;
	case "码头":
		dest = "/d/taihu/taihu";
		break;
	default:
		return notify_fail("这里没有小红马可以渡的河。\n");
	}
	message_vision("\n$N双腿一夹小红马，小红马长嘶一声，跃入水中将$N带到对岸。\n",who);
	message("vision", who->name() +"纵马过河去了。\n",
                environment(who), ({who}));
	me->move(dest);
	who->move(dest);
	message("vision", who->name() +"纵马从河对岸过来了。\n",
                environment(who), ({who}));
	return 1;
}	

