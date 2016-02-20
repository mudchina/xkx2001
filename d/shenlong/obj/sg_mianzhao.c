//Cracked by Roath
// sg_mianzhao.c 面罩
// by ALN Sep / 97
// by ALN 1 / 98

#include <armor.h>
inherit HEAD;

#define SGCANGKU "/d/shenlong/cangku"

void do_copy(object, object);
void do_flee(object);
int eff_fam(object);

#include "/d/shenlong/masters.h"
#include "/d/shenlong/safeplaces.h"

void create()
{
        set_name("面罩", ({ "mianzhao", "mask" }) );
        set_weight(2000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "个");
                set("long", 
                        "这是个神龙教特有的黑布头套，能把整个脑袋套起来，只露出两个眼睛。\n"
                        "你每次为神龙教办案后，务必在尸体上写下(sign)“逆神龙教者杀！”。\n");
                set("material", "cloth");
                set("armor_prop/armor", 1);
                set("value", 10);
                set("no_get", "这样东西不能离开那儿。\n");
                set("no_drop", "这样东西不能离开你。\n");
        }

        setup();
}

void init()
{
        add_action("do_wear", "wear");
        add_action("do_remove", "remove");
        add_action("do_sign", "sign");
        add_action("do_forcejoin", "forcejoin");
        add_action("do_search", "search");
        add_action("do_open", "open");
        add_action("do_job", "job");
        add_action("do_jobtime", "jobtime");
}

int do_wear(string arg)
{
        if (!arg || (arg != "mianzhao" && arg != "mask") ) return 0;

        this_player()->set_temp("apply/name",  ({"蒙面人"}));
        this_player()->set_temp("apply/short", ({"蒙面人(Mengmian ren)"}));
        this_player()->set_temp("apply/long",  ({"一个黑布蒙面，神秘兮兮的家伙。\n"}));

        return 0;
}

int do_remove(string arg)
{
        if (!arg || (arg != "mianzhao" && arg != "mask") ) return 0;

        this_player()->delete_temp("apply/name");
        this_player()->delete_temp("apply/short");
        this_player()->delete_temp("apply/long");

        return 0;
}

int do_sign(string arg)
{
        object obj;
        object me = this_player();
        string v_id, v_name;
        mapping pkjob;
        int mygain;

        if( !me->query("sg/spy") && !mapp(me->query("sgjob_join")) )
                return 0;

        if( !arg || arg != "corpse" || !(obj = present(arg, environment(me))) )
                return 0;

        if( obj->query("my_killer") != me->query("id") )
                return 0;

		  v_name = obj->query("victim_name");
		  if( obj->query("signed")
			|| (v_name != (string)me->query("sgjob/victim_name")
			&&  v_name != (string)me->query("sgjob_join/victim_name")) )
					 return 0;

		  if( v_id = me->query("sgjob_join/victim_id") ) {
					 me->delete("sgjob_join");
					 me->set("sg_ok/join", 1);
		  } else {
					 v_id = me->query("sgjob/victim_id");
					 me->delete("sgjob");
					 me->set("sg_ok/pk", 1);
					 mygain = (int)obj->query("combat_exp") / 1000;
					 me->add("sg/exp", 100 + mygain * (mygain/2000 + 1)/40);
					 if( mygain > 1000 ) mygain = 1000;
					 me->add("combat_exp", mygain);
		  }

		  obj->set("signed", 1);
		  log_file("test/ShenlongPker", sprintf("%s于%s时杀了%s(%s).\n", me->query("name"), ctime(time()), v_name, v_id));

		  me->set("sg_victim/" + time(), v_id);
		  tell_room(environment(me), "蒙面人在尸体旁写下“逆神龙教者杀！”几个大字。", ({me}));
		  tell_object(me, "你在尸体旁写下“逆神龙教者杀！”几个大字。\n");
		  return 1;
}

