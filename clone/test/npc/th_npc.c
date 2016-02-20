//Cracked by Roath
// Kane,
// maco

inherit NPC;
#include <ansi.h>
int auto_perform();

int unarmed();
int sword();
int finger();
int strike();
int hand();
int no_play();
int play();

string* xuedao = ({
        "风池穴", "风府穴", "强间穴", "大椎穴", "至阳穴",
        "百会穴", "灵台穴", "太阳穴", "膻中穴", "命门穴",
});

void create()
{
	set_name("黄药师", ({ "huang yaoshi", "huang" }));
	set("title", "桃花岛主");
	set("nickname", "东邪");
	set("long",
"他就是名震天下的桃花岛主「东邪」黄药师，但见他形相清癯，\n"
"丰资秀爽，湛然若神。一袭青袍，领后插着一支玉箫，神色之间\n"
"大有一股落拓山林的逸气。\n");
	set("gender", "男性");
	set("age", 65);
	set("attitude", "peaceful");
	set("shen_type", 0);
	set("str", 20);
	set("int", 20);
	set("con", 20);
	set("dex", 25);

	set("neili", 8000);
	set("max_neili", 8000);
    set("eff_jingli", 5000);
    set("max_jingli", 5000);
	set("jiali", 200);
	set("combat_exp", 6400000);
	set("score", 5000);
	set("th_jianyi", 1);

	set_skill("force", 400);
	set_skill("dodge", 400);
	set_skill("parry", 400);
	set_skill("sword", 400);
	set_skill("whip", 400);
	set_skill("qimen-dunjia", 400);
	set_skill("strike", 400);
	set_skill("hand",400);
	set_skill("finger", 400);
	set_skill("yuxiao-jian", 400);
	set_skill("canglang-bian", 400);
	set_skill("bitao-xuangong", 400);
	set_skill("luoying-shenjian",400);
	set_skill("luoying-shenfa", 400);
	set_skill("kick", 400);
	set_skill("xuanfeng-saoye", 400);
	set_skill("lanhua-fuxue", 400);
	set_skill("tanzhi-shentong", 400);
	set_skill("throwing", 400);
	set_skill("literate", 400);
	set_skill("music", 400);

	map_skill("force", "bitao-xuangong");
	map_skill("parry", "tanzhi-shentong");
	map_skill("sword", "yuxiao-jian");
	map_skill("finger", "tanzhi-shentong");
	map_skill("strike", "luoying-shenjian");
	map_skill("dodge", "luoying-shenfa");
	map_skill("kick", "xuanfeng-saoye");
	map_skill("hand", "lanhua-fuxue");

	prepare_skill("strike", "luoying-shenjian");
	prepare_skill("kick", "xuanfeng-saoye");
	
	set("chat_chance_combat", 40);
	set("chat_msg_combat", ({
		(: auto_perform :),
	}) );

	create_family("桃花岛", 1, "掌门人");

	set("inquiry", ([ 
                "unarmed"   : (: unarmed :),
                "sword"    : (: sword :),
                "finger"    : (: finger :),
                "hand"    : (: hand :),
                "strike"    : (: strike :),
                "play"    : (: play :),
                "no_play"    : (: no_play :),
	]));

	setup();
	carry_object("/d/xixia/obj/robe")->wear();
	carry_object("/d/taohua/obj/tiexiao"); 
}

void init()
{
	object ob;
	
}

int unarmed()
{
	command("unwield xiao");
	map_skill("parry", "luoying-shenjian");
	return 1;
}

int sword()
{
	command("wield xiao");
	map_skill("parry", "yuxiao-jian");
	return 1;
}

int finger()
{
	command("bei none");
	prepare_skill("finger", "tanzhi-shentong");
	map_skill("parry", "tanzhi-shentong");
	return 1;
}

int strike()
{
	command("bei none");
	prepare_skill("strike", "luoying-shenjian");
	prepare_skill("kick", "xuanfeng-saoye");
	map_skill("parry", "luoying-shenjian");
	return 1;
}

int hand()
{
	command("bei none");
	prepare_skill("hand", "lanhua-fuxue");
	map_skill("parry", "lanhua-fuxue");
	return 1;
}

int no_play()
{
	set("play",0);
	return 1;
}

int play()
{
	set("play",100);
	command("play");
	return 1;
}


int accept_kill(object me)
{
        kill_ob(me);
	    command("exert wuzhuan");
        return 1;
}

#include "/kungfu/class/taohua/auto_perform.h"
