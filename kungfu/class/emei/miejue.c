//Cracked by Roath
// Npc: /kungfu/class/emei/miejue.c 灭绝师太
// Date: xbc 96/09/24
// Modified by xQin 8/00

#include <ansi.h>
inherit F_UNIQUE;
inherit NPC;
inherit F_MASTER;

string ask_for_join();
string ask_for_huansu();
string ask_piaoxue();
string ask_huansu();
int ask_ji();
int auto_perform();
int check_score(mixed);
int start_miejue_event(object, object);

void create()
{
	set_name("灭绝师太", ({ "miejue shitai", "miejue", "shitai" }));
	set("long", 
		"一个白发萧然的老尼，正是峨嵋派掌门人灭绝师太。\n"
		"她容貌算得极美，但两条眉毛斜斜下垂，一副面相便变得极是诡异，\n"
		"几乎有点儿戏台上的吊死鬼味道。\n");

	set("gender", "女性");
	set("attitude", "heroism");
	set("class", "bonze");

	set("age", 45);
	set("shen_type", 1);

	set("str", 25);
	set("int", 25);
	set("con", 25);
	set("dex", 25);

	set("max_qi", 3500);
	set("max_jing", 3500);
	set("neili", 4000);
	set("max_neili", 4000);
	set("jiali", 150);
	set("combat_exp", 3000000);
	set("score", 8000);
	set("PKS", 100000000); //Ryu: Avoid Yitian-jian be begged away!!!

	set_skill("force", 380);
	set_skill("linji-zhuang", 380);
	set_skill("claw", 320);
	set_skill("throwing", 320);
	set_skill("strike", 320);
	set_skill("jinding-zhang", 320);
	set_skill("finger", 300);
	set_skill("tiangang-zhi", 300);
	set_skill("sword", 360);
	set_skill("emei-jian", 360);
	set_skill("blade", 300);
	set_skill("yanxing-dao", 300);
	set_skill("parry", 300);
	set_skill("dodge", 340);
	set_skill("zhutian-bu", 340);
	set_skill("literate", 300);
	set_skill("persuading", 380);
	set_skill("mahayana", 360);

	map_skill("force", "linji-zhuang");
	map_skill("strike", "jinding-zhang");
	map_skill("finger", "tiangang-zhi");
	map_skill("sword", "emei-jian");
	map_skill("blade", "yanxing-dao");
	map_skill("parry", "jinding-zhang");
	map_skill("dodge", "zhutian-bu");

	prepare_skill("strike", "jinding-zhang");
	prepare_skill("finger", "tiangang-zhi");

	create_family("峨嵋派", 3, "掌门人");

	set("chat_chance_combat", 50);
	set("chat_msg_combat", ({
		(: auto_perform :),
	}));

	set("inquiry",([
		"出家"  : (: ask_for_join :),
		"飘雪穿云"  : (: ask_piaoxue :),
		"飘雪穿云掌"  : (: ask_piaoxue :),
		"纪晓芙" : (: ask_ji :),
		"还俗" : (:ask_for_huansu:),
	]));

	setup();
	if( clonep() )
	{
		carry_object("/clone/weapon/yitian-jian");
		//carry_object(__DIR__"obj/xtring")->wear();
		carry_object("/d/emei/npc/obj/nun-cloth")->wear();
		carry_object("/d/emei/npc/obj/emei-shoes")->wear();
	}
}

int ask_ji()
{
	object me = this_player();

	if( !me->query("emei/ji_killer") )
		message_vision(CYN "灭绝师太嘶哑着嗓子说道：“这等不知廉耻的孽徒，留在世上又有何用？”\n"NOR, me);
	else
	{
		switch( me->query_temp("emei/asked_ji") )
		{
			case 0 : command("hmm " + me->query("id")); break;
			case 1 : command("consider " + me->query("id")); break;
			case 2 : command("hit " + me->query("id")); break;
			case 3 : command("kill " + me->query("id")); break;
		}
		me->add_temp("emei/asked_ji", 1);
	}
	return 1;
}

int accept_object(object ob, object obj)
{
	object me = this_object();
	mapping family = me->query("family");
	int mudage = me->query("mud_age");

	if( obj->query("id") == "ji xiaofu" )
	{
		command("thank " + ob->query("id"));
		ob->set("emei/ji_killer", 1);
		if( family["family_name"] == "峨嵋派" )
			me->set("emei/loyal2mj", mudage+random(mudage/2));
		call_out("ji_event", 2, me, obj, 1);
		return 1;
	}

	return 0;
}

