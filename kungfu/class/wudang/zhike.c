//Cracked by Roath
// zhike.c 知客道长 
// Marz@XKX, 11/11/96
// xuy@XKX, 04/97
// chu@xkx 2/9/99: using job_server to reward exp/pot
// xQin 04/01

#include <ansi.h>

// There are do_yes() & attempt_apprentice() inside:
#include "daozhang.h"

inherit NPC;
inherit F_MASTER;

#ifndef JOB_SERVER
#define JOB_SERVER "/clone/obj/job_server.c"
#endif

#define JOB_NAME "wudang_volunteer"

int do_kill(string arg);
int do_guard();
int do_volunteer();
int do_say(string arg);
int do_quit();
void end_guard(object, int);
void end_volunteer(object, int);
void greeting(object);

int jobid = 1;

void create()
{
  set_name("灵虚道长", ({ "lingxu daozhang", "lingxu", "zhike daozhang", "zhike", "daozhang" }));
  set("nickname", "知客道长");
  set("long",
      "他就是武当二侠俞莲舟的弟子灵虚。\n"
      "也即是武当的知客道长，职务是守在山门迎接香客。\n"
      "他三十多岁，是一位体格强健的中年道士，似乎身怀武艺。\n");
  set("gender", "男性");
  set("age", 35);
  set("attitude", "peaceful");
  set("shen_type", 1);
  set("str", 30);
  set("int", 35);
  set("con", 25);
  set("dex", 35);
        
  set("max_qi", 1200);
  set("max_jing", 800);
  set("neili", 1500);
  set("max_neili", 1500);
  set("jiali", 60);
  set("combat_exp", 80000);
  set("score", 3000);

  set_skill("force", 60);
  set_skill("taiji-shengong", 60);
  set_skill("dodge", 90);
  set_skill("tiyunzong", 90);
  set_skill("cuff", 60);
  set_skill("strike", 60);
  set_skill("mian-zhang",60);
  set_skill("parry", 90);
  set_skill("sword", 90);
  set_skill("taiji-jian", 90);
  set_skill("literate", 60);
  set_skill("taoism", 60);

  map_skill("force", "taiji-shengong");
  map_skill("dodge", "tiyunzong");
  map_skill("strike", "mian-zhang");
  map_skill("parry", "taiji-jian");
  map_skill("sword", "taiji-jian");

  prepare_skill("strike", "mian-zhang");

  create_family("武当派", 3, "弟子");
  set("class", "taoist");
        

  set("inquiry", 
      ([
        "香火" : "香火练制不易，不能随便与人，虔诚奉献者方能得之。",
        "进香" : "进香？童言无忌！童言无忌！要说敬香才是！",
        "敬香" : "殿堂的香火能绵延不断，都因为我武当弟子和山外香客及时敬奉。",
        "虔诚奉献" : "虔诚奉献就是主动多捐献香火钱，多作义工。",
        "敬奉" : "虔诚奉献就是主动多捐献香火钱，多作义工。",
        "松林" : "武当松林在山门前面。",
        "柏林" : "武当柏林就在遇真宫后。",
        "name" : "我是武当的知客道长，负责守卫山门。",
        "here" : "这里是武当的玄岳门，一直南上就可到紫霄宫。",
        "rumors" : "听说山门前的松林里有人参果，不知是真是假。"
        "可是有砍树的道士进去找，就再也没有出来。\n",
        "守卫" : "我这里的工作就是守卫(guard)山门，每次守一天。\n"
        "要是自愿守卫(volunteer)呢，就没有报酬了。",
        "工作" : "我这里的工作就是守卫(guard)山门，每次守一天。\n"
        "要是自愿守卫(volunteer)呢，就没有报酬了。",
        "干活" : "我这里的工作就是守卫(guard)山门，每次守一天。\n"
        "要是自愿守卫(volunteer)呢，就没有报酬了。",
        ]));
                                
  set("wanted", ({ "守卫山门" }));

  set("chat_chance", 5);
  set("chat_msg", ({
    "道长说道：香火练制不易，不能随便与人，虔诚奉献者方能得之。\n",
      "道长说道：我武当地灵人杰，香火鼎盛，普天下的人都来朝拜敬香。\n",
      "道长说道：玄岳门乃武当出入门户，我等一定要精心守卫，不可丝毫懈殆。\n",
      "道长说道：听说山门前的松林里有人参果，有砍树的道士进去找，就再也没有出来。\n",
      }) );


  setup();
  carry_object("/clone/weapon/changjian")->wield();
  carry_object("/d/wudang/obj/greyrobe")->wear();

  // make sure the volunteer job is setup
  if (JOB_SERVER->get_exp_limit(JOB_NAME) < 1) {
      JOB_SERVER->set_exp_limit(JOB_NAME, 2000);
      JOB_SERVER->set_pot_limit(JOB_NAME, 400); //newbie job, more pot
  }
}

