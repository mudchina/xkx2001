//Cracked by Roath
// Npc: /kungfu/class/emei/jingxu.c 静虚师太
// Date: xbc 99/09/24
// Modified by xQin 8/00
#include <ansi.h>
inherit NPC;
inherit F_MASTER;

string ask_for_huansu();
string ask_for_update();
string ask_for_join();
int auto_perform();

void create()
{
        set_name("静虚师太", ({
                "jingxu shitai",
                "jingxu",
                "shitai",
	}));
	set("long",
		"她是一位慈祥的中年师太，在华藏庵修行。\n"
		"她是灭绝师太的八大静字辈弟子之二，最擅指法和掌法。\n"
	);

	set("gender", "女性");
	set("attitude", "friendly");
	set("class", "bonze");

        set("inquiry",([
                "出家"  : (: ask_for_join :),
        ]));

	set("age", 38);
	set("shen_type", 1);

	set("str", 26);
	set("int", 20);
	set("con", 20);
	set("dex", 25);

	set("max_qi", 1200);
	set("max_jing", 1200);
	set("neili", 1300);
	set("max_neili", 1300);
	set("jiali", 70);
	set("combat_exp", 650000);
	set("score", 1000);

        set_skill("force", 120);
        set_skill("linji-zhuang", 120);
        set_skill("strike", 120);
        set_skill("jinding-zhang", 120);
        set_skill("finger", 120);
        set_skill("tiangang-zhi", 120);
//        set_skill("sword", 120);
//        set_skill("emei-jian", 120);
//        set_skill("blade", 120);
        set_skill("literate", 120);
        set_skill("parry", 100);
        set_skill("dodge", 110);
        set_skill("zhutian-bu", 110);
        set_skill("persuading", 120);
        set_skill("mahayana", 120);

        map_skill("force", "linji-zhuang");
        map_skill("strike", "jinding-zhang");
        map_skill("finger", "tiangang-zhi");
//        map_skill("sword", "emei-jian");
//        map_skill("blade", "yanxing-dao");
        map_skill("parry", "jinding-zhang");
        map_skill("dodge", "zhutian-bu");

	prepare_skill("strike", "jinding-zhang");
	prepare_skill("finger", "tiangang-zhi");

	create_family("峨嵋派", 4, "弟子");

        set("chat_chance_combat", 50);
        set("chat_msg_combat", ({
                (: auto_perform :),
        }) );

	set("inquiry",([
		"更新"  : (: ask_for_update :),
		"update"  : (: ask_for_update :),
		"还俗" : (:ask_for_huansu:),
	]));
	setup();

        carry_object("/d/emei/npc/obj/nun-cloth")->wear();
        carry_object("/d/emei/npc/obj/emei-shoes")->wear();
}

