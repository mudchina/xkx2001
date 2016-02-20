//Cracked by Roath
// Jay 8/9/96
//changed by wzfeng@xkx 99/12/5

#include <ansi.h>
inherit ITEM;


void create()
{
        set_name("铁床", ({"tie chuang","chuang","bed"}));
        set_weight(200000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
		set("long","如果你看到这行信息，说明系统小有问题，请quit再重进一遍，抱歉。\n");
                set("unit", "张");
                set("material", "steal");
        }
        setup();
}


void init()
{
	object ob,kao;
        add_action("do_du", "du");
        add_action("do_du", "study");
        add_action("move_dianzi","move");
	add_action("do_sleep","sleep");
	add_action("do_look","look");
	add_action("do_look","l");
	add_action("do_dayun","dayun");
	add_action("do_sangong","sangong");
	add_action("do_break","break");

        if( interactive(ob = this_player()) ){
		remove_call_out("heibai_ask");
                call_out("heibai_ask",180,ob,3);
	}
	if(!present("liaokao",ob)) {
		kao = new(__DIR__"liaokao");
		kao->move(ob);
	}
	else call_out("zhenyun",3,ob);
	
}

void zhenyun(object ob)
{
//	ob->unconcious();
       message("system", 
          HIR "\n你的眼前一黑，接著什么也不知道了....\n\n" NOR, ob);
	ob->disable_player(" <昏迷不醒>");
	ob->set("jing",0);
	ob->set("qi",0);
	ob->set("jingli",0);
	ob->set_temp("block_msg/all",1);        
	COMBAT_D->announce(ob, "unconcious");

        call_out("revive", random(100 - ob->query("con")) + 30,ob);
}

void revive(object ob)
{
        remove_call_out("revive");
        while( environment(ob)->is_character() )
                ob->move(environment(environment(ob)));
        ob->enable_player();
        COMBAT_D->announce(ob, "revive");
        ob->set_temp("block_msg/all", 0);
        message("system", HIY "\n慢慢地你终于又有了知觉....\n\n" NOR,
                ob);
        add_action("do_du", "du");
        add_action("do_du", "study");
        add_action("move_dianzi","move");
        add_action("do_sleep","sleep");
        add_action("do_look","look");
        add_action("do_look","l");
        add_action("do_dayun","dayun");
        add_action("do_sangong","sangong");
        add_action("do_break","break");

}

void heibai_ask(object ob, int t)
{
        object heibai;

	if(!objectp(ob)) return;
	if (environment(ob)->query("short") != "地牢") return;

        tell_object(ob,"\n\n\n突然门外传来脚步声。\n");

        if (ob->query("max_neili")==0 || t>0) {

        tell_object(ob,"只听得门外有人说道：「任先生，我有一句话，每隔两个月就来问你老人"
        "家一次，今天我还是这句话，老先生到底答不答允(dayun)？」\n\n");
        ob->set_temp("dayun/can",1);
	remove_call_out("heibai_leave");
        call_out("heibai_leave",30,ob,t-1);
        }
        else {
        tell_object(ob,"只听得门外有人说道：「任先生，你怎麽不说话？」\n");

        heibai=new("/d/jiaxing/npc/heibai2");
        heibai->move(environment(ob));
        message_vision("\n铁门匡啷一响，走进一个人来。\n",ob);
	}
        return;
}

int do_dayun(string arg)
{
	object heibai;

	object me = this_player();
	if (me->query_temp("dayun/can")) {
	tell_object(me, "门外的人激动地说：「任先生，我这就进来。」\n");
        heibai = new("/d/jiaxing/npc/heibai2");
        heibai->move(environment(me));
        message_vision("\n铁门匡啷一响，走进一个人来。\n",heibai);
	remove_call_out("heibai_leave");
	remove_call_out("heibai_ask");
	return 1;
	}
	else return 0;
}



void heibai_leave(object ob, int t)
{
	if(!objectp(ob)) return;
	tell_object(ob,"只听得门外的人说：「既然老先生不答允，我下次再来。」\n\n");
	ob->set_temp("dayun/can",0);
	remove_call_out("heibai_ask");
	call_out("heibai_ask",250,ob,t);
	return;
}

int do_look(string arg)
{
	object me=this_player();

	if (!arg || !(arg=="chuang" || arg=="tie chuang" || arg=="bed"))
		return 0;

	if (!query("tieban")) {
	 	write("一张硬梆梆的铁床，床上铺着草垫子(dianzi)。\n");
		return 1;
	}
	if (me->query_temp("tieslept")) {
		write("
一张硬梆梆的铁床，床上铺着草垫子被卷在一旁，露出刻在上面密密麻麻的字迹。
上面刻着：

    老夫生平快意恩仇，杀人如麻，囚居湖底，亦属应有之报。唯老夫任
    我行被困於此，一身通天彻地神功，不免与老夫枯骨同朽，後世小子
    ，不知老夫之能，亦憾事也。兹将老夫神功精义要旨，留书於此，後
    世小子习之，行当纵横天下，老夫死且不朽。

    功成之後，可用散功(sangong)将你的内力最大值降为零。这样就可以
    免除你内力过强之烦恼。
\n"
);
		return 1;
	}
	else {
		write("一张硬梆梆的铁床，床上的草垫子(dianzi)已被挪到一旁。\n");
		return 1;
	}
}