int do_forcejoin(string arg)
{
		  object *inv, target, me = this_player();
		  int fp, dp;
		  mixed busy;

		  if( !me->query("sg/spy") )
					 return notify_fail("你不是神龙教的人，来什么劲？\n");

		  if( me->query("sg_ok/forcejoin") )
					 return notify_fail("你先回去复命吧。\n");

		  if( environment(me)->query("no_fight") )
					 return notify_fail("这里不是强迫的地方。\n");

		  if ( busy = me->query_busy() ) {
					 if (intp(busy)) me->start_busy(busy+1);
					 return notify_fail("你现在正忙着！\n");
		  }

		  if( !arg || !(target = present(arg, environment(me))) )
					 return notify_fail("你要逼谁入神龙教？\n");

		  if( me->query("sgjob/forcejoin") != target->query("id") )
					 return notify_fail("你找错人了。\n");

		  if( target->query("sg/spy") || target->query("family/family_name") == "神龙教" )
					 return notify_fail(target->name() + "已经加入神龙了，不用再废心了。\n");

		  if( !living(target) )
					 return notify_fail("你现在再逼" + target->name() + "也没有用。\n");

		  if( me->query_temp("forcejoining") )
					 return notify_fail("你已经在逼迫人了。\n");

		  if( (int)me->query("jing") * 100 / (int)me->query("max_jing") < 40
			|| (int)me->query("jingli") * 100 / (int)me->query("max_jingli") < 40)
					 return notify_fail("你太累了，休息一会儿再劝吧。\n");

		  me->receive_damage("jing", 60);
		  me->receive_damage("jingli", 60);

		  message_vision("\n$N对$n大声喝道：" + RANK_D->query_rude(target) + "快加入神龙教，否则格杀无论！！！\n", me, target);

		  inv = all_inventory(environment(target));
		  for(int i = 0; i < sizeof(inv); i++) {
					 if( living(inv[i])
					 &&  inv[i] != me && inv[i] != target && !inv[i]->query("sg/spy")
					 && (string)inv[i]->query("family/family_name")
					 && (string)inv[i]->query("family/family_name") == (string)target->query("family/family_name") ) inv[i]->kill_ob(me);
		  }

		  fp = (int)me->query_skill("force") * 3 +
				 (int)me->query_skill("parry") * 2 +
				 (int)me->query_skill("dodge");

		  fp *= (int)me->query("sg/exp")  +
				  (int)me->query("combat_exp") / 1000 + 1;

		  dp = (int)target->query("jing") + (int)target->query("max_jing") +
				 (int)target->query("qi") + (int)target->query("max_qi") +
				 (int)target->query("jingli") * 2 +
				 (int)target->query("neili") * 3;
		  if ( dp < 1 ) dp = 1;
		  dp *= (int)target->query("combat_exp") / 1000 + 1;

		  me->set_temp("forcejoining",  target->query("id"));
		  call_out("complete_forcejoin", 8+random(10), me, target, fp, dp);
		  return 1;
}

