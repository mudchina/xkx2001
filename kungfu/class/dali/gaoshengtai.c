//Cracked by Roath
// Gao Shengtai

#include <ansi.h>
inherit F_SSERVER;
inherit NPC;
inherit F_MASTER;
string ask_me_1();
string ask_me1();
string ask_me();
int auto_perform();
int do_taojiao(string);

void create()
{
	set_name("高升泰", ({ "gao shengtai", "gao"}));
    set("long","大理国侯爷，这是位宽袍大袖的中年男子，三缕长髯，形貌高雅。\n");
	set("title", "善阐侯");
    set("gender", "男性");
    set("age", 35);
    set("rank_info/respect","侯爷");
    set_skill("cuff", 100);
    set_skill("jinyu-quan", 100);
    set_skill("dodge", 100);
    set_skill("duanshi-shenfa", 110);
    set_skill("parry", 90);
    set_skill("force", 105);
    set_skill("kurong-changong", 90);
    set_skill("duanjia-jian",105);
    set_skill("sword",105);
	set_skill("finger",90);
    set_skill("buddhism",110);
    map_skill("cuff","jinyu-quan");
    map_skill("sword","duanjia-jian");
    map_skill("dodge","duanshi-shenfa");
    map_skill("parry", "duanjia-jian");
    map_skill("force","kurong-changong");
    prepare_skill("cuff","jinyu-quan");

    set("str", 23);
    set("int", 23);
    set("con", 24);
    set("dex", 28);
    set("max_qi", 800);
    set("max_jing", 600);
    set("neili", 800);
    set("max_neili", 800);
    set("jiali", 40);
    set_temp("apply/attack", 50);
    set_temp("apply/defence", 50);
    set_temp("apply/armor", 50);
    set("combat_exp", 500000);
	set("inquiry", ([
		"公文" :  (: ask_me_1 :),
		"佛经" :  (: ask_me :),
		"铁链" :  (: ask_me1 :),
		]));

	set("attitude", "peaceful");
    set("shen_type", 1);
	set("chat_chance_combat", 50);
	set("chat_msg_combat", ({
		(: auto_perform :),
	}));

    create_family("大理段家", 15, "弟子");

    setup();
    carry_object("/d/dali/obj/tiedi")->wield();
    carry_object("/d/dali/obj/zipao")->wear();
}

#include "/kungfu/class/dali/auto_perform.h"

void init()
{
	object ob,me=this_object();
	if (interactive(ob = this_player())
		&& ((int)ob->query_condition("dlkiller")
		|| ob->query("dali/trust")<-300)) {
		remove_call_out("kill_ob");
		call_out("kill_ob", 1, ob);
	}
	else {
		if (interactive(ob = this_player()) && ob->query("dali/rank")>=5 && me->query("dali/rank")<5)
			call_out("bow1", 1, me, ob);
		else 
			if (ob->query("dali/rank")==4 && me->query("family/family_name")=="大理段家" && me->query("dali/rank")<5)
				call_out("bow2", 1, me, ob);
	}

	add_action("do_taojiao", "taojiao");
}

int bow1(object me, object ob)
{
	if (present(ob, environment(me)))
		message_vision("$N毕恭毕敬地向$n躬身行礼：“王爷好。”\n",me,ob);
	return 1;
}

int bow2(object me, object ob)
{
	if (present(ob, environment(me)))
		me->command("bow "+ob->query("id"));
	return 1;
}

int accept_fight(object me)
{

	if (me->query("family/family_name") != "大理段家"
		&& !me->query("dali/employee")) {
		command("say 大爷我正想找人杀呐，今天算你倒霉。\n");
        me->apply_condition("dlkiller", 100);
        kill_ob(me);
        return 1;
	}
	else {
		command("say 你我本是同门，切搓一二到也无仿。\n");
        return 1;
	}
}

int accept_kill(object me)
{
	if (me->query("dali/employee")) {
		command("say 你我同府共事，何故加害与我？！我跟你拼了！\n");
		me->add("dali/trust",-1);
	}
	else command("say 大爷我正想找人杀呐，今天算你倒霉。\n");
	me->apply_condition("dlkiller", 100);
	return 1;
}

