//Cracked by Roath
// Npc: /d/shaolin/npc/shaofan-seng.c
// Date: YZC 96/01/19
// modified by xiaojian on Aug.20,2000
#include "/d/shaolin/npc/tiaoshui2.h"
inherit NPC;

void reward_dest(object me,object obj);
void destroy_tool(object me,object obj);
void destroy_dest(object me,object obj);
string ask_piao();
string ask_tong();
void create()
{
        set_name("烧饭僧", ({
                "shaofan seng",
                "shaofan",
                "seng",
        }));
        set("long",
                "这是位胖胖的中年僧人，大概是因为长年烧饭作菜的缘故，才如此发福的吧。\n"
        );


        set("gender", "男性");
        set("attitude", "peaceful");
        set("class", "bonze");

        set("age", 44);
        set("shen_type", 1);
        set("str", 20);
        set("int", 20);
        set("con", 20);
        set("dex", 20);
        set("max_qi", 400);
        set("max_jing", 200);
        set("neili", 100);
        set("max_neili", 100);
        set("jiali", 10);
        set("combat_exp", 2000);
        set("score", 100);

        set_skill("force", 12);
        set_skill("dodge", 12);
        set_skill("unarmed", 12);
        set_skill("parry", 12);
      set("inquiry", ([
                "here" : "这里是少林寺的厨房。\n",
                "水桶" : (: ask_tong:),
                "tong": (: ask_tong :),
            "水瓢" : (: ask_piao:),
                "piao": (: ask_piao :),
                  ]) );
        setup();

}

private void go_home()
{

        if( !living(this_object()) ) return;
        message_vision("$N神色慌张地离开了。\n", this_object());
        this_object()->move("/d/shaolin/chufang");
        message_vision("$N快步走了过来。\n", this_object());
}
        



void init()
{
     if( environment() != load_object("/d/shaolin/chufang") ) 
                {
                remove_call_out("go_home");
                call_out("go_home", 1);
        }
}