int do_nod(string arg)
{
        object me = this_player();

        if( !me->query_temp("pending/kao") )
                return 0;

	command("smile");
	command("say 我讲个故事你听：\n");

	message("vision", "静虚师太对着"+me->name()+"讲了几句话。\n",
                        environment(me), ({me}) );

        switch(random(2)) {
		case 0:
                write("静虚师太说：大承和尚曾住在峨嵋山。
            有个僧人问他：什么是胜峰？　大承说；直耸烟岚。
            僧人又问：向上事（即脱俗之事）如何？　他答：立地三尺五。
            僧人又问：什么是佛法？　他就说：兴义门前咚咚鼓。
            那僧说：这我不懂。　大承和尚是怎样回答他的呢？\n\n");

		if ((int)me->query_skill("mahayana", 1) > 60 + random(8)) {
			write("你想起在一部经书里读到过这个故事。\n");
			write("你说：朝打三千，暮打八百。\n\n");
			message("vision", me->name()+"想了一下，跟静虚师太说了几句话。\n",
				environment(me), ({me}) );

                	command("say 阿弥陀佛，善哉！善哉！好吧，我就收下你了。");
                	command("say 希望你能以慈悲之心，以智慧之力，努力行善，济度众生。\n");
                	command("recruit " + me->query("id"));
		}
		else {
			write("你想了许久，也解不明白其中的禅理。\n");
			command("say 阿弥陀佛，你多学些佛法后再来找我吧。\n");
		}
		break;

		case 1:
                write("静虚师太说：慧真广悟曾在峨嵋山出家。
            慧真广悟开堂那天，有个僧人出来问：什么是佛法大意？
            慧真广悟说：日出方知天下朗，无油哪点佛前灯？
            僧人又问：什么是双峰境？　慧真广悟是怎样回答他的呢？\n\n");

                if ((int)me->query_skill("mahayana", 1) > 60 + random(8)) {
                        write("你想起在一部经书里读到过这个典故。\n");
                        write("你答道：夜听水流庵后竹，昼起看云面前山。\n\n");
                        message("vision", me->name()+"想了一下，跟静虚师太说了几句话。\n",
                                environment(me), ({me}) );

                        command("say 阿弥陀佛，善哉！善哉！好吧，我就收下你了。");
                        command("say 希望你能以慈悲之心，以智慧之力，努力行善，济度众生。\n");
                        command("recruit " + me->query("id"));
                }
		else {
                        write("你想了许久，也解不明白其中的禅理。\n");
                	command("say 阿弥陀佛，你多学些佛法后在来找我吧。\n");
		}
               	break;
	}
        return 1;

} 
 

void init()
{
        object ob;

        add_action("do_kneel", "kneel");

/*	if( interactive(ob = this_player()) && !is_fighting() )
	{
		remove_call_out("ask_for_update");
		call_out("ask_for_update", 1, ob);
	}*/
        ::init();
        add_action("do_nod","nod");

        if (interactive(ob=this_player()) 
	&& ob->query("family/master_id") == "jingxu shitai"
	&& ob->query("shen") < -100) 
	{
       	 	message_vision(
                "$n看着$N说道：你怎么在外边做坏事？\n",
                ob, this_object() );
		command("say 我峨嵋派乃是堂堂名门正派，" +
                        "对弟子要求极严。我不能再收留你，你去吧。\n");
                command("expell " + ob->query("id"));
                return;
        }

        if (interactive(ob=this_player()) 
	&& ob->query("family/master_id") == "jingxu shitai"
        && ob->query("class") !=  "bonze" )                 
	{
		message_vision(
                        "$n看着$N说道：你既然还了俗，还是去找你俗家师叔学艺吧。\n");
                ob->delete("family/master_name");
                ob->delete("family/master_id");
                return;
        }
}

string ask_for_update()
{
	object me = this_player();
	mapping subpoint = me->query_learned();

	if( environment(me) != environment(this_object()) ) return "";

	if( me->query("emj_converted") ) return "不是已经给你更新过了？";
	if( (int)me->query_skill("huifeng-jian") < 1 ) return "你并不懂得峨嵋的剑法啊？";

	me->set_skill("emei-jian", me->query_skill("huifeng-jian", 1));
	me->improve_skill("emei-jian", subpoint["huifeng-jian"]);
	me->delete_skill("huifeng-jian");
	me->set("emei/emj_converted", 1);
	return HIY"恭喜！您的剑法已经更新为最新的峨嵋剑法2000版，旧的版本也将\n"
		"同时删除，请即时装备上最新的峨嵋剑法"NOR+CYN"(指令：enable sword emei-jian)。\n"NOR
		HIY"如果您有任何疑问，亦或新版本出现任何的运行或操作上的问题与\n"
		"错误，您都可以在此处张贴询问，取得与客户服务部技术人员的联系。\n"
		"再次感谢您对峨嵋派的惠顾。\n"NOR;
}

#include "/kungfu/class/emei/jing3.h"
#include "/kungfu/class/emei/auto_perform.h"
#include "/kungfu/class/emei/nun.h"

