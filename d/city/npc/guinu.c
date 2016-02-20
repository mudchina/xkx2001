//Cracked by Roath
// npc: /d/city/npc/guinu.c
// Jay 6/25/96

#include <ansi.h>
inherit NPC;

void create()
{
        set_name("龟奴", ({ "guinu", "slave" }) );
        set("gender", "无性" );
	set("title", "丽春院总管");
        set("age", 32);
        set("long", 
	    "他是丽春院里里外外管事的，没有他丽春院就不会有今天的繁荣。"
	    "不过他也干尽了逼良为娼的坏事。此人两膀膂力过人，不好惹。\n");
        set("str", 65);
        set("dex", 35);
        set("con", 25);
        set("int", 25);
        set("shen_type", -1);

        set_skill("unarmed", 60);
	set_skill("force", 20);
        set_skill("dodge", 55);

        set("combat_exp", 95000);

        set("max_qi", 300);
        set("max_jing", 100);
        set("neili", 200);
        set("max_neili", 200);

        set("attitude", "friendly");
        set("inquiry", ([
            "name" : "我也不知道我原来叫什么。",
            "韦小宝" : "那是我们老板娘的儿子。",
            "丽春院" : "我们丽春院可是扬州城里头一份的找乐子去处。",
            "here" : "我们丽春院可是扬州城里头一份的找乐子去处。",
            "赎身" : "那可不行。我们这儿的姑娘是摇钱树。除非你加倍地给我钱。",
	    "从良" : "那可不行。我们这儿的姑娘是摇钱树。除非你加倍地给我钱。",
            "姑娘" : "姑娘就是姑娘，连这都不懂还逛什么窑子。",
	    "服务" : "order <某姑娘> <动作emote> <某人...可省略>。十两白银或更多一次。",
	    "service" : "order <某姑娘> <动作emote> <某人...可省略>。十两白银或更多一次。",
       ]) );

        setup();
        set("chat_chance", 5);
        set("chat_msg", ({
	"龟奴对你说道：客官，你要缺钱花就把你妹妹，女儿什么的卖到我这来吧。\n",
	"龟奴对你说道：卖之前，最好先问问我们老板娘，谁漂亮谁才能卖个好价钱。\n",
	}) );
        carry_object("/d/city/obj/pink_cloth")->wear();
}
void init()
{
        object ob;

        ::init();
        if (interactive(ob = this_player()) && !is_fighting()) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
        add_action("do_sell","sell");
}

void greeting(object me)
{
    object * ob;
    int found,i;
    
    found = 0;
    
    if (me->query("hooker")) {
	command("say 好啊，"+me->name() + "，我还当你要逃到天边呢，你又回来了！");
	command("say 你要再逃我打断你的腿！");
	return;
    }
    if (me->query("gender")!="无性") {
      ob = all_inventory(environment());
      for(i=sizeof(ob)-1; (i>=0) && !found; i--) {
      if( !userp(ob[i]) ) continue;
      if (ob[i]->query("hooker")) {
         found = 1;
         command ("say "+ob[i]->name() + "，看见客人来了还不快迎接！ ");
         command ("kick " + ob[i]->query("id"));
      }
      }   
    }
    return ;
}
int price(object ob)
{
    int per, extra=1;

    per = ob->query("per")*100;
    if( ob->query_temp("top_girl") ) {
	extra = 10 ;
	per = ob->query("per")*1000;
    }
    return (ob->query("combat_exp")+per)*extra;
}

int do_sell(string arg)
{
    object ob;
    int value, p;

    string* name1s = ({
       "小", "春", "夏", "秋", "冬", "月" });
    string* name2s = ({
       "红", "兰", "月", "翠", "莲", "荷", "叶", "花", "蝶" });
    string* name3s = ({
       "姐姐", "妹妹", "姑娘" });
    string nick;
    
    if (!arg || !(ob = present(arg, this_player())))
       return notify_fail("你要卖谁？\n");
       
    if (!ob->is_character())
       return notify_fail("这你得卖到当铺去。\n");
              
    if (!userp(ob))
       return notify_fail("我们只召玩家做妓女。\n");
       
    if (ob->query("gender")!="女性")
       return notify_fail("本院目前还不召男妓。\n");
      
    if (ob->query("hooker"))
       return notify_fail("她已经是我们丽春院的人了，你不能再卖了。\n");
       
    if ((value=ob->query("combat_exp")) < 100)
       return notify_fail("她还是个雏儿呢，我可没工夫教她。\n");

    if( ob->query_temp("top_girl") ) {
	command("admire "+this_player()->query("id"));
	command("say 这次的货色不错，这小妞真不赖！\n");
    }

    message_vision("$N把"+ ob->name()+"卖到了丽春院。\n", this_player());
    MONEY_D->pay_player(this_player(), p=price(ob));
    ob->set("lcy-price", p);
    this_player()->set("shen",this_player()->query("shen")-(value/100));
    this_player()->set("sell_woman/" + ob->query("id"), 1);

    ob->move(this_object());
    nick = name1s[random(sizeof(name1s))] + name2s[random(sizeof(name2s))]
           + name3s[random(sizeof(name3s))];
    if (ob->query("age")<18)       
        ob->set("title","丽春院新人");
    else if (ob->query("age")<25)
        ob->set("title","丽春院头牌");
    else if (ob->query("age")<45)
        ob->set("title","丽春院皇后");
    else ob->set("title","丽春院教师");
    if( ob->query_temp("top_girl") ) {
	ob->set("title",HIR"丽春院花魁"NOR);
	ob->delete_temp("top_girl");
    }
    ob->set("nickname",nick);
    command ("chat 我们丽春院新来了「"+nick+ "」"+ob->name()+"，欢迎各位大爷光顾！");
    ob->set("hooker",1); 
    return 1;
}
 
int accept_object(object me, object obj)
{
  int p;

  p = me->query("lcy-price");
  /* 
   * backward compatibility, for those players who are already hookers before
   * this code is written.  -chu
   */
  if (!p) p = price(me);   

  if(obj->query("money_id")) {
    if(me->query("hooker")) {
        if (obj->value()>= p*2)  {  
        command ("say 好吧，人各有志，你要从良我也不勉强，找个好人家嫁了吧。我们大家会想你的。");
        command ("cry "+me->query("id"));
        me->set("title",me->query("family/family_name")+"第"+
                chinese_number(me->query("family/generation"))+
                "代弟子");
        command("bye "+me->query("id"));
        me->delete("hooker");
        return 1;
        }
        else {
        command("say 谢谢"+me->query("nickname")+"赏钱。");
        command("bow "+ me->query("id"));
        return 1;
        }
    }
    else {
        command("say 谢谢赏钱。");
        command("bow "+ me->query("id"));
	if (obj->value() >= 1000) {
		me->set_temp("money_given",1);
		command("thank " + me->query("id"));
	}
        return 1;
    }
  }
  else return 0;
} 

