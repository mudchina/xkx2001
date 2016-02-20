// /d/lingjiu/npc/tbzhu.c 朱天部 石嫂
// By adx @ CuteRabbit 22:21 99-3-19

#include <ansi.h>

inherit NPC;
inherit F_MASTER;
int auto_perform();
void greeting(object);
void init();
void create()
{
	set_name("石嫂", ({ "shi sao", "shi", "sao" }));
	set("long",
	    "她是「灵鹫宫」九天九部中朱天部的首领.\n"+
	    "她跟随童姥多年, 出生入死,饱经风霜.\n");
	set("title", "朱天部首领");
	set("gender", "女性");
	set("age", 30);
	set("shen_type",0);
	set("attitude", "peaceful");

	set("per", 22);
	set("class", "scholar");
	set("str", 25);
	set("int", 25);
	set("con", 30);
	set("dex", 30);

	set("qi", 1300);
	set("max_qi", 1300);
	set("jing", 500);
	set("max_jing", 500);
	set("neili", 2000);
	set("max_neili", 2000);
	set("jiali", 30);

	set("combat_exp", 500000);
	set_skill("force", 100);
	set_skill("dodge", 100);
	set_skill("parry", 100);
	set_skill("hand",100);
	set_skill("strike", 100);
	set_skill("sword",100);
	set_skill("literate",100);
	set_skill("music",100);

	set_skill("zhemei-shou",100);
	set_skill("liuyang-zhang",100);
	set_skill("tianyu-qijian",100);
	set_skill("yueying-wubu",100);
	set_skill("bahuang-gong", 100);

	map_skill("force", "bahuang-gong");
	map_skill("strike","liuyang-zhang");
	map_skill("dodge", "yueying-wubu");
	map_skill("hand", "zhemei-shou");
	map_skill("parry", "liuyang-zhang");
	map_skill("sword", "tianyu-qijian");

	prepare_skill("strike","liuyang-zhang");
	prepare_skill("hand","zhemei-shou");

        set("inquiry", ([
	"灵鹫宫" : "这里就是。\n",
	"童姥" : "她是灵鹫宫的主人。\n",
	"尊主" : "灵鹫宫现在的尊主是虚竹，他是灵鹫宫唯一的男子。\n",
	"生死符" : "你今年给本宫的贡金呢？\n",
        ]));

	prepare_skill("strike","liuyang-zhang");
	prepare_skill("hand","zhemei-shou");
	create_family("灵鹫宫",4,"弟子");
        set("chat_chance_combat", 50);
        set("chat_msg_combat", ({
                (: auto_perform :),
        }) );
	setup();
 	carry_object("/clone/weapon/changjian")->wield();
 	carry_object("/d/lingjiu/obj/qingyi")->wear();
        carry_object("/d/lingjiu/obj/doupeng")->wear();
        add_money("silver",25);
}
void init()
{
        object ob;
 
        ::init();
 
        if( interactive(ob = this_player()) && !is_fighting() ) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
}
void greeting(object ob)
{
       if ((string)ob->query("family/family_name") == "灵鹫宫") 
	{
               message_vision("石嫂冲着$N点点头，微微笑了笑。\n",ob);
               return;
	}
        if (!(string)ob->query("family/family_name"))
	{
               message_vision("石嫂冲着$N微笑说：你是来拜师的吧，拜我吧。\n",ob);
               return;
	}
}

int accept_object(object me, object ob)
{
	object qing;

        if( ob->query("money_id") ) 
	{
		if(ob->value() < 1000000)
		{
			command("heng");
			command("say 你打发叫化子啊！滚！");
			return 1;
		}
		else
		{
			this_player()->apply_condition("zf_poison", 0);
			command("say 好，你身上的生死符已解了！");
			command("say 下次给本宫的贡金一定要准时！");
			return 1;
		}
	}
}
#include "/kungfu/class/lingjiu/tianbu.h"
#include "/kungfu/class/lingjiu/auto_perform.h"