int accept_kill(object obj)
{
        if (obj->is_killing(this_object()) ) return 1;
        command("menpai 各位武当同门，" + obj->name() + "这个" + RANK_D->query_rude(obj
) + "胆敢在武当撒野，大伙儿一起跟我上！");
}

void init()
{
  object me = this_player();
  mapping myfam;

  ::init();
        
  if (environment() != load_object("/d/wudang/shanmen") ) return;
  myfam = (mapping)me->query("family");

  add_action("do_guard", "guard");
  add_action("do_volunteer", "volunteer");
  add_action("do_kill", "kill");
  add_action("do_kill", "hit");
  add_action("do_quit", "quit");

  if( !is_fighting() && living(this_object())) {
    if(interactive(me)) {
      if(present("bandit", environment(me))) {
        command("kill bandit");
      } else {
        remove_call_out("greeting");
        call_out("greeting", 1, me);
      }
    } else if(base_name(me) == "/d/wudang/npc/bandit") {
      message_vision("只听知客道长一声怒喝：大胆毛贼竟敢在武当山上行凶杀人，\n且让贫道手中长剑教训教训你！\n", me);
      command("menpai 各位武当同门，蒙面大汉这个臭贼胆敢在武当撒野，大伙儿一起跟我上！");
      command("kill bandit");
      me->kill_ob(this_object());
    }
  }
}

void clear_guard_job(object who)
{
  who->delete_temp("apply/short");
  who->delete("job/guarding");
  who->delete("job/supervisor");
  who->delete("job/description");
  who->delete("job/wage");
  who->delete("job/object");
  who->delete("job/id");
}

void greeting(object me)
{
	mapping myfam;
	object where, ob;

	ob = this_object();
	myfam = (mapping)me->query("family");
	where = environment(ob);

	if( !me || !living(ob) || strsrch(file_name(where), "/d/wudang/") < 0
		|| environment(me) != environment() )
		return;

  if ( myfam && myfam["family_name"] == "武当派" )
    command("say 这位道"+(((string)me->query("gender")=="女性")?"姑":"兄")+
            "辛苦了！");
  else if ( me->query("title") == "武当道童" ) 
    say("知客道长说道：这位"+RANK_D->query_respect(me)
        +"还要继续努力啊！\n");
  else if ( me->query("shen") > -100 ) 
    say("知客道长作了个揖道：这位" + RANK_D->query_respect(me)
        + "请了，欢迎来到武当山！\n");
  else 
    say("知客道长「唰」抽出长剑：这位"+RANK_D->query_respect(me)
        +"满脸杀气，如果不是来武当敬香就请回吧！\n");
}

