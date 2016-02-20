//Cracked by Kafei
// mux.c 侠客岛赵大
// Long, 6/13/97

#include <ansi.h>

inherit NPC;
string* whattotell = ({
	" 你已经签好名了，下去休息会吧。呆会查下你的电子信箱好啦。",
	" 快点过来挂个名吧。",
	" 你在那干嘛，我没法整天陪你。", 
	" 签不签啊。", 
	" 发呆呀你。", 
	" 再不签，我可要走了。", 
	" 来快签名，签了名我给你糖吃。", 	
});

int ask_leave();
int ask_food();
int ask_daozhu();
void greeting(object);
void checking();
string* fname = ({
	"yi","er", "san", "si", "wu", "liu", "qi", "ba", "jiu",
});

void create()
{	int i = random(8)+1;
	
	set_name("木老" + chinese_number(i), ({ "mu lao" + fname[i-1], "mu"}));
	set("long", "
他身材削瘦，头却奇大，看过去就像一根细竹杆顶着一个大西瓜。他
样子虽滑稽，但一脸的肃容，吓得你不敢笑出来。\n");
	set("nickname", "登记使");
	set("gender", "男性");
	set("age", random(50) + 30);
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
      object me = this_player();
      add_action("do_register", "register");
	::init();
      if( interactive(me) )
      {	remove_call_out("greeting");
            call_out("greeting", 1, me);
	}
//	remove_call_out("checking");
//	call_out("checking", 30);
}

void greeting(object me)
{	command("say 这是侠客岛的挂名室，来到侠客岛上先要在这里报个名。\n" + 
	"    这个月轮到我在这当班。请到这边来登个记吧，登记的指令：\n" +
 "    " + HBGRN+HIW"register 後跟着是你完整及真实的 email (可以是bbs email)，\n"NOR +
"		"+ BRED+HIW"(register xxxxx@yyyy.zzz)\n"NOR+
     CYN"    千万不能有错，否则后果自负。");
	me->set_temp("xkd/sign", 1);
}
void checking()
{	object *players;
	object me = this_object();
	int count;
	int times;
	players = all_inventory(environment(me));
	for (count = 0 ; count <sizeof(players); count ++)
	{	if ((string)players[count]->query("race") == "人类"  && players[count] != me )
		{	if (players[count]->query_temp("registered"))
			{	command("tell " + players[count]->query("id") + whattotell[0]);
			}
			else
			{
				times = (int)players[count]->query_temp("xkd/sign");
				//command("say " + (string)times + ", " + (string)sizeof(whattotell));
				if (times >= sizeof(whattotell)-1)
				{	times = 1;			}
				else
				{	times = times + 1;	}
				command("tell " + players[count]->query("id") + whattotell[times]);
				players[count]->set_temp("xkd/sign", times);
			}
		}
	}
	remove_call_out("checking");
	call_out("checking", 15);
	return;
}
int check_register(object ob)
{
        if (!ob->is_character())
                return notify_fail("你好像不是大活人耶！\n");
        if (!ob->query("id"))
                return notify_fail("你的代号是什么？\n");
        if (!ob->query("name") || strsrch(ob->query("name"), "客人") != -1)
                return notify_fail("你的中文名字是什么？\n");
        if (!ob->query("gender"))
                return notify_fail("你的性别是什么？\n");
        return 1;
}

int do_register(string arg)
{
	object ob;
	string pass;
	int bid;
        
                
      if (!check_register(this_player()))
      	return 0;

	if (!arg)
		return notify_fail("您的电子邮件地址是什么？\n");
	bid = REGI_D->is_banned_email(arg);
	if (bid > 1)
		return notify_fail("您说的电子邮件地址已被查封了。\n");
	if (bid > 0)
		return notify_fail("请输入正确的电子邮件地址。\n");
	if (!(ob = this_player()->query_temp("link_ob")))
		return notify_fail("您的帐号出了些问题，速向巫师求救。\n");
      if (this_object()->query_temp("iambusy"))
              return notify_fail("别急别急，一个一个来……\n");

	this_object()->set_temp("iambusy", 1);
	ob->set("name", this_player()->query("name"));
	ob->save();
	REGI_D->register_char(this_player()->query("id"), arg);
//	this_player()->delete_temp("xkd/sign");
//	this_player()->set_temp("registered", 1);
	this_object()->delete_temp("iambusy");
	return 1;
}