int ji_event(object miejue, object ji, int stage)
{
	string msg;

	switch( stage )
	{
		case 1 :
			msg = "";
			if( !living(ji) )
			{
				message_vision(CYN"$N突然间转过身去，伸指在$n人中穴上一按。\n"NOR, miejue, ji);
				ji->revive();
			}
			ji->start_busy(20);
			break;
		case 2 :
			msg = "$N厉声对$n道：“我再问你一次，你愿不愿意去刺杀那个"
			"魔教的淫徒恶贼？\n大功告成之后，你回来峨嵋，我便将衣钵和倚天剑都传了"
			"于你，立你为本派掌门的继承人。”\n";
			break;
		case 3 :
			msg = "$n低头沉思，终于坚决的摇了摇头，显是不肯遵奉师父之命。\n";
			break;
		case 4 :
			msg = "只见$N举起左掌，便要击落，但手掌停在半空，却不击下，想是盼$n最后终于回心转意。\n";
			break;
		case 5 :
			msg = "只见$n突然双膝跪地，却坚决的摇了摇头。\n";
			break;
		case 6 :
			msg = "$N手起掌落，击中$n的顶门。\n";
			ji->receive_wound("qi", ji->query("max_qi")+200);
			break;
	}
	message_vision(CYN+msg+NOR, miejue, ji);
	if( stage < 6 ) call_out("ji_event", 1, miejue, ji, ++stage);

	return 1;
}

void attempt_apprentice(object ob)
{
  mapping fam;
  string name, newname;

  if (!mapp(fam = ob->query("family")) || (string)ob->query("family/family_name") != "峨嵋派")
    {
      command ("say " + RANK_D->query_respect(this_player())
               + "并非我峨嵋派中人，习武还是先从我的弟子那里开始吧。");
      return;
    }

  if (ob->query("class") != "bonze" 
      && ob->query_int() < 38+2*(int)(ob->query("gender")=="男性") ) {
    // can't input chinese now, shall add some words here later
    command("say 阿弥陀佛！贫尼不收俗家弟子。");
    return;
  }

  if ((int)ob->query_skill("linji-zhuang", 1) < 90 ) {
    command("say 我峨嵋派乃内家武功，最重视内功心法。你应该在临济十二庄上多下点功夫。"); 
    return;
  }

  if ((int)ob->query("shen") < 0) 
    {
      command("hmm " + ob->query("id"));
      command("say 我峨嵋派乃是堂堂名门正派，对弟子要求极严。");
      message_vision(
                     "$n看着$N说道：你在外边做的事你师父知道吗？我不收你，你先去做几件侠义的事再来吧。\n",
                     ob, this_object() );
      return;
    }

  command("say 好吧，我暂且收下你。希望你能将峨嵋精神发扬光大。");
  if (fam["generation"] != 4 && ob->query("class") == "bonze" ) {
    name = ob->query("name");
    newname = "静"+name[2..3];
    ob->set("name", newname);
    command("say 从今以后你就是我门下静字辈弟子，法名"+newname+"。");
    command("chat " + name + "入我门下，成为峨嵋派静字辈弟子，法名"+newname+"。");
  }
  command("recruit " + ob->query("id"));

}


void init()
{
	int score;
	object ob;

  add_action("do_kneel", "kneel");

  ::init();
  set_heart_beat(1);

  if (interactive(ob=this_player()) 
      && ob->query("family/master_id") == "miejue shitai"
      && ob->query("shen") < -100) 
    {
      message_vision(
                     "$n看着$N说道：你怎么在外边做坏事？\n",
                     ob, this_object() );
      command("say 我峨嵋派乃是堂堂名门正派，" +
              "对弟子要求极严。我不能再收留你，你去吧。\n");
      command("expell " + ob->query("id"));
      return;
    }
  if (interactive(ob=this_player())
      && this_object()->is_killing(ob->query("id"))
      || present("yitian jian", ob))
    {
      set_leader(ob);
      kill_ob(ob);
      return;
    }
	if( interactive(ob=this_player()) &&
	ob->query("loyal2mj") + 10000 > ob->query("mud_age") &&
	this_object()->query("eff_qi") < this_object()->query("max_qi")/5 &&
	(score = check_score(ob)) > 13 )
		start_miejue_event(this_object(), ob);
}