private void complete_forcejoin(object me, object target, int fp, int dp)
{
		  object ob, *inv;
		  int t_shen, t_exp, bonus = 2, times, record;

		if( !present(target, environment(me)) )
			return ;

		  if( !objectp(me) )  return;

		  me->delete_temp("forcejoining");
		  target->add_temp("forcetimes", 1);

		  if( !objectp(target) ) return;

		  if( environment(target) != environment(me) ) return;

		  if( !living(target) ) {
					 tell_object(me, "你现在再逼也没有用。\n");
					 return;
		  }

		  t_shen = (int)target->query("shen");
		  while ( t_shen > 10 ) {
					 bonus += 1;
					 t_shen = t_shen/16;
		  }

		  if( member_array(target->query("id"), masters) != -1 )
					 bonus *=30;

		  dp *= bonus;
		  dp *= 4 * eff_fam(target);

		  if( target->query_condition("embedded") )
					 dp /= 2;

		  if( (int)target->query_condition("snake_poison") > 0 )
					 dp /= 2;

		  if( (int)target->query_condition("insect_poison") > 0 )
					 dp /= 2;

		  if( (int)target->query_condition("xx_poison") > 0 )
					 dp /= 2;

		  if( (int)target->query_temp("hgmz") > 0 )
					 dp /= 4;

		  if( (int)target->query_condition("hyz_damage") > 0 )
					 dp /= 2;

		  if( (int)target->query_condition("hsf_poison") > 0 )
					 dp /= 2;

		  if( dp < 1 ) dp = 1;

		  if( random(fp+dp)  > dp ) {
					 message_vision("$N别无它法，只得答应$n加入神龙教。\n", target, me);

					 if( member_array(target->query("id"), masters) != -1 )
								bonus += 100;

					 bonus += (int)me->query("sg/exp") * 2000 / (int)me->query("combat_exp");

					 bonus *= eff_fam(target);
					 if(bonus>300)bonus = 300;

					 record = bonus/3 + random(bonus/3);
					 me->add("combat_exp", record);
					 me->add("sg/exp", 1);
					 me->add("shen", -(int)target->query("combat_exp")/100);

					 log_file("test/ForceJoin", sprintf("%s于%s时逼%s入神龙教获得%s经验点\n", me->query("name"), ctime(time()), target->query("name"), chinese_number(record)));

					 bonus /= 4;
					 me->add("potential", bonus/3 + random(bonus/3));
					 if( me->query("potential") > me->query("max_potential") )
								me->set("potential", me->query("max_potential"));

					 me->delete("sgjob");
					 me->set("sg_ok/forcejoin", 1);

					 inv = all_inventory(target);
					 for(int i = 0; i < sizeof(inv); i++)
								if( inv[i]->is_unique()
								||  inv[i]->query("weapon_prop/damage") > 100
								||  inv[i]->query("armor_prop/armor") > 100 ) {
										  inv[i]->move(me);
										  message_vision("$N将" + inv[i]->name() + "双手奉上递给$n。\n", target, me);
								}

					 target->set("sg/spy", 1);
					 target->delete_temp("forcetimes");
					 target->set("attitude", "heroism");
					 target->set("shen_type", -1);
					 target->remove_killer(me);
					 target->start_busy(1);
					 me->remove_killer(target);
					 me->start_busy(1);
		  } else {
			  if( random((int)target->query_temp("forcetimes")) > 2 ) {
				 COMMAND_DIR"std/halt"->main(target);
							  if( !random(3) )
										do_flee(target);
                       else   target->random_move();
		       if( !mapp(environment(target)->query("exits")) )
			      target->return_home(target->query("startroom"));
		} else {
                       target->kill_ob(me);
                       message_vision("\n$N不屑地撇撇嘴：" + RANK_D->query_rude(me) + "，我先杀了你这狂徒！！！\n", target);
                }
                me->start_busy(1+random(3));
        }
}

int eff_fam(object ob)
{
        switch((string)ob->query("family/family_name")) {
        case "武当派"   :  return 10; break;
	case "少林派"   :  return 10; break;
        case "大理段家" :  return 10; break;
	case "峨眉派"   :  return  9; break;
	case "华山派"   :  return  8; break;
        case "桃花岛"   :  return  7; break;
        case "雪山派"   :  return  6; break;
        case "丐帮"     :  return  5; break;
		  case "血刀门"   :  return  4; break;
	case "白陀山"   :  return  3; break;
	case "星宿派"   :  return  2; break;
        default:
                if( ob->query("attitude") == "aggressive" || ob->query("attitude") == "heroism" )
                         return 6;
					 else     return 3;
                break;
        }

        return  5;
}

void do_flee(object ob)
{
        message("vision",
                ob->name() + "一转眼便消失了。\n",
                environment(ob), ({ob}));

        if( mapp(ob->query("family"))
        &&   member_array((string)ob->query("id"), masters) == -1 ) {
                switch((string)ob->query("family/family_name")) {
                case "武当派"   :  
                        ob->move("/d/wudang/xiaoyuan");  break;
                case "少林派"   :
                        ob->move("/d/shaolin/fumoquan"); break;
                case "大理段家" :
                        ob->move("/d/dali/yideng9");     break;
                case "峨嵋派"   : 
								ob->move("/d/emei/hz_back");     break;
                case "华山派"   :
                        ob->move("/d/huashan/buwei1");   break;
                case "桃花岛"   :
                        ob->move("/d/taohua/hyjuchu");   break;
                case "雪山派"   :
								ob->move("/d/xueshan/angqian2"); break;
                case "丐帮"     : 
                        ob->move("/d/gaibang/gbxiaowu"); break;
                case "血刀门"   :
                        ob->move("/d/xueshan/cave2");    break;
                case "白陀山"   :
                        ob->move("/d/xingxiu/btroom");   break;
                case "星宿派"   : 
                        ob->move("/d/xingxiu/riyuedong");break;
                default  : 
                ob->move(safeplaces[random(sizeof(safeplaces))]); break;
                }
        } else  ob->move(safeplaces[random(sizeof(safeplaces))]);

        message("vision",
                ob->name() + "走了过来。\n",
                environment(ob), ({ob}));
}      

