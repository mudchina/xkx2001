//Cracked by Roath
// /d/huanghe/obj/bangling.c
// by aln 2/98

#define BANGZHU   "/d/huanghe/npc/bangzhu"

#include <ansi.h>
#include <localtime.h>

inherit ITEM;

#include "/d/REGIONS.h"
#include "/d/huanghe/doc/info_store.h"

void create()
{
        set_name("帮令", ({ "bang ling", "ling" }) );
        set_weight(10);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "块");
                set("long", "这是一块帮会中常用的帮令。\n");
                set("value", 0);
                set("material", "wood");
                set("no_drop", "这样东西不能离开你。\n");
                set("no_get", "这样东西不能离开那儿。\n");
        }
        setup();
}

void init()
{
        add_action("do_collect", "collect");
        add_action("do_sign", "sign");
        add_action("do_find", "find");
        add_action("do_bargain", "bargain");
}

int do_find(string arg)
{
        object *obj, room;
        string file, region, fam, result;
        int i;
        mapping job;

        if( (string)query("owner") != this_player()->query("id") ) {
               write("你连自己的帮令都管不好，还是离开帮会吧。\n");
               return 1;
        }

        if( !stringp(fam = this_player()->query_temp("bangs/fam")) ) {
               write("你没有加入帮会。\n");
               return 1;
        }

        if( arg == "score" ) {
                write("你挣了" + chinese_number((int)query("score")) + "点功劳点。\n");
                return 1;
        }

        if( arg != "job" ) {
                write("什么？\n");
                return 1;
        }

        if( !mapp(job = query("job")) ) {
                write("你现在没有被指派帮务。\n");
                return 1;
        }

        result = "你当前的帮务是";
        switch(job["type"]) {
        case "寻":
                result += "找" + job["name"]; 
                break;
        case "杀":
                result += "杀" + job["area"] + "的" + job["name"]; 
                break;
        case "摊费":
                result += "要" + job["name"] + "的摊费";
                break;
        case "截镖":
                result += "截" + job["name"] + "的镖";
                break;
        case "示威":
                result += "向" + job["name"] + "示威";
                break;
        case "送礼":
                result += "送礼给" + job["area"] + "的" + job["title"];
                break;
        case "护驾":
	        result += "护送帮主至" + job["dest"];
                break;
        case "买卖":
                result += "将" + job["name"] + "卖个好价钱";
                break;
        case "伙计":
                result += "在天宝阁做伙计";
                break;
	default:
                write("你现在没有被指派帮务。\n");
                return 1;
        }

        write(result + "。\n");
        return 1;     
}

int do_collect(string arg)
{
        object me = this_player();
        object victim, obj;
        int ap, dp, myexp, yourexp, bonus, record;
        mapping job;

        if( time() < (int)query("collect_time") + random(10) )
                return notify_fail("你刚向此人要过钱。\n");

        if( (int)me->query("jingli") < 50 || (int)me->query("jing") < 50 )
                return notify_fail("你太累了，先歇会儿。\n");

        if( (string)query("owner") != me->query("id") )
                return notify_fail("帮令岂能瞎用？\n");

        if( (string)query("fam") != me->query_temp("bangs/fam") )
                return notify_fail("你已经不是此帮的人了。\n");

        if( !mapp(job = query("job")) )
                return notify_fail("你现在没有帮务缠身。\n");

        if( job["type"] != "摊费" )
                return notify_fail("你当前的帮务不是收摊费。\n");

        if( base_name(environment(me)) != job["place"] )
                return notify_fail("你还没到" + job["name"] + "收什么摊费？\n");

        if( !arg )
                return notify_fail("你要向谁收括钱？\n");

        if( !(victim = present(arg, environment(me))) )
                return notify_fail("这儿没有这个人。\n");

        if( victim->name() != job["boss"] )
                return notify_fail("你找错人了。\n");

        if( !living(victim) )
                return notify_fail("你还是等此人醒来后再收括钱吧。\n");

        if( victim->is_busy() || victim->is_fighting() )
                return notify_fail("此人正忙着。\n");

        message_vision(HIR"\n$N向$n大声吆喝道：我是" + (string)query("fam") + "来收摊费的，识时务的赶快给钱！！！\n"NOR, me, victim);

        me->receive_damage("jingli", 20 + random(10));
        me->receive_damage("jing", 20 + random(10));

        set("collect_time", time());

        myexp = (int)me->query("combat_exp");
        ap = (int)query("combat_exp") + myexp * 10;

        yourexp = (int)victim->query("combat_exp");
        if( yourexp < 30000 ) yourexp = 30000;
        dp = yourexp * 30;
 
        if( random(ap + dp) < dp ) {
                message_vision("$N大怒道：什么" + (string)query("fam") + "，还不快滚！！！\n", victim);
                return 1;
        }

        message_vision("$N对$n说道：" + RANK_D->query_respect(me) + "辛苦了，这一点摊费是小的该付的。\n", victim, me);
        message_vision("$N接着说道：" + RANK_D->query_respect(me) + "请放心，我马上派人将钱送到贵帮！！！\n", victim);

        bonus = 1 + yourexp * 2 / (myexp + 10000);
        record = bonus + random(bonus);
        me->add("combat_exp", record);
        log_file("test/BangJob", sprintf("%s于%s时因收摊费得%s经验点\n", me->query("name"), ctime(time()), chinese_number(record)));

        bonus /= 4;
        me->add("shen", -bonus);
        add("score", bonus);
        return 1;
}

