//Cracked by Roath
// shentong_paper.c
//Can't use it in no_fight rooms By Sure 
//5.2001

#include <ansi.h>
inherit ITEM;

string long_desc();

mapping default_dirs = ([
                  "north":        "北",
                  "south":        "南",
                  "east":         "东",
                  "west":         "西",
                  "northup":      "北边",
                  "southup":      "南边",
                  "eastup":       "东边",
                  "westup":       "西边",
                  "northdown":    "北边",
                  "southdown":    "南边",
                  "eastdown":     "东边",
                  "westdown":     "西边",
                  "northeast":    "东北",
                  "northwest":    "西北",
                  "southeast":    "东南",
                  "southwest":    "西南",
                  "up":           "上",
                  "down":         "下",
                  "out":          "外",
                  "enter":        "里",
]);

void create()
{
                  set_name("纯阳神通功秘诀", ({"shentong mijue", "mijue"}));
                  set_weight(100);
                  if( clonep() )
                                         set_default_object(__FILE__);
                  else {
                                         set("unit", "卷");
                                         set("long", (: long_desc :));
                                         set("value", 10000000);
                                         set("material", "paper");
                                         set("no_drop","这样东西不能离开你。\n");
                  }
}

string long_desc()
{
        string desc;

        if( random(2) )
        {
          desc ="

纯阳神通功秘诀

纯阳神通功系本山人晚年悟得。吾青壮年献身于抗金大业，大小百余战，
杀金贼无数。无奈朝廷奸贼当道，忠义之士俱被杀戳，有功之臣惨遭灭门。
余虽有心回天，奈我朝气数已尽，非人力所能为。为免我华夏遭灭门之厄，
余慨叹之余，网罗天下同道之士，修活死人墓，集数万金，以为日后东山
再起之备。余手创全真教，广传门徒，授防身之术，盼我教众徒能成为我
大宋之中流砥拄。我大宋中兴，全系于诸人。余闭关多年，并与诤友林氏
朝英切磋多次，兼参读九阴真经，终大彻大悟，得成大道。余戎马生涯，
行走江湖多年，身受巨创多次，又与西毒欧阳锋大战数次，虽破其哈蟆功，
余亦深受剧毒，元气大伤，恐不日就要归天。惜众徒皆资质一般，无人能
授予奇功。师弟伯通虽资质奇佳，但已非纯阳之身，且不通事理。余去之
后，恐重阳宫不日就要遭厄运，此也是天数。余特留此秘诀，藏于极密之
处，日后有缘者自能获得此诀。尔既能得此诀，当是极为有缘。中兴华夏，
全赖于汝，望汝不负吾望。汝若能习成此功，可进列为吾徒，日后须行侠
仗义，替天行道。

终南山王重阳
\n";
        }
        else desc="
练功秘诀：须于无人僻静之处，持此秘诀，静读潜心修练(xiulian)。
已婚者须当心走火入魔。此功光练无用，须常常和高手切磋(qiecuo)。\n";


return desc;
}


void init()
{
        add_action("do_xiulian","xiulian");
        add_action("do_qiecuo","qiecuo");
}