private int is_spy(object ob)
{
        if( !ob->query("sg/spy") ) return 0;
 
		  return 1;
}

int do_search(string arg)
{
        string str, *option;
		  object *list;
        int i, j, ppl_cnt, total;

        if( !arg || !(arg == "shenlong" || arg == "神龙教")
        ||  this_player()->query("sg/exp") < 1000 )
                return 0;

        if( !wizardp(this_player()) && (int)this_player()->query("jing") < 30 )
                return notify_fail("你的精神太差了，没有办法得知本教组织的详细资料。\n");

        this_player()->receive_damage("jing", 30);

        seteuid(getuid());

        str = "◎ " + MUD_NAME + "\n";
        str += "─────────────────────────────────────\n";

        list = filter_array(users(), "is_spy", this_object());   
        total = sizeof(list);

        list = sort_array(list, "sort_user", this_object());
        j = sizeof(list);
        while( j-- ) {
					 // Skip those users in login limbo.
                if( !environment(list[j]) ) continue;
                if( this_player() && !this_player()->visible(list[j]) ) continue;
                str = sprintf("%s%12s %s\n", str, RANK_D->query_rank(list[j]),
                                list[j]->short(1) );
        }

        str += "─────────────────────────────────────\n";
        str = sprintf("%s共有 %d 位神龙教成员连线中。\n", str, total);

        this_player()->start_more(str);
        return 1;
}

int sort_user(object ob1, object ob2)
{
        return (int)ob2->query("sg/exp") - (int)ob1->query("sg/exp");
}

int do_job()
{
        string job;


        if( this_player()->query("sg_ok/pk") || this_player()->query("sg_ok/join") ) {
                write("你最近完成了一件追杀任务。\n");
                return 1;
        }

		  if( this_player()->query("sg_ok/stuff") ) {
                write("你最近完成了一件找东西的任务。\n");
                return 1;
        }

        if( this_player()->query("sg_ok/forcejoin") ) {
					 write("你最近完成了一件逼迫入教的的任务。\n");
                return 1;
        }

        if( !mapp(this_player()->query("sgjob")) && !mapp(this_player()->query("sgjob_join")) ) {
                write("你现在没有教务缠身。\n");
                return 1;
        }

        if( (job = this_player()->query("sgjob/forcejoin")) ) {
                write("你当前的任务是逼迫" + job + "入教。\n");
                return 1;
        }

        if( (job = this_player()->query("sgjob/victim_name")) ) {
                write("你当前的任务是追杀" + job + "(" + this_player()->query("sgjob/victim_id") + ")。\n");
                return 1;
        }

        if( (job = this_player()->query("sgjob/sgjob")) ) {
                write("你当前的任务是找" + job + "。\n");
                return 1;
        }

        write("你现在没有教务缠身。\n");
        return 1;
}

int do_jobtime()
{
        int start_time, time, s, m;

        if( mapp(this_player()->query("sg_ok")) )
        return notify_fail("你已经完成任务了，无需在乎时间。\n");

        if( !(start_time = this_player()->query("sgjob/assigntime")) )
        if( !(start_time = this_player()->query("sgjob_join/assigntime")) )
        return notify_fail("你现在没有教务缠身。\n");

        time = time() - start_time;
        if( time > 1800 ) {
                write("已经过了半小时，可以去问新任务了。\n");
                return 1;
        }

        s = time % 60;
        m = time / 60;

        write("加油！加油！加油！已经过了" + chinese_number(m) + "分" + chinese_number(s) + "秒\n");
        return 1;
}
                