int move_dianzi(string arg)
{
        object me = this_player();

        if (!arg || arg=="")
                return notify_fail("你要挪动什么？\n");
        if (arg == "dianzi")
        {
          if (query("tieban")) {          
          write ("你把卷起来的草垫又铺到铁板上。\n");
	  say (me->name()+"把卷起来的草垫又铺到铁板上。\n");
          set("tieban",0);
	  }
          else {
          write("你把铁床上的破草垫卷起来，露出冰凉的铁板。\n");
	  say (me->name()+"把铁床上的破草垫卷起来，露出冰凉的铁板。\n");
          set("tieban",1);
          }
          return 1;
        }
        if (arg == "chuang" || arg=="bed" || arg=="tie chuang"){
                write("铁床太重了。你挪不动。\n");
                return 1;
        }
}

int do_sleep(string arg)
{
  object me = this_player();
  object where = environment(me);
  object *inv;
  int i;
  int normal;
  if(me->query_temp("sleeped"))
	  return 0;

  if (query("tieban") && !(me->query_temp("tieslept")==1)) {
        if (me->is_busy())
                return notify_fail("你正忙着呢！\n");

        inv = all_inventory(me);
        for(i=0; i<sizeof(inv); i++)
            if( inv[i]->query("equipped") 
		&& inv[i]->query("armor_type")=="cloth")
                i = sizeof(inv)+1;

        if (i==sizeof(inv)+2)
                normal = 1;
        else normal = 0;
  }
  else normal = 1;

        write("你往床上一躺，开始睡觉。\n");
        write("不一会儿，你就进入了梦乡。\n");
		me->set_temp("sleeped",1);
        me->set_temp("block_msg/all",1);
        message_vision("$N一歪身，倒在床上，不一会便鼾声大作，进入了梦乡。\n",me);
        where->add_temp("sleeping_person", 1);
        me->disable_player("<睡梦中>");

  if (normal) call_out("normal_wakeup",random(60 - me->query("con")), me, where);
	else call_out("wakeup",random(60 - me->query("con")), me, where);
  return 1;

}

void wakeup(object me,object where)
{
       object oldbed, newbed;

	if(!objectp(me)) return;
        while( environment(me)->is_character() )
                me->move(environment(environment(me)));
        me->enable_player();
        me->apply_condition("sleep", 8 + random(5));


        message_vision("$N一觉醒来，精力充沛地活动了一下筋骨。\n",me);
		me->delete_temp("sleeped");
        me->set_temp("block_msg/all", 0);

        where->add_temp("sleeping_person", -1);

        write("这一觉睡得甚是畅快，醒转来时，顿觉精神饱满。突然之间，在"
                "微弱的灯光下，只见自己左手背上凸起了四个字，清清楚楚是"
                "“我行被困”四字。\n");

        me->set_temp("tieslept",1);
        add_action("do_du", "du");
        add_action("do_du", "study");
        add_action("move_dianzi","move");
        add_action("do_sleep","sleep");
        add_action("do_look","look");
        add_action("do_look","l");
	add_action("do_dayun","dayun");
	add_action("do_sangong","sangong");
	add_action("do_break","break");

        return ;
}

void normal_wakeup(object me,object where)
{
        int sp, new_hp;

	if( !objectp(me) ) return;
        sp = 10 - (int)me->query_condition("sleep");
//      me->add("qi", (((me->query("eff_qi")) - me->query("qi"))*sp)/10 + 3);
        new_hp = (int)me->query("qi");
        new_hp += ((int)me->query("eff_qi") - new_hp)*sp/10;
        if (new_hp < 0) new_hp = 0;
        me->set("qi", new_hp);

        new_hp = (int)me->query("jingli");
        new_hp += ((int)me->query("max_jingli") - new_hp)*sp/10;
        if (new_hp < 0) new_hp = 0;
        me->set("jingli", new_hp);

        new_hp = (int)me->query("jing");
        new_hp += ((int)me->query("eff_jing") - new_hp)*sp/10;
        if (new_hp < 0) new_hp = 0;
        me->set("jing", new_hp);

        new_hp = (int)me->query("neili");
        new_hp += ((int)me->query("max_neili") - new_hp)*sp/20;
        if (new_hp < 0) new_hp = 0;
        me->set("neili", new_hp);

        while( environment(me)->is_character() )
                me->move(environment(environment(me)));
        me->enable_player();
        me->apply_condition("sleep", 8 + random(5));

        message_vision("$N一觉醒来，精力充沛地活动了一下筋骨。\n",me);
        me->set_temp("block_msg/all", 0);
        write("你一觉醒来，只觉精力充沛。该活动一下了。\n");

        //if (!where->query("sleep_room") && !where->query("hotel"))
                //where->delete("no_fight");

        where->add_temp("sleeping_person", -1);
        //me->delete("no_get");
        //me->delete("no_get_from");
        add_action("do_du", "du");
        add_action("do_du", "study");
        add_action("move_dianzi","move");
        add_action("do_sleep","sleep");
        add_action("do_look","look");
        add_action("do_look","l");
	add_action("do_dayun","dayun");
	add_action("do_sangong","sangong");
        add_action("do_break","break");

}

