//Cracked by Roath
// longx.c 侠客岛龙
// Long, 6/13/97

#include <ansi.h>

inherit NPC;
object me;
string* commands = ({
	"north",
	"north",
	"northup",
	"climb tree", 
	"remove cloth",
	"wear coat",
	"jump fall",
	"east",
	"north",
});
string* places = ({
	"/d/xiakedao/shanlu1",
	"/d/xiakedao/shanlu2",
	"/d/xiakedao/pubu",
	"/d/xiakedao/pubu",
	"/d/xiakedao/pubu",
	"/d/xiakedao/pubu",
	"/d/xiakedao/yongdao1",
	"/d/xiakedao/yongdao3",
	"/d/xiakedao/dadong",
});
string* fname = ({
	" yi"," er", " san", " si", " wu", " liu", " qi", " ba", " jiu",
});

string* wait = ({
	" 岛主在洞中相候，请跟" + RANK_D->query_self(this_object()) + "来吧。",
	" 阁下请移驾到侠客洞中再发呆吧。", 	
});

int ask_leave();
int ask_food();
int ask_daozhu();
void greeting();
void checking();
void check_follow(object, int);
void create()
{	int i;
	i = random(8) + 1;
	set_name("龙" + chinese_number(i), ({ "long" + fname[i-1]}));
	set("long", "他是侠客岛龙岛主门下的一个弟子。身上穿着洗得发白的锦衣，
头上带着秀才帽，一脸的书呆子气，怎麽看也不象是个武林中人。\n");
	set("nickname", "引路使");
	set("gender", "男性");
	set("age", random(30) + 20);
	set("attitude", "peaceful");
	set("shen_type", 1);
	set("str", 30);
	set("int", 25);
	set("con", 25);
	set("dex", 25);
	set("race", "人类");	
	set("max_qi", 1500);
	set("eff_qi", 1500);
	set("qi", 1500);
	set("max_jing", 1500);
	set("eff_jing", 1500);
	set("jing", 1500);
	set("max_neili", 1500);
	set("eff_neili", 1500);
	set("neili", 1500);
	set("max_jingli", 1500);
	set("eff_jingli", 1500);
	set("jingli", 1500);
	set("combat_exp", 300000 + random(5) * 100000);
	set("score", 1000);
	
	set_skill("force", 150);
	set_skill("dodge", 150);
	set_skill("parry", 150);
	set_skill("strike", 150);
	set_skill("sword", 150);
	set_skill("taiji-shengong", 150);
	set_skill("liuxing-bu", 150);
	set_skill("wugou-jianfa", 150);
	set_skill("wuyu-zhangfa", 150);

      map_skill("force", "taiji-shengong");
	map_skill("sword", "wugou-jianfa");
	map_skill("parry", "wugou-jianfa");
	map_skill("dodge", "liuxing-bu");
	map_skill("strike", "wuyu-zhangfa");
	
	prepare_skill("strike", "wuyu-zhangfa");
	setup();
	carry_object("/clone/weapon/changjian")->wield();
	carry_object(__DIR__"obj/yellowrobe")->wear();

}
void init()
{
      me = this_player();
	::init();
      if( interactive(me) )
      {	//command("say " + query_temp("xkd/guest") + " -- " + me->query("id"));
		if (query_temp("xkd/guest") == me->query("id"))
		{	remove_call_out("greeting");
            	call_out("greeting", 0);
		}
	}
	//remove_call_out("checking");
	//call_out("checking", 5);
}

void greeting()
{	
	me = present(query_temp("xkd/guest"), environment(this_object()));
//	command("say " + me->query("id"));
	if (!(me->query_leader() == this_object()))
	{	command("hi " + query_temp("xkd/guest"));
		command("say " + RANK_D->query_self(this_object()) + query("name") + 
			"奉岛主之命在此恭迎大驾，" + RANK_D->query_respect(me) + "请跟我来。\n" +
			"    "+HBRED+HIW"(follow " + query("id") + ")"NOR);	
		remove_call_out("check_follow");
		call_out("check_follow", 20, me, 0);
		return;
	}
}
void check_follow(object me, int count)
{	int i;
	object long = this_object();
    	if( !(find_player(query_temp("xkd/guest"))))
	{	command("say 这人也真是的，一转眼就不知跑哪去了。");
		message_vision("$N说完转身离去了。\n", long);
		remove_call_out("check_follow");
		destruct(long);
		return;
	}
	if (me->query_leader() == this_object())
	{	remove_call_out("move_next");
		call_out("move_next", 1, me, 0);
	}
	else
	{	if ( count > 2 )
		{	message("vision", long->name() + "不知从哪变了出来，拉起" + me->name() + "的手，身形一闪便不见了\n", environment(me), ({me}));
			tell_object(me, long->name() + "不知从哪变了出来，拉起你的手边走边埋怨道：叫你跟我的，还乱跑，来吧。\n");
			me->move(environment(long));
			me->set_leader(long);
			remove_call_out("check_follow");
			call_out("check_follow", 1, me, count);
		}
		else
		{
			i = random(sizeof(wait));
			command("tell " + me->query("id") + wait[i]);
			count = count + 1;
			remove_call_out("check_follow");
			call_out("check_follow", 10, me, count);
		}
	}
	return;
}
void move_next(object me, int count)
{	object long = this_object();
    	if( !(objectp(me=find_player(query_temp("xkd/guest")))))
	{	command("say 这人也真是的，一转眼就不知跑哪去了。");
		message_vision("$N说完转身离去了。\n", this_object());
		remove_call_out("check_follow");
		destruct(this_object());
		return;
	}
	if (count >= sizeof(commands))
	{	command("say " + RANK_D->query_respect(me) + "请在这里稍候，岛主一会便到。");
		command("bye " + me->query("id"));
		me->set("xkd/hosted", 1);
		message_vision("$N说完挥了挥手，转身离去了。\n", long);
		destruct(long);
		return;
	}
	command(commands[count]);
	if (!(present(me, environment(long))))
	{	message("vision", long->name() + "不知从哪变了出来，拉起" + me->name() + "的手，身形一闪便不见了\n", environment(me), ({me}));
		tell_object(me, long->name() + "不知从哪变了出来，拉起你的手边走边埋怨道：叫你跟我的，还乱跑，来吧。\n");
		//message_vision("$N不知从哪变了出来，埋怨你道：叫你跟我的，还乱跑，来吧。\n", long);
		me->move(places[count]);
		remove_call_out("move_next");
		call_out("move_next", 10, me, count);
	}
	count = count + 1;
	remove_call_out("move_next");
	call_out("move_next", 10, me, count);
	return;
}
