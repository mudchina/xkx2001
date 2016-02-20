//Cracked by Roath
// /emei/ding.c 丁敏君
// xQin: 99/08/14

inherit NPC;
inherit F_MASTER;

int auto_perform();
void create()
{
        set_name("丁敏君", ({ "ding minjun", "ding", "minjun" }));
        set("long", 
                "她是灭绝师太的八大俗家第子之一。\n"
                "她高挑身材，面貌甚美，可惜颧骨微高，嘴非樱桃小口，\n"
                "皮色也不够白皙。\n");
        set("gender", "女性");
        set("age", 35);
        set("attitude", "peaceful");
        set("shen_type", 1);

        set("str", 25);
        set("int", 20);
        set("con", 20);
        set("dex", 25);
        
        set("max_qi", 1100);
        set("max_jing", 1100);
        set("neili", 1800);
        set("jiali", 60);
        set("max_neili", 1800);

        set("combat_exp", 300000);
        
	set_skill("force", 125);
  	set_skill("linji-zhuang", 125);
  	set_skill("throwing", 125);
  	set_skill("strike", 125);
  	set_skill("jinding-zhang", 125);
  	set_skill("hand", 125);
  	set_skill("jiushou-jiushi", 125);
  	set_skill("sword", 125);
  	set_skill("emei-jian", 125);
  	set_skill("blade", 125);
  	set_skill("yanxing-dao", 125);
  	set_skill("parry", 125);
  	set_skill("dodge", 125);
  	set_skill("zhutian-bu", 125);
//	set_skill("literate", 80);
  	set_skill("persuading", 100);
  	set_skill("mahayana", 100);

  	map_skill("force", "linji-zhuang");
  	map_skill("strike", "jinding-zhang");
  	map_skill("hand", "jieshou-jiushi");
  	map_skill("sword", "emei-jian");
  	map_skill("blade", "yanxing-dao");
  	map_skill("parry", "emei-jian");
  	map_skill("dodge", "zhutian-bu");
	
  	prepare_skill("strike", "jinding-zhang");
  	prepare_skill("hand", "jieshou-jiushi");

        create_family("峨嵋派", 4, "弟子");
        set("chat_chance_combat", 50);
        set("chat_msg_combat", ({
                (: auto_perform :),
        }) );

        set("inquiry", ([
                "出家" : "你去本山的庵堂里找我静字辈师姐吧。她们在福寿庵、千佛庵、\n万年庵、万行庵和卧云庵修行。\n",
            "灭绝师太" : "她是本派掌门人，在华藏庵修行。\n",
        ]));

        setup();
        carry_object("/clone/weapon/changjian")->wield();
        carry_object("/d/emei/npc/obj/hui-cloth")->wear();
        carry_object("/d/emei/npc/obj/emei-shoes")->wear();

}

#include "/kungfu/class/emei/sujia.h"
#include "/kungfu/class/emei/auto_perform.h"
