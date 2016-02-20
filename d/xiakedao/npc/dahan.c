//Cracked by Roath
// dahan.c 黄衣大汉
// Long, 6/13/97
// xQin 7/00 cut sheyao

#include <ansi.h>

inherit NPC;

int ask_leave();
int ask_weapon();
int ask_armor();
void greeting(object);

string* armors = ({
        "/clone/armor/beixin",
        "/clone/armor/tie-beixin",
});

string* weapons = ({
        "/clone/weapon/caidao",
        "/clone/weapon/changjian",
        "/clone/weapon/duanjian",
});

void create()
{
        set_name("黄衣大汉", ({ "da han", "han"}));
        set("long", "他身材魁武，看过去像一座小山似的。\n");
        set("gender", "男性");
        set("age", 30);
        set("attitude", "peaceful");
        set("shen_type", 1);
        set("str", 30);
        set("int", 25);
        set("con", 25);
        set("dex", 25);
        set("race", "人类");    
        set("max_qi", 200);
        set("eff_qi", 200);
        set("qi", 200);
        set("max_jing", 200);
        set("eff_jing", 200);
        set("jing", 200);
        set("max_neili", 200);
        set("eff_neili", 200);
        set("neili", 200);
        set("max_jingli", 200);
        set("eff_jingli", 200);
        set("jingli", 200);
        set("combat_exp", 50000);
        set("score", 1000);

        set_skill("force", 70);
        set_skill("dodge", 70);
        set_skill("parry", 70);
        set_skill("cuff", 70);
        set_skill("sword", 70);
        
        set("inquiry", ([
                        "武器"   :  (: ask_weapon :),
                        "防具"   :  (: ask_armor :),
                        "中原"   :      (: ask_leave :),
                        "岛主"   :      "岛主好象在洞里。\n",
        "买"     :  "岛上没有什麽店铺。你回到中原时要什麽东西可到店里买。\n",
        "卖"     :  "岛上也没有当铺。中原的几个大城镇都有当铺，没用的东西可以卖掉。\n",
                ]));
        set("armor_count", 50);
        set("weapon_count", 50);
        setup();
}

void init()
{
        object me = this_player();        

        ::init();

        if( interactive(me) )
        {
                remove_call_out("greeting");
                call_out("greeting", 1, me);
        }
}

void greeting(object me)
{       object sheyao;
        object weapon, armor;
        string whattosay;
        int count = 0, i;

        if (me->query_temp(this_object()->query("id")) == 0 )
        {       command(":) "+ me->query("id") );
                whattosay = 
"
             这位"+RANK_D->query_respect(me) + 
          "走山路或野路时要小心野兽，老虎和毒蛇
     见人就咬的。刀，剑，石块或树枝都可以用来加强你的攻击力。
     还有你可以找些东西来穿，狗皮，牛皮，皮背心，或铁甲等等，
     这些都可以增加你的防御能力。";
                command("say " + whattosay);
                me->set_temp(this_object()->query("id"), 1);
        }
        for( i = 0; i < sizeof(weapons); i++ )
        {       if (  weapon = present(weapons[i]->query("id"), me) )
                {       if (weapon->query("equipped") == 0)
                        {       command ("say" + RANK_D->query_respect(me) + "快把你带的" + 
                                        weapon->query("name") + "装备起来吧。\n" +
                                        HBRED+HIW"(wield " + weapon->query("id") + ")"NOR + "。");
                        }
                        count = count + 1;
                }
        }
        if (count == 0 ) 
        {       command("say 我这里正好有几件兵器，你要的话就告诉我。\n" + 
                HBRED+HIW"(ask han about 武器)"NOR+ "。");
        }
        count = 0;
        for( i = 0; i < sizeof(armors); i++ )
        {       if (  armor = present(armors[i]->query("id"), me) )
                {       if (armor->query("equipped") == 0)
                        {       say("黄衣大汉说道：" + RANK_D->query_respect(me) + "快把你带的" + 
                                        armor->query("name") + "装备起来吧。"+ 
                                        HBRED+HIW"(wear " + armor->query("id") + ")"NOR +"。\n");
                        }
                        count = count + 1;
                }
        }

	if (count == 0)
        {       command("say 我这好象也还有一两件防具，要就问我要吧。\n" +
                        HBRED+HIW"(ask han about 防具)"NOR +"。");
        }
//        if (  present("she yao", me) )
//	{	say("黄衣大汉皱了皱眉头说道：赶快把蛇要服下。\n");
//	} 
//	else if (present("she yao", environment(me)))
//	{	say("黄衣大汉皱了皱眉头说道：赶快把蛇要服下。\n");
//	}
       // count = (int)me->query_condition("snake_poison");
       // if ( count > 0)
       // {       command("say 唉呀，你被毒蛇咬了，我这正好有些蛇药，快服下吧。\n" +
         //       HBRED+HIW"(fu sheyao)"NOR);
          //      count = count / 5 + 1;
           //     for (i = 0; i < count; i++ )
             //   {       
			//	sheyao = new("/clone/drug/sheyao.c");
			//	sheyao->move(this_object());
//		command("give " + sheyao->query("id") + " to " + me->query("id"));
//                }
//        }
}
int ask_leave()
{       
        say("黄衣大汉摇了摇头说道：没有岛主同意，你可不能私自离岛。\n");
        return 1;
}
int ask_weapon()
{       int i;
        object you = this_player();
        object weapon;
        if (query("weapon_count") < 1)
        {       say("黄衣大汉低头在身上翻了半天，抱歉地笑了笑说道，对不起，没了。\n");
                return 1;
        }
        
        for( i = 1; i < sizeof(weapons); i++ )
        {       if (  present(weapons[i]->query("id"), you) )
                {       say("黄衣大汉皱了皱眉头说道：有了还要，你太贪心了吧。\n");
                        return 1;
                }
                else if (present(weapons[i]->query("id"), environment(you)))
                {       say("黄衣大汉往地上一指：地上不是有吗，你要的话就捡走吧。\n");
                        return 1;
                }
        }
        weapon = new(weapons[random(sizeof(weapons))] );
        weapon->set("value", 0);
        weapon->move(this_object());
//      command("say " + weapon->query("id") + " to " + you->query("id"));
        command("give " + weapon->query("id") + " to " + you->query("id"));
//      say("黄衣大汉从身上找出一" + weapon->query("unit") + weapon->query("name") + "，递了给你。\n");
//      weapon->move(you);
        add("weapon_count", -1);
        return 1;
}
int ask_armor()
{       int i;
        object you = this_player();
        object armor;
        if (query("armor_count") < 1)
        {       say("黄衣大汉低头在身上翻了半天，抱歉地笑了笑说道，对不起，没了。\n");
                return 1;
        }
        for( i = 1; i < sizeof(armors); i++ )
        {       if (  present(armors[i]->query("id"), you) )
                {       say("黄衣大汉皱了皱眉头说道：有了还要，你太贪心了吧。\n");
                        return 1;
                }
                else if (present(armors[i]->query("id"), environment(you)))
                {       say("黄衣大汉往地上一指：地上不是有吗，你要的话就捡走吧。\n");
                        return 1;
                }
        }
        armor = new( armors[random(sizeof(armors))] );
        armor->move(this_object());
        armor->set("value", 0);
        command("give " + armor->query("id") + " to " + you->query("id"));
        }
