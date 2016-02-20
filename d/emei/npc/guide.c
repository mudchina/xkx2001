//Cracked by Roath
// 15th-Sep-2000: yasuko
#include <ansi.h>
inherit NPC;

string ask_job_begin();
string ask_job_finish();

void create()
{
        int i;
        i=random(2);
        set_name("俗家弟子", ({ "sujia dizi", "guide"}));
        if (i==0) {
	        set("long", 
		        "这是一名峨嵋派俗家女弟子。\n"
		"只见她怯生生的，一副弱不禁风的样子。\n");
        	set("gender", "女性");
        }
        if (i==1) {
	        set("long", 
		        "这是一名峨嵋派俗家男弟子。\n"
		"却见他眉清目秀，举止甚是斯文。\n");
        	set("gender", "男性");
        }
        set("age", 14);
	set("attitude", "peaceful");

   	set("str", 30);
	set("int", 30);
  	set("con", 30);
	set("dex", 30);
	set("kar", 20);
	set("per", 20);
	
	set("max_qi", 400);
	set("max_jing", 400);
	set("combat_exp", 0);
	set("inquiry", ([
	    "出发" : (: ask_job_begin :),
	    "结束" : (: ask_job_finish :),
	]));
        i=this_player()->query("family/generation");
        create_family("峨嵋派", i, "弟子");
	setup();
	carry_object("/d/emei/npc/obj/hui-cloth")->wear();
}