int do_guard()
{
  object ob, obj=this_object();
  string what;
  string *wanted;

  ob = this_player();
        
  if ( ob->is_busy() || ob->is_fighting() )
    {
      tell_object(ob, "你现在正忙着！\n");
      return 1;
    }           

  message_vision("$N想给知客道长守卫山门。\n", ob);

  if ( ob->query("job/supervisor") )
    {
      command("say 你第一份活儿都没做完就想做第二份？");

      if ( ob->query("job/supervisor") == "知客道长") 
        {
          add_action("do_say", "say");
          command("say 如果你干不了我派给你的活，可以直接跟我说你干不了。");
        } else  
          command("say 如果你干不了，可以直接去告诉"+ob->query("job/supervisor"));      
                
      return 1;
    }

  if (query_temp("stock") > 1)
    {
      command("say 你来晚了，今天的活儿我都分派完了。");
      return 1;
    }

  if ((int)environment(ob)->query_temp("worker/"+ob->query("id")) 
      * (int)ob->query("wudang/offerring") > 700)
    {
      command("say 这两天山门平安无事，你去帮制香道长砍树吧。");
      return 1;
    }

  add_temp("stock", 1);
  set_temp("worker/"+ob->query("id"), 1);

  wanted = query("wanted");
  what = wanted[random(sizeof(wanted))];

  ob->set("job/supervisor", "知客道长");
  ob->set("job/object", what);
  ob->set("job/description", what);
  ob->set("job/id", jobid);
  ob->set("job/guarding", 1);
  ob->set_temp("apply/short", 
               ({ HIW"山门守卫 "NOR+ob->query("name")+"("+capitalize(ob->query("id"))+")"}));

  if ( ob->query("combat_exp") < 1000 ) 
    ob->set("job/wage", 2+random(4));
  else if ( ob->query("combat_exp") < 10000 ) 
    ob->set("job/wage", 4+(ob->query("combat_exp"))/1600 );
  else 
    ob->set("job/wage", 10+(ob->query("combat_exp"))/15000 );


  message_vision("知客道长高兴对$N说道：来得正好，这里正缺人手。\n", ob);
  command("say 你就在这里好好看门吧，可别让那些邪魔歪道的人混进去！");

  call_out("end_guard", 300, ob, jobid);
  jobid++;
  if (random(5)==1){
    remove_call_out("bandit_show");
    call_out("bandit_show", 10, obj);
  }
  return 1;
}


int do_volunteer()
{
  int wage, exp;
  object ob, obj=this_object();
  string what;
  string *wanted;

  ob = this_player();

  if ( ob->is_busy() || ob->is_fighting() )
    {
      tell_object(ob, "你现在正忙着！\n");
      return 1;
    }           

  message_vision("$N想自愿为知客道长守卫山门。\n", ob);

  if ( ob->query("job/supervisor") )
    {
      command("say 你第一份活儿都没做完就想做第二份？");

      if ( ob->query("job/supervisor") == "知客道长") 
        {
          add_action("do_say", "say");
          command("say 如果你干不了我派给你的活，可以直接跟我说你干不了。");
        } else  
          command("say 如果你干不了，可以直接去告诉"+ob->query("job/supervisor"));
    
      return 1;
    }

  if (query_temp("stock") > 1)
    {
      command("say 你来晚了，今天的活儿我都分派完了。");
      return 1;
    }

  if ((int)environment(ob)->query_temp("worker/"+ob->query("id")) 
      * (int)ob->query("wudang/offerring") > 800)
    {
      command("say 这两天山门平安无事，你去帮制香道长砍树吧。");
      return 1;
    }

  add_temp("stock", 1);
  set_temp("worker/"+ob->query("id"), 1);

  wanted = query("wanted");
  what = wanted[random(sizeof(wanted))];

  ob->set("job/supervisor", "知客道长");
  ob->set("job/object", what);
  ob->set("job/guarding", 1);
  ob->set("job/description", what);
  ob->set("job/id", jobid);
  ob->set_temp("apply/short",
               ({ HIW"山门守卫 "NOR+ob->query("name")+"("+capitalize(ob->query("id"))+")"}));

  message_vision("知客道长高兴对$N说道：来得正好，这里正缺人手。\n", ob);
  command("say 你就在这里好好看门吧，可别让那些邪魔歪道的人混进去！");

  if (random(7)==1){
    remove_call_out("bandit_show");
    call_out("bandit_show", 10, obj);   
  }
  exp = ob->query("combat_exp");
  wage = 0;
  
  if (exp > 1000)  wage += 5;
  if (exp > 10000)  wage += 5;
  if (exp > 100000)  wage += 5;
  if (exp > 1000000)  wage += 5;
  ob->set("job/wage", wage);
  JOB_SERVER->start_job(ob, JOB_NAME);
  call_out("end_volunteer", 300, ob, jobid);
  jobid++;
  return 1;
}