int do_sign(string arg)
{
        object obj, room;
        object me = this_player();
        int bonus, record;
        mapping job;

        if( query("owner") != me->query("id") )
                return 0;

        if( (string)query("fam") != (string)me->query_temp("bangs/fam") )
                return 0;

        if( !arg || arg != "corpse" || !(obj = present(arg, environment(me))) )
                return 0;

        if( !mapp(job = query("job")) ) {
                tell_object(me, "你现在没有帮务。\n");
                return 1;
        }

        if( obj->query("my_killer") != me->query("id")
        ||  obj->query("signed")
        ||  (string)obj->query("victim_name") != job["name"] )
                return 0;

        if( !( room = find_object("/d/taishan/fengchan")) )
                room = load_object("/d/taishan/fengchan");

        if( me->query("id") == room->query("winner") ) {
                tell_object(me, "怕死，不中用的东西！\n");
                return 1;
        }

        obj->set("signed", 1);
        bonus = job["bonus"] * job["max"] / (1000 + me->query("combat_exp"));
        record = bonus + random(bonus);
        me->add("combat_exp", record);
        log_file("test/BangJob", sprintf("%s于%s时杀%s得%s经验点\n", me->query("name"), ctime(time()), job["name"], chinese_number(record)));

        bonus = job["score"];
        me->add("shen", -bonus);
        add("score", bonus);

        message_vision("$N在尸体旁写下“与" + (string)query("fam") + "为敌者杀！”几个大字。\n", me);
        delete("job");
        return 1;
}

int do_bargain(string arg)
{
        object target, obj, me = this_player();
        mapping job;
        int bonus, exp;

        if( (string)query("owner") != me->query("id") )
                return notify_fail("帮令岂能瞎用？\n");

        if( (string)query("fam") != me->query_temp("bangs/fam") )
                return notify_fail("你已经不是此帮的人了。\n");

        if( !mapp(job = query("job")) )
                return notify_fail("你现在没有帮务缠身。\n");

        if( !arg )
                return notify_fail("你要和谁讨价还价？\n");

        if( !(target = present(arg, environment(me))) )
                return notify_fail("这儿没有这个人。\n");

        if( !living(target) )
                return notify_fail("你还是等此人醒来后再说吧\n");

        if( userp(target) )
                return notify_fail("玩家不会出好价钱的。\n");

        if( target->is_busy() || target->is_fighting() )
                return notify_fail(target->name() + "正忙着。\n");

        if( (exp = (int)target->query("combat_exp")) < 10000 ) {
                message_vision("$N摆了摆手说道：我买不起，你卖给别人吧。\n", target);
                return 1;
        }

        if( !(obj = present(job["good"], me)) )
                return notify_fail("你把" + job["name"] + "弄丢了。\n");

        if( time() < (int)target->query("trader/time") + 600 ) {
                message_vision("$N 摆了摆手说道：我刚买了一" + obj->query("unit") + obj->name() + "。\n", target);
                return 1;
        }

        if( (bonus = (int)job["prices"][explode(base_name(environment(target)), "/")[1]]) < 5 ) {
                message_vision("$N摆了摆手说道：这东西现在在此地一点也不值钱，你自己用吧。\n", target);
                return 1;
        }

        target->set("trader/time", time());

        bonus *= (1 + (int)target->query("combat_exp") / 100000);

        message_vision("$N想了想说道：好吧，" + chinese_number(bonus) + "两银子，再贵我不买了。\n", target);
        message_vision("$N点了点头，将" + obj->query("unit") + obj->name() + "交给$n。\n", me, target);
        obj->move("/d/shenlong/cangku");
        message_vision("$N说道：下次贵帮来人时我再付款。\n", target);
        message_vision("$N说道：没关系，下次还有更好的货。\n", me);

        bonus /= 20;
        me->add("combat_exp", bonus);
        log_file("test/BangJob", sprintf("%s于%s时因卖%s得%s经验点\n", me->query("name"), ctime(time()), obj->name(), chinese_number(bonus)));
        add("score", bonus/4);
        delete("job");
        return 1;
}
