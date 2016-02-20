//Cracked by Roath
int ask_me();

inherit NPC;

void create()
{
	set_name("叶二娘", ({ "ye erniang", "ye", "erniang"}));
	set("nickname", "无恶不作");
	set("long", 
"一个中年女子，身穿淡青色长袍，左右脸颊上各有三条血痕。\n");
	set("gender", "女性");
	set("age", 45);
	set("attitude", "heroism");
	set("shen_type", -1);
	set("str", 30);
	set("int", 30);
	set("con", 30);
	set("dex", 30);
	set("max_qi", 1000);
	set("max_jing",1000);
	set("neili", 1500);
	set("max_neili", 1500);
	set("jiali", 50);
	set("combat_exp", 800000);
	set("chat_chance_combat", 15);
        set("chat_msg_combat", ({
                "叶二娘突然轻轻地对你说道：乖孩子，别哭，我是你妈。\n",
                "叶二娘突然唱了起来：摇摇摇，摇到外婆桥。。。。\n"
        }) );

	 set("inquiry", ([
        "测试" : (: ask_me :),
        "测试武功" : (: ask_me :),
        ]));

	set_temp("apply/armor", 50);
	set_skill("force", 160);
	set_skill("dodge", 160);
	set_skill("parry", 160);
	set_skill("ding-dodge", 160);
	set_skill("ding-force", 160);
	set_skill("ding-unarmed", 160);
	set_skill("liangyi-dao", 170);
	set_skill("strike", 160);
	set_skill("blade", 170);

	map_skill("dodge", "ding-dodge");
        map_skill("force", "ding-force");
        map_skill("unarmed", "ding-unarmed");
	map_skill("blade", "liangyi-dao");
	map_skill("parry", "liangyi-dao");

	setup();
	carry_object("/d/xixia/obj/liuyedao")->wield();
	carry_object("/d/xixia/obj/robe")->wear();
}
void init()
{
        ::init();
        add_action("do_accept", "accept");
}

int ask_me()
{
	object me=this_player();
if ((int)me->query_temp("marks/西夏ye")) 
        {
say("叶二娘笑盈盈的看了看你，这地方没有白胖孩儿,你要是想试就试试(accept
test)吧，打死了你，为娘的可心疼啊！\n");
       return 1;
        }
/* else {

say("南海鳄神怒喝道：滚，老子心烦，不滚看老子一下拧断你的脖子！\n");
        return 1;
        }
*/
}

int do_accept(string arg)
{
	object me=this_player();
        mapping guild;
	if (!(int)me->query_temp("marks/西夏ye"))
	return notify_fail ("你瞎试什么？\n");
	
        if( arg== "test" ) {
                say("\叶二娘点了点头，说道：很好，这是第一招....\n\n");
                COMBAT_D->do_attack(this_object(), this_player(),
query_temp("weapon"));
COMBAT_D->do_attack(this_object(), this_player(),
query_temp("weapon"));

               if( (int)this_player()->query("qi") < 0 
                || !present(this_player(), environment())) {

say("叶二娘叹了口气，说道：连第一招都撑不过，真是自不量力....\n");
                        return 1;
                }
                say("\n叶二娘说道：这是第二招....\n\n");
                COMBAT_D->do_attack(this_object(), this_player(),
query_temp("weapon"));
COMBAT_D->do_attack(this_object(), this_player(),
query_temp("weapon"));

                if( (int)this_player()->query("qi") < 0 
                || !present(this_player(), environment())) {

say("叶二娘「哼」地一声，说道：便是有这许多不怕死的家伙....\n");
return 1;
                }
                say("\n叶二娘说道：第三招来了....\n\n");
                COMBAT_D->do_attack(this_object(), this_player(),
query_temp("weapon"));
                COMBAT_D->do_attack(this_object(), this_player(),
query_temp("weapon"));

                if( (int)this_player()->query("qi") < 0 
                || !present(this_player(), environment())) {

say("叶二娘叹道：乖孩儿，为娘的舍不得杀你啊...\n");
                        return 1;
                }

say("\n叶二娘尖声说道：孩儿啊，你真是长出息了...\n");
                this_player()->set_temp("xixia/testpass", 2);
                this_player()->delete_temp("marks/西夏ye");
                return 1;
        }
        return 0;
}