void end_guard(object who, int jobid)
{
  int i; 
  object wage;

  if ( !objectp(who) || !present(who, environment(this_object())) 
       || (string)who->query("job/description") != "守卫山门"  
       || (int)who->query("job/id") != jobid )
    return;


  i = (int)who->query("job/wage");
  i = i/2 +random(i);
  if (i < 2 ) i = 2;
        
  wage = new("/clone/money/silver");
  wage->set_amount(i);
  wage->move(who);

  message_vision("知客道长对$N说道：换班时间到，你可以走了！\n", who);
  command("pat " + who->query("id"));
  message_vision("道长给$N"+chinese_number(i)+"两白银作为工作报酬。\n", who);

  who->add("combat_exp", 1+random(i)/6);
        
  who->add("job/succeed", 1);

  clear_guard_job(who);

  add_temp("stock", -1);
  delete_temp("worker/"+who->query("id"));

  environment(who)->add_temp("worker/"+who->query("id"), 1);
}

void bandit_show(object obj)
{
  object ob;
  if(ob = present("bandit", environment(obj)) ) {
    ob->kill_ob(obj);
    obj->kill_ob(ob);
    return;
  }
  ob=new("/d/wudang/npc/bandit");
  ob->move("/d/wudang/shanmen");
  ob->kill_ob(obj);
  obj->kill_ob(ob);
  message_vision(RED"突然山下冲上一个$N，二话不说向守卫们发起攻击！\n"NOR, ob);
}

void adjust_rate() {
  int tmp;

  // the longer a zhike daozhang lives, the more the bonus
  // assuming one hour 12 guards, 2 players guard, which is
  // max, the bonus is about 5 percent per hour
  // if the zhike is alive for 24 hours, they get 300% regular speed
  tmp = JOB_SERVER->get_exp_limit(JOB_NAME);
  tmp += 30;
  if (tmp > 7000) tmp = 7000;
  JOB_SERVER->set_exp_limit(JOB_NAME, tmp);
  tmp = JOB_SERVER->get_pot_limit(JOB_NAME);
  tmp += 6;
  if (tmp > 1000) tmp = 1000;
  JOB_SERVER->set_pot_limit(JOB_NAME, tmp);
}

void end_volunteer(object who, int jobid)
{
  object obn, zhike=this_object();
  int i, j, rate;

  if ( !objectp(who) || !present(who, environment(zhike))
       || (string)who->query("job/description") != "守卫山门"  
       || (int)who->query("job/id") != jobid )
    return;

  message_vision("知客道长对$N说道：换班时间到，你可以走了！\n", who);
  command("say 你如此自愿为武当效力，日后必成武当栋梁！");
  command("thumb " + who->query("id"));

  i = (int)who->query("job/wage");
  j = (int)who->query("wudang/offerring") - (int)who->query("age")*2;
  // offering <= 151 guaranteed by code below
  // wage <= 20 guaranteed by do_volunteer
  rate = i+j;
  if (rate > 100) rate = 100;   // safty check
  if (rate < 10) rate = 10;   // safty check
        
  if ( (who->query("family/family_name") == "武当派" ) && j > 0 )
    {
      JOB_SERVER->reward(who, JOB_NAME, rate, rate);
      adjust_rate();

      if ( random(3) ) 
        {
          tell_object(who, "我这有新制香火一枝，你拿去贡奉吧。\n");
          who->add("wudang/offerring", -2);
          obn = new("/d/wudang/obj/incense");
          obn->move(who);
        }
      
    }
  else if ( who->query("family/family_name") == "武当派" )
    {
      JOB_SERVER->reward(who, JOB_NAME, rate, rate);
      adjust_rate();
    } else              
      who->add("combat_exp", 1+random(i));
        

  if (who->query("wudang/offerring") > 150)
    who->set("wudang/offerring", 150);

  if (who->query("age") < 20 && who->query("wudang/offerring") < 60)
    who->add("wudang/offerring", 1);
  if (who->query("age") < 30 && who->query("wudang/offerring") < 120)
    who->add("wudang/offerring", 1);
  if (who->query("age") > 30 && who->query("wudang/offerring") < 150)
    who->add("wudang/offerring", 1);

  who->add("wudang/offerring", 1);
  who->add("job/succeed", 1);

  clear_guard_job(who);

  add_temp("stock", -1);
  delete_temp("worker/"+who->query("id"));

  environment(who)->add_temp("worker/"+who->query("id"), 1);
}

