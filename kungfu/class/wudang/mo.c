//Cracked by Roath
// shenggu.c 莫声谷
// xQin 6/2000

#include <ansi.h>
inherit	NPC;
inherit F_MASTER;

void init();
int accept_object(object who, object ob);

string ask_me();
string ask_me1();
string ask_me2();

void create()
{
	set_name("莫声谷", ({ "mo shenggu", "mo", "shenggu" }));
	set("nickname",	"武当七侠");
	set("long",
		"这就是张三丰最小的弟子莫声谷。\n"
		"他自幼便少年老成，脾气粗豪直爽，长得魁梧奇伟，满脸的浓髯。\n"
		"武功内外兼修、刚柔合一。\n");
	set("gender", "男性");
	set("age", 35);
	set("attitude",	"peaceful");
	set("shen_type", 1);

	set("neili", 3000);
	set("max_neili", 3000);
	set("jiali", 60);
	set("combat_exp", 700000);
	set("score", 700000);
	set("wudang/raozhi", 1);

	set_skill("force", 185);
	set_skill("taiji-shengong", 150);
	set_skill("dodge", 160);
	set_skill("tiyunzong",	160);
	set_skill("cuff", 150);
	set_skill("strike", 150);
	set_skill("mian-zhang",150);
	set_skill("parry", 150);
	set_skill("sword", 185);
	set_skill("taiji-jian", 170);
	set_skill("throwing", 150);
	set_skill("literate", 120);
	set_skill("taoism", 120);

	map_skill("force", "taiji-shengong");
	map_skill("dodge", "tiyunzong");
	map_skill("cuff", "taiji-quan");
	map_skill("strike", "mian-zhang");
	map_skill("parry", "taiji-jian");
	map_skill("sword", "taiji-jian");

	prepare_skill("cuff", "chang-quan");
	prepare_skill("strike",	"mian-zhang");
	
	set("chat_chance_combat", 50);
	set("chat_msg_combat", ({
		(: perform_action("sword.raozhi") :),
	}) );

	create_family("武当派",	2, "弟子");

	        set("inquiry", ([
                "绕指柔剑" : (: ask_me :),
                "宋青书" : (: ask_me1 :),
                "raozhi" : (: ask_me :),
                "qingshu" : (: ask_me1 :),
		"teach" : (: ask_me2 :),
		"指教" : (: ask_me2 :),
		               
        ]));

	set("chat_chance",6);
        set("chat_msg", ({
            "莫声谷说道: 你知道江湖上的朋友为什么都尊称我们一声武当七侠吗？\n",
            "莫声谷说道: 身为武当弟子应时时以侠义为先，你要切记啊！\n",
            "莫声谷说道: 何为侠义之道？你自己好好想清楚吧。 \n", 	
	    "莫声谷说道: 青书那个畜生不知道躲哪去了，上次在峨嵋真不应该让他逃掉！ \n"	        
            "莫声谷说道: 下次再见到青书一定不能让他再跑了。 \n",	
        }));


	set("first_ask", 1);
	set("set_gocatch", 1);

	setup();
	carry_object("/clone/weapon/changjian")->wield();
	carry_object("/d/wudang/obj/whiterobe")->wear();
}

	
void init()
{
	object ob;
	object me = this_player();
	
	::init();
	
	if(present("qingshu", environment(me))) {
        command("sigh qingshu");
        call_out("qingshustory", 1, ob);
	
}
	
	
	if( interactive(ob = this_player()) && ob->query("family/family_name") == "武当派" )
		call_out("greeting", 1, ob);
}


void greeting(object me)
{
	command("nod " + me->query("id"));
}

string ask_me()
{
        mapping fam; 
        object me, ob, *obs;
        me = this_player();

	
       		                
        if (me->query("can_fight", 1)) 
	   	{
		add_action("do_fight", "fight");
		command ("ok");
		me->delete("can_fight");
		me->set("fight_mo", 1);
		command("fight " + me->query("id"));
		return "既然你帮我抓到了本派叛徒，你我可算有缘，就让我先试试你的身手吧。";
		}
        
        
        if (!(fam = this_player()->query("family")) || fam["family_name"] != "武当派")
                { 
               	command ("brother2");               	
               	return RANK_D->query_respect(this_player()) + 
                "有意要加入我武当派？";
               	}	
		
        if (query("first_ask") < 1)
                {
                command ("smile");	
                return "「绕指柔剑」正是武当派的绝技";
		}
        
  	add("first_ask", -1);
        me->set("know_raozhi", 1);
        command ("hehe");
                return "这路「绕指柔剑」全仗以浑厚内力逼弯剑刃，使剑招闪烁无常，敌人难以挡架。";

	
}



string ask_me1()
{
        mapping fam; 
        object me, ob, qingshu, *obs;
        me = this_player();
        
                      
        
         if (!(fam = this_player()->query("family")) || fam["family_name"] != "武当派")
               { 
               	command ("hmm");               	
               	return RANK_D->query_respect(this_player()) + 
                "， 青书和你是什么关系？";
               	}	
        
        
        
        if (!(fam = this_player()->query("family")) || fam["family_name"] != "武当派")
               	{ 
               	command ("hmm");               	
               	return RANK_D->query_respect(this_player()) + 
                "， 请不要再提那个畜生！";
               	}	
		
        if (query("set_gocatch") < 1)
                {
                command ("hmm");	
                return "我不想再提起那个畜生！";
		}
        
  	add("set_gocatch", -1);
        me->set("set_gocatch", 1);
        command ("sigh ");
        return "上次不小心被那个畜生逃走了，真是师门不幸。只可惜自从上次在峨嵋被他逃走后一直找不到他。";

	
}


