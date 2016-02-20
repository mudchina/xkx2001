//Cracked by Roath
// ling.c
inherit ITEM;
#include <ansi.h>
void create()
{
        set_name(YEL"铁焰令"NOR, ({ "tieyan ling","ling"}));
        set_weight(10);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "令");
                set("long",
                        "这是明教信物<铁焰令>，明教弟子必须随身携带，万万不可丢失，否则后果不堪设想。\n"
						"凭这块铁焰令能：\n"
						"向明教中有威望的兄弟请教武功(qingjiao <某人> <技能>)。\n");
                set("value", 0);
                set("material", "iron");
				set("no_get",1);
				set("no_drop","这是明教信物，岂能丢弃。\n");
				
				set("no_give","这是明教信物，岂能给人。");
				set("no_insert", 1);
         }
	setup();
}
int query_autoload()
{
	return 1;
}
int init()
{
	add_action ("do_qingjiao", "qingjiao");
}

int do_qingjiao(string arg)
{
	
	string skill, teacher, master, skill_name, slow_msg;
	object ob;
	int master_skill, my_skill, gin_cost,i,teach_falg,slow_factor;
	int tmp, learn_times;

	mixed master_allskill;
	
	
	object me=this_player();
	mapping fam = me->query("family");
	mapping fam_ob;
    if (me->is_busy())
		return notify_fail("你现在正忙着呢。\n");

    if(!arg)
		return notify_fail("指令格式：qingjiao <某人> <技能> [次数]\n");

    if (sscanf(arg, "%s %s %d", teacher, skill, learn_times)!=3 ) {
		learn_times = 1;
        if (sscanf(arg, "%s %s", teacher, skill)!=2 )
			return notify_fail("指令格式：qingjiao <某人> <技能> [次数]\n");
        }
	if (learn_times < 1) 
		return notify_fail("指令格式：qingjiao <某人> <技能> [次数]\n");
    if( me->is_fighting() )
		return notify_fail("临阵磨枪？来不及啦。\n");

    if( !(ob = present(teacher, environment(me))) || !ob->is_character())
		return notify_fail("你要向谁求教？\n");

   if( !living(ob) )
	   return notify_fail("嗯....你得先把" + ob->name() + "弄醒再说。\n");
   fam_ob = ob->query("family");	
   if (fam_ob["family_name"] != "明教")
	   return notify_fail("你只能向明教中的兄弟请教武功。\n");


   if( (int)me->query("potential") < learn_times )
       return notify_fail("你的潜能不够，没有办法再成长了。\n");

	if(ob==me)
		return notify_fail("自己向自己请教？\n");
	if (fam["family_name"] != "明教")
		return notify_fail("你非我明教兄弟，如何搞得这铁焰令,居然还来向我讨教功夫？快向wzfeng汇报你得到铁焰令的方法。\n");

	if(!master_allskill=ob->query("teach_skillsname"))
		return notify_fail(ob->name()+"没什么可以请教的武功。\n");
		if(skill=="literate")
	{
		return notify_fail(ob->name()+"说道：读书写字只能靠你平时自己在书院学习，我不能传授你。\n");

	}

	i=sizeof(master_allskill);
	if(i=sizeof(master_allskill))
		for(i=0;i<sizeof(master_allskill);i++)
			if(master_allskill[i]==skill)
				teach_falg=1;
	if(!teach_falg)
		return notify_fail(ob->name()+"不能传授你这项武功。\n");
		
	if( ob->prevent_learn(me, skill) )
		return 1;

	my_skill = me->query_skill(skill, 1);
	master_skill = ob->query_skill(skill, 1);
	if( my_skill >= master_skill )
		return notify_fail(ob->name()+"呵呵一笑：这项技能你已经不输与我，我那里还敢教阁下什么？\n");

	
	if( !SKILL_D(skill)->valid_learn(me) ) return 0;
	 
	slow_factor = 1;
    slow_msg = "";

        
	gin_cost = 150 / (int)me->query("int");
    if( !my_skill ) 
	{
		gin_cost *= 2;
        me->set_skill(skill,0);
    }
     printf("你向%s请教有关「%s」的疑问。\n", ob->name(), to_chinese(skill));

     if( ob->query("env/no_teach") )
		 return notify_fail("但是" + ob->name() + "现在并不准备回答你什么。\n");

	 tell_object(ob, sprintf("%s向你请教有关「%s」的问题。\n", me->name(), to_chinese(skill)));

    if( (int)ob->query("jing") > learn_times*gin_cost/5 + 1 ) {
            if( userp(ob) ) ob->receive_damage("jing", learn_times*gin_cost/5 + 1);
    } else {
            write("但是" + ob->name() + "显然太累了，没有办法教你什么。\n");
            tell_object(ob, "但是你太累了，没有办法教" + me->name() + "。\n");
            return 1;
    }

	gin_cost = learn_times * gin_cost*3/2;
        
        if( (int)me->query("jing") > gin_cost ) {
                if( (string)SKILL_D(skill)->type()=="martial"
                &&      my_skill * my_skill * my_skill / 10 > (int)me->query("combat_exp") ) {
                        printf("也许是缺乏实战经验，你对%s的回答总是无法领会。\n", ob->name() );
                } else {
                    if(skill_name = SKILL_D(skill)->query_skill_name(my_skill)) {
                            printf("你听了%s的指导，%s对「%s」这一招似乎有些心得。\n", 
                                    ob->name(), slow_msg, skill_name);
                    }
                    else
                        printf("你听了%s的指导，%s似乎有些心得。\n", ob->name(), slow_msg);

                    me->add("potential", -learn_times);

                    tmp = 0;
                    for (i=0; i<learn_times; i++)  tmp += random(me->query_int());
        
	     me->improve_skill(skill, tmp/slow_factor);

                }
        } else {
                gin_cost = me->query("jing") > 0 ? (int)me->query("jing") : 0;
                write("你现在精神不够，无法向"+ob->name()+"请教"+to_chinese(skill)+"。\n");
				return 1;
        }

        me->receive_damage("jing", gin_cost);

        return 1;
}