void unconcious()
{
	object ob, me=this_object();

	if (objectp(ob = me->query_temp("last_damage_from")))
		ob->add("dali/trust", -1);

	::unconcious();
}

void die()
{
	object ob, me=this_object();

	if (objectp(ob=me->query_temp("last_damage_from")))
		ob->add("dali/trust", -1);

	::die();
}

void attempt_apprentice(object ob)
{
	mapping fam;

	if (!mapp(fam = ob->query("family"))
		|| fam["family_name"] != "大理段家") {
		command ("say "+RANK_D->query_respect(ob)+"先去朱傅古褚四位处学学入门功夫吧。");
		return;
	}

	if ((int)ob->query_skill("kurong-changong", 1)< 50) {
		command("say 大理段氏武功多以内功为主。"); 
		command("say "+RANK_D->query_respect(ob) + "是否还应该在枯荣禅功上多下点功夫？");
		return;
	}
	
	if (ob->query("shen") <0 ) {
		command ("say 大理境内容不得你这等阴险小人！");
		return;
	}

	command("say 好吧，我就斗胆代王爷收你作个家臣了。");
	ob->set_temp("title", ob->query("title"));
	command("recruit " + ob->query("id"));
	ob->set("title", ob->query_temp("title"));
	ob->delete_temp("title");
    return;
}

string ask_me_1()
{
	mapping skl; 
    object ob, me=this_player();
    string *sname;
    int i, k;

	if (me->query("family/family_name")!="大理段家"
		&& !me->query("dali/employee"))
		return RANK_D->query_respect(me)+"如要投官，何不前往中原大宋国？";

	if (me->query("dali/rank")>=2)
		return RANK_D->query_respect(me)+"已有官职，无须再申请公文升职了。";

	skl=me->query_skills();
    sname=sort_array( keys(skl), (: strcmp :) );
    for(i=0; i<sizeof(skl); i++) {
		if (skl[sname[i]]<60) k++; }
	if (k>2)
		return RANK_D->query_respect(me)+"功力尚浅，还不够资格申请升级。";

	if (me->query("family/family_name")!="大理段家"
		&& me->query("dali/employee")) {
		if (me->query("dali/arrestmade") < (me->query("combat_exp")*3/4000))
			return RANK_D->query_respect(me)+"还是请先为大理多出力再来申请升级吧。";
		if (me->query("dali/trust") < (100+me->query("dali/arrestmade")/20))
			return RANK_D->query_respect(me)+"在我大理当差，工作还不够努力啊。";
		me->set("dali/rank",1);
	}

	ob = new("/d/dali/obj/allow-letter2");
	ob->set("applicant",me->query("id"));
	ob->move(me);
    message_vision("$N获得一封公文。\n",me);

	return "好吧，凭这封公文，你可以去向定安府总管申请升级。";
}

string ask_me()
{
	object ob,me=this_player(),room=find_object("/d/dali/wuhua2.c");
	mapping fam, log;

	if (!(fam = me->query("family")) 
		|| fam["family_name"] != "大理段家")
		return RANK_D->query_respect(me)+"与本派素无来往，不知此话从何谈起？";

	if (environment()!=room)
		return "对不起，佛经都在王府里，我没带出来，你等我回去再来问我要吧。\n";

	if (me->query_skill("buddhism", 1) < 51 )
		return RANK_D->query_respect(me) + "是否该在佛法上多下些功夫再问不迟？";

	if (query("book_count") > 20)
		return "你来晚了，佛经已经发完了。";

	if (ob=present("fo jing", me))
		return RANK_D->query_respect(me)+"你现在身上不是有佛经吗，怎麽还要？ 真是贪得无厌！";

	log = room->query_temp("fojing");

	if (mapp(log) && log[me->query("id")])
		return "你刚才不是来领过佛经了吗，怎麽又来要了？";

	room->set_temp("fojing/"+me->query("id"),1);
	add("book_count", 1);
	ob = new("/d/dali/obj/fojing2");
	ob->move(me);

	return "好吧，这本佛经你拿回去好好钻研。";
}