int accept_object(object who, object ob)
{

  object obn, wage;     
  int i, j;
  string *wanted;

  /*    if (ob->query("money_id") && ob->value() >= 100*(int)who->query("age") ) 
        {
        if ((string)(who->query("family/family_name")) == "武当派") 
        tell_object(who, "道长哈哈一笑：既然道兄如此诚心向道，"
        +"我这有新制香火一枝，请道兄拿去贡奉吧。\n");
        else 
        tell_object(who, "道长哈哈一笑：既然施主如此诚心向道，"
        +"我这有新制香火一枝，请施主拿去贡奉吧。\n");

        obn = new("/d/wudang/obj/incense");
        obn->move(who);
        return 1;
        } else
        */
  if (ob->query("money_id") )     
    {
      if ((string)(who->query("family/family_name")) == "武当派") 
        tell_object(who, 
                    "道长对你赞叹道：武当山香火鼎盛，全靠象道兄这样捐献香火啊！\n");
      else  
        tell_object(who, 
                    "道长对你赞叹道：武当山香火鼎盛，全靠象您这样的虔诚香客啊！\n");

      //        if (random(ob->value())/50 > who->query("age"))
      //                who->add("wudang/offerring", 1);

      return 1;
    }
        

  return 0;
}


int do_say(string arg)
{
  object ob, who;

  who = this_player();
  ob = this_object();

  if ( arg != "干不了") return 0;

  if ( who->query("job/supervisor") != ob->query("nickname")) return 0;

  message_vision("$N低声说道：道长分派的活我干不了…\n", who);
  command("pat "+ who->query("id"));
  command("say 没关系，下次好好干！");


  // If I didn't assigned you the job, I will just remove your
  // job status but not making any empty slot in my job pool.

  if (query_temp("worker/"+who->query("id"))) {
    ob->add_temp("stock", -1);
    ob->delete_temp("worker/"+who->query("id"));
  }
  who->add("job/fail", 1);
  clear_guard_job(who);
  JOB_SERVER->abort_job(who, "wudang_volunteer");

  return 1;
}


int do_kill(string arg)
{
  int i;
  object me, ob, *inv;  
        
  me = this_player();

  if ( !arg ) return 0;

  ob = present(arg, environment());
        
  if (!objectp(ob)) return 0;
        
  if ( me->query("job/supervisor") == "知客道长" 
       && ob->query("id") == "zhike daozhang" )
    {
      message_vision("$N想杀掉$n。\n"
                     "$n厉声对$N道：你想造反哪？！报酬扣消。\n", me, ob);
      me->set("job/wage", 0);
      return 1;
    }
        
  if ((string)(me->query("family/family_name")) == "武当派" 
      && ob->query("id") == "zhike daozhang" )
    {
      message_vision("$N想杀掉$n。\n"
                     "$n厉声对$N道：你我本同门，却为何想相害于我！\n"
                     "$n对$N很不满意！\n" , me,ob);
                        
      me->add("wudang/offerring", -20);
      return 1;
    }

  if ( ob->query("job/supervisor") == "知客道长" 
       || (ob->query("family/family_name") == "武当派" 
           && ob != this_object()) )
    {
      message_vision("$N想杀掉$n。\n"
                     "知客道长厉声对$N道：武当山上岂能纵容你行凶杀人！来问问我手中长剑是否答应！\n",
                     me, ob);
      command("kill "+me->query("id"));
      return 1;
    }
        
  /***
    inv = all_inventory(environment(ob));
    for(i = 0; i < sizeof(inv); i++)
    if ( userp(inv[i]) && inv[i]->query("job/supervisor") == "知客道长" )  
    ***/
        
  return 0;
}

/*
int return_home(object home) 
{
int i;
mapping worker = query_temp("worker");
string* players;

if ( mapp(worker) && sizeof(worker) ) {
players = keys(worker);
for(i=0; i<sizeof(players); i++) 
if (query_temp("worker/"+players[i])>0)
add_temp("worker/"+players[i], -1);
}

return ::return_home(home);
}
*/

void die()
{
    JOB_SERVER->set_exp_limit("wudang_volunteer", 4000);
    JOB_SERVER->set_pot_limit("wudang_volunteer", 800);
    ::die();
}

int do_quit()
{
	object me = this_player();

        if( (string)me->query("job/description") == "守卫山门" && interactive(me) )
	{
                message_vision("$N对$n喝道：时辰未到，你就想溜！\n", this_object(), me);
		return 1;
	}
	return 0;
}

// End of File
