//Cracked by Roath
// modified by xuy 8/10/97
#include <ansi.h>

inherit NPC;
int ask_me();

void create()
{
	set_name("赫连铁树", ({ "helian tieshu", "helian", "tieshu" }) );
	set("nickname", "西夏王爷");
	set("title", "征东大将军");
	set("gender", "男性");
	set("age", 45);
	set("long",
		"此人身穿大红锦袍，鹰钩鼻、八字须。\n");
	set("combat_exp", 50000);
        set("shen_type", -1);
	set("no_get", 1);
	set("attitude", "heroism");

	set("str", 26);
	set("con", 22);
	set("int", 20);
	set("dex", 24);

	set("max_qi", 800);
	set("eff_qi", 2000);
	set("qi", 800);
	set("max_jing", 500);
	set("jing", 500);

	set_temp("apply/attack",  60);
	set_temp("apply/defense", 60);

	set_skill("parry", 60);
	set_skill("unarmed", 60);
	set_skill("dodge", 60);
        set("inquiry",
        ([
                "效命" : (: ask_me :),
        ]));


	setup();

        carry_object("/d/city/obj/xiupao")->wear();
}
void init()
{
        add_action("do_kill", "kill");
}

int do_kill(string arg)
{
        object ob;
        int i;

        if (!arg || !id(arg)) return 0;

        if (present("wu shi", environment(this_object()))){
        	command("say 你想谋害本官，当真是自找死路！ 左右何在！");
        	message_vision("赫连铁树左右的武士对$N发动攻击！\n", this_player());

        	for(i=0; i<2; i++) {
                	if( objectp( ob = present("wu shi " + (i+1), environment(this_object())) ) )
                               	ob->kill_ob(this_player());
        	}
		this_player()->apply_condition("xakiller", 100);
	}
	return 0;
}

int ask_me()
{
	object ob, room, me=this_player();

	if(!( room = find_object("/d/taishan/fengchan")) )
        room = load_object("/d/taishan/fengchan");

        if (userp(me) && me->query("id") == room->query("winner") ) {
        	command("say 阁下是武林盟主，本堂可担待不起！");
        	return 1;
        }

	if ((int)me->query_condition("ypjob") > 0) {
		say("赫连铁树大怒道：他妈的，颁给你的活还没完成，居然敢有脸来见我！\n");
		command("slap " +me->query("id"));
		return 1;
	}

	if ( ((int)me->query("yipin/done")+30)/
			((int)me->query("yipin/failure")+1) < random(3)) {
		command("sneer " +me->query("id"));
		say("赫连铁树冷笑道：你先歇几天吧，我手头这几桩差事可信不过让你去做。\n");
		me->delete_temp("xixia/testpass");
		me->delete_temp("xixia/一品堂");
		me->delete_temp("apply/short");
		me->apply_condition("ypjob", 100);
		return 1;
	}
 
	if (me->query_temp("xixia/一品堂")) {
		command("nod " +me->query("id"));
		me->apply_condition("ypjob", 70);
		if (me->query_condition("xakiller") > 0)
		me->apply_condition("xakiller", 0);
		call_out("assign_job", 1, me);
		return 1;
	}

	if ((int)me->query_temp("xixia/testpass")) {
		say("赫连铁树哈哈大笑道；好！今天起你就在我西夏一品堂下任事吧！\n");
		me->set_temp("xixia/一品堂",1);
		me->delete_temp("xixia/testpass");
		me->set_temp("apply/short",
     ({ HIW"西夏一品堂武士 "NOR+me->query("name")+"("+capitalize(me->query("id"))+")"}));
		me->apply_condition("ypjob", 70);
		if (me->query_condition("xakiller") > 0)
		me->apply_condition("xakiller", 0);
		call_out("assign_job", 1, me);
		return 1;
	} else {
		return notify_fail ("赫连铁树说道：你去问努儿海吧。\n");
	}
}

private int is_suitable(object victim, object killer)
{
	string *no_kill_list = ({
		"mu ren",
		"mengzhu",
		"shangshan shizhe",
		"fae shizhe",
		"xuantong dashi",
		"feng qingyang",
		"huang zhen",
		"juexin dashi",
		"yideng dashi",
		"ren woxing"
	});

	if( victim->query("combat_exp") < killer->query("combat_exp")
	 || victim->query("combat_exp") > killer->query("combat_exp")*7/4
	 || !clonep(victim) || userp(victim) 
	 || victim->query("race") != "人类"
	 || victim->query("shen") < 0
	 || victim->query("winner")
	 || strsrch(base_name(victim), "/kunfu/skill") == 0
	 || strsrch(base_name(victim), "/d/xiakedao/") == 0
	 || strsrch(base_name(victim), "/d/beijing/") == 0
	 || strsrch(base_name(victim), "/clone/user") == 0
	 || strsrch(base_name(victim), "/u/") == 0
	 || member_array(victim->query("id"), no_kill_list) != -1 ) 
	{
		return 0;
	} 
	return 1;
}

void assign_job(object me)
{
	object ob, *victim_list;
	int i;
	string str, ttt;
	
	victim_list = filter_array(livings(), "is_suitable", this_object(), me);
	if( sizeof(victim_list) == 0 ) {
	// try again in 5 secs.
		call_out("assign_job", 5, me);
		return;
	}

	i = random(sizeof(victim_list));

	ttt=gender_pronoun(victim_list[i]->query("gender"));

	say("赫连铁树说道："+victim_list[i]->query("name")+"近日一直跟我们西夏国作对，"
	    +"你去给我把"+ttt+"杀了！\n");
	tell_object(me,"赫连铁树说完扔给你一块青铁令。\n");
	ob=new(__DIR__"obj/ypling");
	ob->set("long", "这是一块西夏一品堂堂主令。上面写着“"+victim_list[i]->query("name")+"”。\n");
	ob->set("victim", victim_list[i]->query("name"));
	ob->set("owner", me->query("id"));
        ob->move(me);
}

int accept_object(object who, object ob)
{
	string *award_list = ({
	"渡难",
	"渡劫",
	"渡厄",
	"洪七公",
	"黄药师",
	"周芷若",
	"张三丰"
	});

	int gain;

	if (ob->query("id") != "head" 
	 || ob->query("owner") != who->query("id"))
		return 0;

	if (who->query_temp("xixia/一品堂")){
	gain = ob->query("gain");
		if (who->query_condition("ypjob") > 0 && ob->query("gain")){
		who->add("combat_exp", gain * 6 + random(gain*5));
		who->add("potential", gain * 3 + random(gain));
		if (who->query("potential") > who->query("max_potential"))
			who->set("potential", who->query("max_potential"));
		command("u&me "+who->query("id"));
		command("say 凭青铁令去努尔海那里领工钱吧。");
		who->add("yipin/done", 1);
		who->apply_condition("ypjob", 0);

	if (member_array(ob->query("victim_name"), award_list) >= 0  
	&& ob->query("combat_exp") > who->query("combat_exp")*3/2)
		who->add("combat_exp", gain*30);		
	}
	else {
		command("kick "+who->query("id"));
		say("赫连铁树大怒道：没用的东西，这麽半天才干完活，亏你还有脸回来见我！\n");
		who->add("yipin/failure", 1);
	}		
	call_out("destroy_it", 1, ob);
        return 1;
	}
}

void destroy_it(object ob)
{
        destruct(ob);
        return;
}

void unconcious()
{
        message_vision("\n突然，$N一按座椅上的机关，只见墙上现出一个门洞，$N转身钻了进去。\n",
                this_object());
        destruct(this_object());
}	