string ask_me1()
{
	mapping log; 
	object ob,me=this_player(),room=find_object("/d/dali/wuhua2.c");

	if (me->query("family/family_name")!= "大理段家"
		&& !me->query("dali/employee"))
		return RANK_D->query_respect(me)+"与本派素无来往，不知此话从何谈起？";

	if (environment()!=room)
		return "对不起，铁链都在王府里，我没带出来，你等我回去再来问我要吧。\n";

	if (me->query("combat_exp", 1) < 10000 )
		return RANK_D->query_respect(me) + "是否该多下些功夫再问不迟？";

	if (room->query("chain_count") > 20)
		return "你来晚了，铁链已经发完了。";

//	if (query("chain_count") > 20)
//		return "你来晚了，铁链已经发完了。";

	if (ob=present("tie lian", me))
		return RANK_D->query_respect(me)+"你现在身上不是有铁链了吗，怎么还要？";

	log = room->query_temp("chain");
	if (mapp(log) && log[me->query("id")])
		return "你刚才不是来领过铁链了吗，怎麽又来要了？";

	room->set_temp("chain/"+me->query("id"),1);
	add("chain_count", 1);
	ob = new("/d/dali/obj/chain.c");
	ob->move(me);
	return "你拿去护身，见到有打架斗殴的把他们送给段陉处置。";
}

int accept_object(object who,object ob)
{
	object me=this_object(),room=find_object("/d/dali/wuhua2.c");

	if ((who->query("family/family_name")!="大理段家"
		&& !who->query("dali/employee"))
		|| !present(ob,who)
		|| ob->is_character()
		|| userp(ob)
		|| ob->query("id")!="tie lian")
		return 0;

	command("nod "+who->query("id"));
	remove_call_out("destroying");
	call_out("destroying",1,ob);
	room->delete_temp("chain/"+who->query("id"));
	room->add("chain_count", -1);
//	add("chain_count", -1);
	command("say 很好，"+RANK_D->query_respect(who)+"以后需要用铁链，再来向我要好了。");
	return 1;
}

void destroying(object ob)
{
	destruct(ob);
}

int do_taojiao(string arg)
{
	object me=this_object(), who=this_player();
	int skill, myint;

	if (!arg)
		return notify_fail("你想向高升泰讨教什么功夫？\n");

	if (who->is_busy())
		return notify_fail("你现在正忙着呢。\n");

	if (who->is_fighting())
		return notify_fail("临阵磨枪？来不及啦。\n");

	if (who->query("family/family_name")=="大理段家")
		return notify_fail("你应该向你的师傅请教功夫才是。\n");

	if (!who->query("dali/employee"))
		return notify_fail("什么？\n");

	if (who->query("family")
		&& who->query("family/family_name") != "无"
		&& who->query("dali/rank")<3)
		return notify_fail("你在大理的资历还不够，不能向高升泰讨教武功。\n");

	if (me->is_fighting() || me->is_busy())
		return notify_fail("他正忙着呢，没工夫教你。\n");

	if (!living(me))
		return notify_fail("嗯 ... 你得先把他弄醒再说。\n");

	if (arg!="kurong-changong"
		&& arg!="duanjia-jian"
		&& arg!="duanshi-shenfa"
		&& arg!="buddhism"
		&& arg!="jinyu-quan")
		return notify_fail("高升泰根本不会这门功夫，无法指导你。\n");

	if ((int)who->query("potential") < 10)
		return notify_fail("你的潜能不足，无法领会任何东西。\n");

	if ((int)who->query("jing") <110 )
		return notify_fail("你太累了，无法领会任何东西。\n");
        
	if ((int)me->query("jing") <30 )
		return notify_fail("高升泰太累了，无法指导你。\n");

	skill=who->query_skill(arg,1);

	if (skill>100) return notify_fail("你这门功夫已经登堂入室，不能从高升泰那里讨教到什么了。\n");
	if (skill * skill * skill / 10 > (int)who->query("combat_exp"))
		return notify_fail("你的实战经验不足，无法领会这门功夫。\n");

	message_vision("$N向$n讨教武功，似乎有所领悟。\n", who, me);
	myint=who->query_int();
	who->add("potential", -10);
	who->improve_skill(arg, (random(myint)+random(myint)+random(myint)+random(myint)+random(myint))*2);
	who->receive_damage("jing", 100);
	me->receive_damage("jing", 20);

	return 1;
}