int do_xiulian(string arg)
{
        object me = this_player();
        object here=environment(me);
		object where;

		seteuid(getuid());
        where = environment(me);

        if(me->is_busy())return notify_fail("你正忙着呢。\n");
		if (where->query("no_fight"))
                return notify_fail("你只觉浑身懒懒地，无法凝神聚气。\n");
        if(me->query("neili")<1000)return notify_fail("你内力不足，无法修练。\n");
        if(me->query("jingli")<1000)return notify_fail("你精力不足，无法修练。\n");
        if(me->query_skill("xiantian-gong",1)<300)return notify_fail("你先天功基础太差，无法修练。\n");
        if(me->query_skill("force",1)<300)return notify_fail("你内功基础太差，无法修练。\n");
        if(me->query_skill("taoism",1)<300)return notify_fail("你道学基础太差，无法修练。\n");
        if(me->query("shen") < 3500000)return notify_fail("你行侠仗义之事做得不够，正气不足，无法修练。\n");

        if( me->query("quanzhen/shentong_times") > 20 ) return notify_fail("你修练已久，该去实战应用一下了。\n");

        message_vision(
HIG"$N按照纯阳神通功秘诀，运起玄门先天功，聚天地之精气，过紫宫，入泥丸，
透十二重楼，开玄关，通任督，劲随意到，劲到力至。\n"NOR,me);

        me->start_busy( 1+random(5) );

        call_out("done",1+random(10) );

        return 1;
}

void done()
{
        object me = this_player();
        object here=environment(me);
        int marries= me->query("married_times");
	object where;


        if( random(marries) > 0 )
        {
                message_vision(
HIY"$N只觉元气不足，想要打通的督脉只差一丝丝，可是偏偏就是过不去。累得出了一身大汗。\n"NOR,me);
                me->add("neili",-me->query("neili")/2);
                me->add("jingli",-1000);
                me->improve_skill("force",100+random(400));
        }
        else
        {
                if( random(me->query("neili"))>8000 )
                {
                        message_vision(
HIG"$N只觉得真气直通任督，越运真气越是充沛，灵台一片清凉光明，偏体舒畅无比。\n"NOR,me);
                        me->improve_skill("force",200+random(400));
                        me->add("neili",-1000-random(2000));
                        me->add("shentong",random(2));
                }
                else if( random(me->query("neili"))>3000 )
                {
                        message_vision(
HIG"$N只觉得真气通过任督，真气充沛，偏体舒畅无比。\n"NOR,me);
                        if(me->query("potential"))
                        {
                                me->set("potential",me->query("potential")-1);
                                me->add("neili",-random(50));
                        }
                        else me->add("neili",-100-random(50));

                        me->improve_skill("force",100+random(100));
                }
                else
                {
                        message_vision(
HIY"$N只觉内力不足，想要打通的任脉只差一丝丝，可是偏偏就是过不去。累得出了一身大汗。\n"NOR,me);
                        me->add("neili",-100);
                        me->add("jingli",-500);
                }
        }

        me->add("quanzhen/shentong_times",1);
}


int do_qiecuo(string arg)
{
        object me = this_player();
        object target;
        object here=environment(me);
        int skill, value;
		object where;

		seteuid(getuid());
        where = environment(me);

        if(me->is_busy())return notify_fail("你正忙着呢。\n");
		if (where->query("no_fight"))
                return notify_fail("比试的念头刚在脑中一闪，四周就凝结了一层杀气。\n");
        if(!arg)return notify_fail("你想和谁切磋？\n");
        target = present(arg,here);
        if(!target)return notify_fail("你想和谁切磋？\n");

        if( target->query("race") != "人类" )return notify_fail("可惜它不懂人事。\n");
        if( target->query("combat_exp")*3 < me->query("combat_exp")*2 )
                return notify_fail("此人武功太差，无法和你切磋。\n");

        if(!living(target)) return notify_fail("你得等人家醒了才行。\n");
        if(target->is_busy())return notify_fail("人家正忙着呢。\n");

        if(me->query("neili")<1000)return notify_fail("你内力不足，无法切磋。\n");
        if(me->query("jingli")<1000)return notify_fail("你精力不足，无法切磋。\n");
        if(me->query_skill("xiantian-gong",1)<300)return notify_fail("你先天功基础太差，无法切磋。\n");
        if(me->query_skill("force",1)<300)return notify_fail("你内功基础太差，无法切磋。\n");
        if(me->query_skill("taoism",1)<300)return notify_fail("你道学基础太差，无法切磋。\n");

        if( me->query("quanzhen/shentong_times") < 1 ) return notify_fail("你纯阳神通未练已久，该去修练一下了。\n");

        message_vision(
HIG"$N按照纯阳神通功秘诀，运起玄门先天功，聚天地之精气，过紫宫，入泥丸，
透十二重楼，开玄关，通任督，劲随意到，劲到力至。\n"NOR,me);
        message_vision(
HIW"$N紧跟着将内力偏布全身，只见白气逐渐笼罩全身，双眼精光四射，与平时判若两人。\n" NOR, me);

        message_vision(
HIR"$N接着突然出掌攻向$n，当真是无声无息，却迅如闪电。\n" NOR, me,target);

                  skill = me->query_skill("force");
                  me->add("neili", -skill*2);
                  me->set("jiali",0);
                  value = skill * (5+random(me->query("shentong")*5));
                  if( value > 90000 ) value = 90000;
                  if( value < 30000 ) value = 30000;
                  me->add( "jingli",value  );
                  me->add_temp( "apply/attack",value/200  );
                  COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
                  me->start_busy(1+random(2));
                  me->add( "jingli", -value );
                  me->add_temp( "apply/attack",-value/200  );
                  me->improve_skill("force",50+random(100));

                  if( random(10)==1 ) call_out("run_away",0,target);

                  me->set( "quanzhen/shentong_times",me->query("quanzhen/shentong_times")-4 );

        return 1;
}

void destroy_me(object ob)
{
        message_vision(HIR"$N被纯阳神通功惊人内力所惊，不由得向后连连退步，口道：“佩服！佩服！”。
说完转身撒腿就跑，比兔子还快，转眼就不见了。\n"NOR,ob);
        destruct(ob);
}

void run_away(object ob)
{
        object obj;
        object here = environment(ob);
        string *dirs,dir,dest,target_dir;
        mapping exit;

        if(!ob)return;
        if(!here || !objectp(here) )return;

        if( !userp(ob) && random(100)==1 )
        {
                call_out("destroy_me",1,ob);
                return;
        }

        if(random(5) != 0) call_out("run_away",0,ob);

        message_vision(HIR"$N被纯阳神通功惊人内力所逼，不由得向后连连退步。\n"NOR,ob);

        exit = here->query("exits");
        if( !exit ) return;
        dirs = keys(exit);
        dir = dirs[random(sizeof(dirs))];
        if(!dir)return;
        dest = exit[dir];
        if( !dest )return;

        if( !(obj = find_object(dest)) )
                call_other(dest, "???");
        if( !(obj = find_object(dest)) )
                return;
        if( !wizardp(ob) && obj->query("short") == "巫师休息室" )
                return;

        if( !undefinedp(default_dirs[dir]) )
                                         target_dir = default_dirs[dir];
                  else
                                         target_dir = dir;


        if( ob->move(obj) ) {
                        message_vision(HIY"只见$N踉踉跄呛跑了过来。\n" NOR, ob);
        }
}