int check_score(mixed arg)
{
	int i, exp, rate, lvl, mark = 1;
	object me, xqin;
	string *skills;
	mapping family;

        if( stringp(arg) ) me = find_living(arg);
        else if( objectp(arg) ) me = arg;
        else return 0;
        if( !objectp(me) ) return 0;
	xqin = find_player("xqin");

	exp = me->query("combat_exp");
	rate = exp / ( me->query("age")-14 );
	family = me->query("family");
	skills = ({ "linji-zhuang", "emei-jian", "yanxing-dao", "jinding-zhang",
		    "tiangang-zhi", "zhutian-bu" });

	if( rate >= 90000 ) mark += 5;
	else if( rate >= 80000 ) mark += 4;
	else if( rate >= 70000 ) mark += 3;
	else if( rate >= 60000 ) mark += 2;
	else if( rate >= 50000 ) mark += 1;
	tell_object(xqin, "for get exp speed, "+me->name()+" have get "+mark+" marks\n");

	for( i=0; i < sizeof(skills); i++ )
	{
		lvl = me->query_skill(skills[i], 1)+10;
		if( lvl*lvl*lvl > exp*10 )
		{
			mark += 1;
			tell_object(xqin, me->name()+" have gain 1 mark for "+skills[i]+" skill\n");
		}
	}

	if( family["master_name"] == "灭绝师太" && family["master_id"] == "miejue shitai" )
		mark += 3;
	switch( me->query("betrayer") )
	{
		case 0 : mark += 3; break;
		case 1 : mark += 1; break;
	}

	if( me->query("class") == "bonze" ) mark += 2;
	else if( !me->query("married_times") ) mark += 2;

	tell_object(xqin, me->name()+" have get "+mark+" marks for total score!\n");
	return mark;
}

string ask_piaoxue()
{
  object db;
  string msg="";
  int    rate, history;
  mapping info;
  object player = this_player();

  if (!mapp( player->query("family")) || (string)player->query("family/family_name") != "峨嵋派")
    {
      command ("say " + RANK_D->query_respect(player)
               + "并非我峨嵋派中人，不知此话从何说起？");
      return 0;
    }

  db = find_object("/clone/obj/skill_db");
  if (!objectp(db)) db = new("/clone/obj/skill_db");
  if (!objectp(db)) return "什么？";

  info=db->update_usage("piaoxue", this_object(), 0, 0);
  // temporarily set the history
  if (time()-info["last_use"] > info["history"]) {
    history = info["history"];
    info["history"] = time() - info["last_use"];
  }
  rate = db->compute_rate(info);
  info["history"] = history;

  if (rate <= 10) {
    msg = "唉，一班不成器的弟子们到处乱用飘雪穿云掌，如今已不是什么秘密啦。";
  }else if (rate <= 50) {
    msg = "咦，飘雪穿云掌也不是什么深奥的工夫，你师傅没教你么？";
  }else if (rate <= 100) {
    msg = "飘雪穿云掌乃是峨眉掌法精要，我的徒儿们都会吧。";
  }else if (rate <= 200) {
    msg = "飘雪穿云掌虚实莫测，端的厉害无方，当今峨眉派也就我会使啦。";
  }else {
    msg = "故老相传，飘雪穿云掌虚实莫测，乃是江湖上的一大秘密。";
  }
  remove_call_out("more_piaoxue");
  call_out("more_piaoxue", random(20), player, rate);
  return msg;
}

void more_piaoxue(object player, int rate) 
{
  object me = this_object();
  object room = environment(me);

  if (environment(player) != room) return;

  message_vision("\n灭绝师太顿了顿，对$N点头道：好吧，那我就教教你吧。\n", player);
  message_vision("$N说道：飘雪穿云掌乃是内家掌力，讲究的是把内力使得吞吐闪烁，\n"+
        "让敌人摸不着头脑。尤其是要攻其不备，千万不可在江湖上乱用。\n", me);
  if (rate <= 10) return;

  if (random(rate) < 30) 
      message_vision("\n$N接着说道：内力运使时需得三虚一实，五虚一实，乃或七虚一实，\n"+
        "加力要大，让敌人不得轻忽，却又不得要领，然后趁虚直入。\n", me);
  if (rate <= 30) return;

  if (random(rate) < 50) 
      message_vision("\n$N接着说道：飘雪穿云掌使出去后敌人不得全力提防，\n"+
        "此时进攻则其必然大耗真气，于我则事半功倍。\n", me);
  if (rate <= 50) return;

  if (random(rate) < 100)
      message_vision("\n$N接着说道：临济桩乃是峨眉一绝，于飘雪穿云掌也要紧得很。\n"+
        "若是敌人也练了临济桩，那就不用也罢。\n", me);
  if (rate <= 100) return;
        
  if (random(rate) < 300)
      message_vision("\n$N接着说道：掌法，指法需练得炉火纯青，内力使用方才顺手。\n"+
        "若是碰上敌人懂得金顶绵掌或是拳法名家，那就棘手些。\n", me);
  if (rate <= 300) return;

  me->command("whisper "+player->query("id")+" 最重要的是心眼要活，聪明人一点就透吧？\n");
  
}

int accept_fight(object me)
{
  write("灭绝师太一声冷笑：你不配跟我过招。\n");
  return 0;
}
int accept_kill(object me)
{
  command("say 我正想找人杀呐，今天算你倒霉。\n");
  if (present("yitian jian", this_object())){
    command("wield yitian jian");
  }
  set_leader(me);
  kill_ob(me);
  return 1;
}



#include "/kungfu/class/emei/auto_perform.h"
#include "/kungfu/class/emei/nun.h"