int do_fight(string arg)

{
  int i;
  object me, ob, *inv;  
        
  me = this_player();

  if ( !arg ) return 0;

  ob = present(arg, environment());
        
  if (!objectp(ob)) return 0;
        
  if (me->query("fight_mo", 1)) 
        
  
   
     {       
    	    tell_object(HIR "如果你要和莫声谷性命相搏，请你也对这个人下一次 kill 指令。\n" NOR);
            message("vision",
   HIR  "如果你要和莫声谷性命相搏，请你也对这个人下一次 kill 指令。\n"
       "看起来莫声谷想杀死" + me->name() +"\n"
   NOR, environment(), this_object() );
                   fight_ob(this_player());
    
    
      add_action("do_halt", "halt");	
      add_action("do_brother2", "brother2");
      add_action("do_kill", "kill");
      me->delete("fight_mo");
      me->set("brother2_mo", 1);
      me->set("halt_mo", 1);
      
      return 1;
    }

}

int do_halt()
{
  object ob, obj=this_object();
  
  ob = this_player();
        
  
  if ( ob->query("halt_mo", 1) )
    {
      
      ob->delete("brother2_mo");
      ob->delete("halt_mo");
      command("sigh"); 
      command("halt");
      command("say 既然如此，你走吧。 我没有什么好教你的。");

      

 
  return 1;
}	
}


int do_kill(string arg)

{
  int i;
  object me, ob, *inv;  
        
  me = this_player();

  if ( !arg ) return 0;

  ob = present(arg, environment());
        
  if (!objectp(ob)) return 0;
        
        
  if ((string)(me->query("family/family_name")) == "武当派" 
      && ob->query("id") == "mo shenggu" )
    {
      message_vision("$N想杀掉$n。\n"
                     "$n厉声对$N道：你我本同门，却为何想相害于我！\n"
                     "$n厉声对$N道：你别妄想学到「绕指柔剑」！\n"
                     "$n对$N很不满意！\n" , me,ob);
      command ("sigh");
      command ("disapp");
      
      ob->delete("brother2_mo");
      ob->delete("halt_mo");
      me->delete("can_fight");       
      me->add("wudang/offerring", -20);
      return 0;    

}
}

int do_brother2(string arg)

{
  int i;
  object me, ob, *inv;  
        
  me = this_player();

  if ( !arg ) return 0;

  ob = present(arg, environment());
        
  if (!objectp(ob)) return 0;
        
   if (me->query("brother2_mo", 1)) 
        
    {
      ob->delete("brother2_mo");
      ob->delete("halt_mo");
      me->delete("can_fight");
      me->set("can_teach", 1);   
      
      
      command ("say 身为武当弟子，当以侠义为先，你虽入门颇晚，但武艺不凡。");
      command ("say 更难得你心存仁念，实属吾道中人，希望你好自为之，将武当发扬光大。");
      command ("halt");
      command ("touch");
      command ("thumb");
      
      return 0;	
}
}
int accept_object(object who, object ob)
{
	object obn;

	
	if ( !who || environment(who) != environment() ) return 0;
	if ( !objectp(ob) ) return 0; 
	if ( !present(ob, who) ) return notify_fail("你没有这件东西。");
	if (who->query("know_raozhi") < 1) 
	return notify_fail("你这么把青书弄成这样了！");
	if (who->query("set_gocatch") < 1) 
	return notify_fail("你想干什么？");
	if (  (string)ob->query("name") == "qingshu"
		|| (string)ob->query("name") == "宋青书"  ) 
	{
		if ( (string)ob->query("name") == "宋青书" )
	{		
	who->delete("set_gocatch");
        who->add("can_fight", 1);
        who->add("wudang/offerring", 10);
        command	("thumb");
	command("touch " + (string)who->query("id")); 
        ob->move(this_object());
        if ( ob) destruct(ob);
	command("say" + RANK_D->query_respect(who)
	       	+ "谢谢你帮我抓到了这个叛徒。 \n");
		}
	return 1;
	}
        command("? " + who->query("id"));
        
        
        return 0;
}



string ask_me2()
{
        mapping fam; 
        object me, ob, qingshu, *obs;
        me = this_player();
        
                      
        
         
        
        
        if ((int)me->query("can_teach", 1) < 1)
		{
		command ("hmm");
		return "你想请教什么？";
		}
		
	if ((int)me->query_skill("sword", 1) < 180)	
                {
                me->delete("can_teach");
                command ("hmm");	
                return "你的剑法功力太浅，不适宜学「绕指柔剑」";
		}
	
	if ((int)me->query_skill("force", 1) < 180)	
                {
                me->delete("can_teach");
                command ("hmm");	
                return "你的内功火候太浅，不适宜学「绕指柔剑」";
		}
        
  	
  	
  		me->set("wudang/raozhi", 1); 
      		me->add("wudang/offerring", 10);        
       		me->delete("can_teach");
      		command ("ok");
       		command ("say" + "你的知质品性深的我心，若你要学我就把「绕指柔剑」传授于你吧！\n");
       		message("vision", HIW  "恭喜你学会了「绕指柔剑」！\n" NOR, me,ob);
         	return 0;         
  	
	
}

