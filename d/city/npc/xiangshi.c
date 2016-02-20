//Cracked by Roath
//zhanbu 用npc 相士 by maco
inherit NPC;
#include <ansi.h>
#include "/d/REGIONS.h";

void create()
{
        set_name("相士", ({ "xiang shi", "shi" }));
        set("long","一个摆摊算命的道士，神色俨然，看起来倒有点高深莫测。\n");
        set("gender", "男性");	
	set("age", 40);
	set("attitude", "friendly");
	
	set("max_qi", 400);
	set("max_jing", 400);
	set("neili", 50);
	set("max_neili", 50);
	set("combat_exp", 10000);

	set_skill("force", 30);
	set_skill("dodge", 30);
	set_skill("parry", 30);
	set_skill("qimen-dunjia", 60);


        set("inquiry", ([
		"占卜" : "不是贫道胡吹，不管紫微数、梅花易数、铁板神算、手相面相，贫道样样精通，祗要十两黄金，贫道给你铁口直断，千不一失。不过当然钱给多点更准....",
        ]));

	setup();
	carry_object("/d/wudang/obj/greyrobe")->wear();
}

void init()
{
        ::init();
	add_action("do_divine", "divine");
	add_action("do_divine", "zhanbu");
}

int do_divine(string arg)
{
        object ob, where, env, me = this_player();
        string region;
	
	if (!me->query_temp("zhanbu_gold"))
		return 0;

        if( !living(this_object()) )
                return notify_fail("嗯....你得先把相士弄醒再说。\n");

        if( this_object()->is_busy() )
                return notify_fail("相士说道：请稍等，我正忙著呐。\n");

	if(this_object()->query("jing") < 80)
                return notify_fail("相士说道：请稍等，我现在很累。\n");

	if (!arg) return notify_fail("相士告诉你：你要占卜谁的位置？\n");
	
        if( !(ob = find_player(arg)) )
        if( !(ob = find_living(arg)) )
	        return notify_fail("相士告诉你：现在没这个人。\n");
        if( ob == me )
	        return notify_fail("占卜自己的位置？没这个必要吧。\n");
	        
        if( ob == this_object() )
	        return notify_fail("要相士占卜自己？浪费钱也不是这样子。\n");

	write("\n你在相士的耳边悄声说道：麻烦先生替我占卜"+ob->name()+"的所在。\n\n");
        tell_room( environment(me), "\n"+me->name() + "在相士耳边小声地说了些话。\n", ({ me, this_object() }) );

	message_vision(CYN"相士拿起一只木雕八卦屏心凝气，拇指依次掐向上面子、、寅、卯、辰、巳、午、未、申、酉、戌、亥\n各个方位，细心推算起来……\n\n"NOR, me);
	me->start_busy(1);

	if( !(where = environment(ob)) ) {
		command("doubt xiang shi");
	        return notify_fail("相士告诉你：这个人……目前找不到。\n");
		}
        if( !wizardp(me) && wizardp(ob) ) {
		command("fear");
		return notify_fail("相士脸色发白，低声道：这个人是巫师，我可不敢说！\n");
		}
        if( strsrch(file_name(where), "/d/") != 0
        ||  undefinedp(region = region_names[explode(file_name(where), "/")[1]]) ) {
        	command("doubt xiang shi");
                return notify_fail("相士告诉你：这个人……目前找不到。\n");
		}

	env = environment(me);

	if( random(me->query_kar()/2) + me->query_temp("zhanbu_gold") > ob->query_kar()*3/2 ) {
	
	command("whisper "+me->query("id")+" "+ob->name()+"("+ob->query("id")+")现在在"+region+""+where->query("short")+"。");
		if( random(me->query("kar")) < ob->query("kar") )
		tell_object(ob, HIB"你感觉心神不定，似乎有人在暗中窥视着你......好像是"+me->query("name")+"("+me->query("id")+")！\n"NOR);
	} 
	
	else if( me->query_kar() + me->query_temp("zhanbu_gold") > random(ob->query_kar()) ) {
	command("whisper "+me->query("id")+" "+ob->name()+"("+ob->query("id")+")现在在"+region+"一带。");
	 	if( random(me->query("kar")) < ob->query("kar"))
                tell_object(ob, HIB"你感觉心神不定，似乎有人在暗中窥视着你......好像是"+me->query("name")+"("+me->query("id")+")！\n"NOR);

	} else {
	command("dunno");
	command("say "+ RANK_D->query_respect(me) +"付的金子太....啊不，福缘太差，所以贫道有点算不大清楚.....");
	}
	
	me->delete_temp("zhanbu_gold");
	add("zhanbu_times",1);

	if(query("zhanbu_times") > 8){
	command("rich xiang shi");
	command("say 今天够本了，收摊。");
        message_vision("$N快步离开了。\n",this_object());
        destruct(this_object());

	}
	
	return 1;
}


int accept_object(object who, object ob)
{
        object me = this_player();
        if(me->query("combat_exp") < 10000)
                return notify_fail("你的经验太低了，无法请人占卜。\n");

        if (ob->query("money_id") && (int)me->query_skill("qimen-dunjia",1) > 60 && me->query("family/family_name") == "桃花岛"){
                tell_object(who, "相士苦著脸道："+ RANK_D->query_respect(me) +"自己就是奇门遁甲的好手，就别来踢我场子，让贫道混口饭吃吧？\n");
                return 0;
                }

        if (ob->query("money_id") && ob->value() >= 100000 ) 
        {
        
                who->add_temp("zhanbu_gold",ob->value()/100000);
		command("rich xiang shi");
		command("say "+ RANK_D->query_respect(me) +"要占卜(zhanbu)些什麽？");
                return 1;
        }
        else if (ob->query("money_id") && ob->value() < 100000) 
        {
	message_vision("相士双眼一翻，道：十两黄金，是会要你命麽？\n", me);
                return 1;
        }

        return 0;
}
