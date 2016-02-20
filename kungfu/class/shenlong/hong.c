//Cracked by Roath
// hong antong 洪安通
// modified by ALN 10 / 97

#include <ansi.h>
#include <localtime.h>

inherit NPC;
// inherit F_MASTER;

int ask_jiao();
int ask_wan();
int ask_dan();
string ask_skill();

void create()
{
	set_name("洪安通", ({ "hong antong","hong", "jiaozhu" }));
//      set("nickname", "");
	set("long",
		"年纪甚老，白鬓垂胸，脸上都是伤疤皱纹，丑陋之极。\n");
	set("gender", "男性");
	set("age", 51);
	set("attitude", "peaceful");
	set("shen_type", -1);
	set("str", 31);
	set("int", 32);
	set("con", 29);
	set("dex", 29);
	set("max_qi", 3500);
	set("max_jing", 3200);
	set("neili", 4000);
	set("max_neili", 4000);
	set("combat_exp", 3500000);
	set("jiali", 50);
	set("shen", -100000);

	set_skill("force", 400);
 	set_skill("dulong-dafa", 360);
	set_skill("dodge", 400);
	set_skill("lingshe-shenfa", 320);
	set_skill("strike", 400);
	set_skill("huagu-mianzhang", 360);
	set_skill("parry", 400);
	set_skill("medicine", 200);
	set_skill("yingxiong-sanzhao", 360);
	set_skill("literate", 160);
	set_skill("digging", 360);
	set_skill("kick", 240);
	set_skill("jueming-tui", 300);
	set_skill("finger", 280);

        set_temp("apply/attack", 100);
        set_temp("apply/damage", 100);
        set_temp("apply/dodge", 80);

	map_skill("force", "dulong-dafa");
	map_skill("dodge", "lingshe-shenfa");
	map_skill("strike", "huagu-mianzhang");
	map_skill("parry", "huagu-mianzhang");
//      map_skill("magic", "shenlong-magic");
	map_skill("finger", "yingxiong-sanzhao");

	prepare_skill("strike", "huagu-mianzhang");
	prepare_skill("kick", "jueming-tui");

	create_family("神龙教", 1, "教主");

	set("inquiry", ([
                "豹胎易筋丸" : (: ask_wan :),
                "天王保命丹" : (: ask_dan :),
		"神龙教" : (: ask_jiao :),
                "化骨绵掌" : (: ask_skill :),
                "skill" : (: ask_skill :),
	]));

	setup();

	carry_object("/clone/misc/cloth")->wear();
}

void init()
{
        ::init();

  //      add_action("do_flatter", "flatter");
}

int ask_wan()
{
        if( !this_player()->query("sg/spy") ) {
                command("consider " + this_player()->query("id"));
                return 1;
        }

        command("say 这种芝麻大的事，也用得着找我？");
        return 1;
}

int ask_jiao()
{
        if( !this_player()->query("sg/spy") ) {
                command("consider " + this_player()->query("id"));
                return 1;
        }

        command("say 关于教中的杂事，你去问瘦头陀。");
        return 1;
}

int ask_dan()
{
        object ob, me = this_player();

        if( !me->query("sg/spy") ) {
                command("consider " + ob->query("id"));
                return 1;
        }

        if( (int)me->query("sg/exp") < 100 ) {
                command("say 就凭你在教中的表现，也有脸来要天王保命丹？");
                return 1;
        }

        if( time() < (int)me->query("bmdan_time") + 1800 ) {
                command("say 你太贪了，刚要过又来要丹。");
                return 1;
        }

        command("say 好吧，不过得消减你的神龙功劳点。");
        ob = new(DRUG_D("bmdan"));
        ob->move(me);
        me->set("bmdan_time", time());
        message_vision("$N给了$n一" + ob->query("unit") + ob->name() + "。\n", this_object(), me);
        command("say 务必在最危急的关头服用。");
        return 1;
}

int do_flatter(string arg)
{
        object ob = this_player();

        if( !arg ) return notify_fail("你要说什么？\n");

        if( arg != "hong"  && arg != "洪安通"
        &&  arg != "jiaozhu" && arg != "教主" )
                return notify_fail("你要拍谁？\n");

        if( !ob->query("sg/spy") ) {
                message_vision("$N厚脸无耻地说道：祝洪教主早日一统江湖，泽被苍生！！！\n", ob);
                command("haha");
                command("say 想不到老夫在江湖中有如此盛名，哈！哈！哈！\n");
                return 1;
        }

        message_vision("$N高举右手，叫道：「洪教主万年不老，永享仙福，寿与天齐！」\n", ob);
        command("nod");

        if( random((int)ob->query("kar")) > 9 
        && (int)ob->query("sg/exp") >= 100
        && ob->query("sgjob") ) {
                command("smile");
                ob->delete("sgjob");
                command("say 完不成一次教务算不了什么大事，下次努力吧。\n");
        }

        if( time() > (int)ob->query_temp("flatter_time") + 900 ) {
                ob->add_temp("flatter_bonus", 1);
                ob->set_temp("flatter_time", time());
        }

        return 1;
}

string ask_skill()
{
        object me = this_player();

        if( me->query("sg/cured") ) 
                return "无耻的叛徒，还不给我滚！！！";

        if( !me->query("sg/spy") )
                return "这是敝教的秘密，有什么好问的？！";

        if( (int)me->query("sg/exp") < 5000 )
                return "就凭你在教中的表现，我怎么能传授你本教秘技？";

        if( (int)me->query_skill("huagu-mianzhang", 1) >= 30 )
                return "你还是去练功房练习吧。";

        command("nod");
        me->set_skill("huagu-mianzhang", 30);

        message_vision(HIB"\n$N的化骨绵掌进步了！！！\n\n", me);

        return "好！你在本教功绩显赫，我就传授你这本教秘技吧。";
}
