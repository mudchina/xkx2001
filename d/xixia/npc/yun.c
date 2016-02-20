//Cracked by Roath
int ask_me();

inherit NPC;

void create()
{
	set_name("云中鹤", ({ "yun zhonghe", "yun", "zhonghe"}));
	set("nickname", "穷凶极恶");
	set("long", 
"此人身材极高，却又极瘦，便似是根竹竿，一张脸长得极是凶恶。\n");
	set("gender", "男性");
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
	set("env/wimpy", 40);
	set("combat_exp", 700000);
	set("chat_chance_combat", 15);
	set("chat_msg_combat", ({
                "云中鹤身形飘逸，窜纵之势迅捷异常。\n"
        }) );

 set("inquiry", ([
        "测试" : (: ask_me :),
        "测试武功" : (: ask_me :),
        ]));

	set_temp("apply/armor", 50);

	set_skill("force", 140);
	set_skill("dodge", 180);
	set_skill("ding-dodge", 180);
	set_skill("ding-force", 140);
	set_skill("ding-unarmed", 140);
	set_skill("parry", 140);
	set_skill("unarmed", 140);
	set_skill("san-sword", 150);
	set_skill("pike", 140);

	map_skill("dodge", "ding-dodge");
        map_skill("force", "ding-force");
        map_skill("unarmed", "ding-unarmed");
	map_skill("pike", "san-sword");

	setup();
	carry_object("/d/xixia/obj/gangzhua")->wield();
	carry_object("/d/city/obj/cloth")->wear();
}
void init()
{
        ::init();
        add_action("do_accept", "accept");
}


int ask_me()
{
object me=this_player();
if ((int)me->query_temp("marks/西夏yun")) 
        {
say("云中鹤看了看你，啐了一口：奶奶的，这鬼地方没个漂亮小娘儿，就试试(accept
test)，看老子不宰了你？\n");
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

if (!(int)me->query_temp("marks/西夏yun"))
 return notify_fail ("你瞎试什么？\n");

        if( arg== "test" ) {
                say("\n云中鹤点了点头，说道：很好，这是第一招....\n\n");
                COMBAT_D->do_attack(this_object(), this_player(),
query_temp("weapon"));
COMBAT_D->do_attack(this_object(), this_player(),
query_temp("weapon"));

                if( (int)this_player()->query("qi") < 0 
                || !present(this_player(), environment())) {

say("云中鹤叹了口气，说道：连第一招都撑不过，真是自不量力....\n");
                        return 1;
                }
                say("\n云中鹤说道：这是第二招....\n\n");
                COMBAT_D->do_attack(this_object(), this_player(),
query_temp("weapon"));
COMBAT_D->do_attack(this_object(), this_player(),
query_temp("weapon"));

                if( (int)this_player()->query("qi") < 0 
                || !present(this_player(), environment())) {

say("云中鹤「哼」地一声，说道：便是有这许多不怕死的家伙....\n");
return 1;
                }
                say("\n云中鹤说道：第三招来了....\n\n");
                COMBAT_D->do_attack(this_object(), this_player(),
query_temp("weapon"));
                COMBAT_D->do_attack(this_object(), this_player(),
query_temp("weapon"));

                if( (int)this_player()->query("qi") < 0 
                || !present(this_player(), environment())) {

say("云中鹤叹道：没有漂亮小娘儿，我就宰了你....\n");
                        return 1;
                }

say("\n云中鹤翻了翻白眼说道：看不出你还有俩下子....\n");
                this_player()->set_temp("xixia/testpass", 2);
                this_player()->delete_temp("marks/西夏yun");
                return 1;
        }
        return 0;
}