int do_sangong(string arg)
{
	object me = this_player();

	if (!me->query_temp("tieslept"))
	return 0;

	if( me->query_skill("huagong-dafa",1) < 30) {
	write("你的化功大法还不足以进行散功。\n");
	return 1;
	}
	if(me->query("max_neili")==0) {
	write("你的内力已散得一干二净。没什麽好再散的了。\n");
        return 1;
        }
	
	if(!me->query_temp("sangong_once")) {
	me->set_temp("sangong_once",1);
	write("散功意味着把内力最大值清为零。望你三思而後行。你如果肯定要散，"
		"再重复一遍此命令。\n");
	return 1;
	}

	write("你把全身内力散尽，有说不出的通泰。\n");
	me->set("neili",0);
	me->set("mz_neili",me->query("max_neili"));
	me->set("max_neili",0);
	me->delete_temp("sangong_once");
	return 1;
}

int do_break(string arg)
{
	object me= this_player();
	object kao;

	if( !arg || arg=="" ) return 0;
	if (arg!="liaokao") return 0;

	if(!(kao=present("liaokao",me))) return 0;
	
	if (me->query("max_neili")>0) {
	write("你一使劲，周身内力激荡，你差点疼得昏过去。\n");
	return 1;
	}

	if (me->query("combat_exp")<500) {
	write("你功力不够，掰不开镣铐。\n");
        return 1;
        }

	write("你一使劲，镣铐竟然被掰开了。\n");
	destruct(kao);
	return 1;
}
int do_du(string arg)
{
	mapping skl;
        string *sname;
	int hglevel, i, k=0; 

        object me = this_player();
        if (!(arg=="tie chuang" || arg=="chuang" || arg=="bed"))
	return 0;

        if (me->is_busy()) {
                write("你现在正忙着呢。\n");
                return 1;
        }
        if (!id(arg)) {
                write("你要读什么？\n");
                return 1;
        }
	if (!query("tieban")) {
                write("床上铺着草垫子呢。\n");
                return 1;
        }
        if (!me->query_temp("tieslept")) {
		write("光溜溜的铁床有什麽好读？\n");
                return 1;
	}

        if( !me->query_skill("literate", 1) ){
                write("你是个文盲，先学点文化(literate)吧。\n");
                return 1;
        }

        if( (int)me->query("jing") < 35) {
                write("你现在过于疲倦，无法专心下来研读新知。\n");
                return 1;
        }

	if (me->query_skill("huagong-dafa", 1)>29){ 
	skl=this_player()->query_skills();
        sname=sort_array( keys(skl), (: strcmp :) );

        for(i=0; i<sizeof(skl); i++) {
                if (SKILL_D(sname[i])->check() == "force")
		k++;
        	}
        if ( k >=2 ){ 
		write("你体内不同内力互相冲撞，难以领会更高深的内功。\n");
		return 1;
		}
        }

	hglevel = me->query_skill("huagong-dafa", 1);
        if( (int)me->query("combat_exp") < (int)hglevel*hglevel*hglevel/10) {
		write("你的实战经验不足，再怎么读也没用。\n");
                return 1;
        }

	if( hglevel > 30 && hglevel < 50) {
		write("你的化功大法火候不足，不能自学化功大法！\n");
		return 1;
        }

        if( me->query_skill("huagong-dafa", 1) > 119){
                write("你研读了一会儿，但是发现上面所说的对你而言都太浅了，没有学到任何东西。\n");
                return 1;
        }

	if( me->query_skill("force", 1)<10) {
		write("你的基本内功火候不足，不能学化功大法。\n");
		return 1;
	}

        if( me->query_skill("huagong-dafa", 1)>29 && 
	(me->query_skill("buddhism",1) || me->query_skill("taoism",1))) {
                write("你的正派心法使你良心发现，不愿再学化功大法。\n");
                return 1;
        }

        me->receive_damage("jing", 35);
	me->improve_skill("huagong-dafa",
		me->query("int")*2/3+me->query_skill("literate",1)/10);
	write("你在黑暗中摸索着铁板，领悟化功大法的要旨。\n");
        return 1;
}                         

