//Cracked by Roath
// mizheng.c 兵部尚书
// 负责京畿武官，皇宫侍卫的赏罚，记录，升迁，降级等	-chu

#include <ansi.h>
#ifndef NPCDATA
#define NPCDATA "/data/npc/"
#endif

inherit NPC;
inherit F_SAVE;

string do_toujun();
string do_tuiyi();
string do_shengqian();

void create()
{
    seteuid(getuid());
    if (! restore()) {
	set_name("米正", ({"mi zheng", "mi"}));
	set("title", "兵部尚书");
	set("gender", "男性");
	set("age", 30);
	set("long", "他就是当今朝廷的兵部尚书，\n"
	"京畿侍卫，武官的升迁就全看他了。\n");
	set("attitude","heroism");
	set("generation",0);

	set("max_qi",800);
	set("eff_qi",800);
	set("qi",800);
	set("max_jing",300);
	set("jing",300);
	set("shen_type",1);
	set("no_clean_up",1);
	set("combat_exp",20000);

	setup();
	carry_object("/d/city/obj/cloth")->wear();
	save();
    }
}

int init()
{
	set("inquiry", ([
	"随从" : "这个你去问军营的多总管吧。\n",
	"任务" : "这个你去问军营的多总管吧。\n",
	"投军" : (: do_toujun :),
	"升迁" : (: do_shengqian :),
	"退役" : (: do_tuiyi :),
	]));
}

string query_save_file()
{
    return NPCDATA+"mizheng";
}

string do_shengqian()
{
    return "等等";
}

string do_tuiyi()
{
    return "等等";
}

string do_toujun()
{
    return "等等";
}
