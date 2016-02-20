//Cracked by Roath
// /d/huange/npc/tc_wang.c

#define TIECHA  "/d/huanghe/obj/tiecha"

inherit NPC;

string ask_join();

void create()
{
        set_name("王老六", ({ "wang laoliu", "wang" }));
        set("title", "铁叉帮小头目");
        set("long",
"他是一位三十多岁的彪形大汉。\n");
        set("gender", "男性");
        set("age", 35);
        set("attitude", "friendly");
        set("shen_type", -1);
        set("str", 25);
        set("int", 20);
        set("con", 25);
        set("dex", 25);

        set("max_qi", 500);
        set("max_jing", 400);
        set("max_neili", 400);
        set("neili", 400);
        set("jiali", 25);
        set("combat_exp", 50000);
        set("score", 2000);

        set_temp("apply/armor", 20);

        set_skill("force", 65);
        set_skill("dodge", 65);
        set_skill("parry", 65);
        set_skill("cuff",  65);
        set_skill("pike",  65);

        set_skill("ding-force", 65);
        set_skill("wuxingbu", 65);
        set_skill("wuxing-quan", 65);
        set_skill("liuhe-qiang", 70);

        map_skill("force", "ding-force");
        map_skill("dodge", "wuxingbu");
        map_skill("cuff", "wuxing-quan");
        map_skill("parry", "liuhe-qiang");
        map_skill("pike", "liuhe-qiang");

        prepare_skill("cuff", "wuxing-quan");

        set("inquiry", ([
                "铁叉帮" : "咱们铁叉帮横行黄河两岸，天不怕，地不怕，连皇帝老儿都不买他的帐。",
                "尤得胜" : "我家帮主尤大爷乃是山西‘伏虎门’的惟一传人，叉法绝世无双。",
                "赏善罚恶使者" : "赏善罚恶使者重入江湖，大伙儿便吓得夹起尾巴，躲到渔村中去做缩头乌龟！",
                "侠客岛" : "他妈的侠客岛什么赏善罚恶使者，老子不怕！",
                "胡大哥" : "胡大哥在弊帮劳苦功高，颇得帮主信任。",
                "入帮" : (: ask_join :),
        ]));

        setup();

        carry_object("/clone/weapon/sangucha")->wield();
}

int accept_object(object who, object ob)
{
        object obj;

        if( base_name(ob) != CORPSE_OB ) return 0;

        if( ob->query("my_killer") != who->query("id") ) {
                say("王老六大怒道：你当我是二愣子？！滚！！！\n");
                return 0;
        }

        if( ob->query("combat_exp") < who->query("combat_exp") ) {
                command("sigh");
                command("say 欺软怕硬的东西，你还是滚吧！");
                return 0;
        }

        if( who->query_temp("bangs/fam") == "铁叉帮" ) {
                command("bored " + who->query("id"));
                command("say 都已经是兄弟了，谁还不知道谁？");
                return 0;
        }

        command("nod");

        obj = new(TIECHA);
        obj->move(who);
        who->set_temp("tc_wang", 1);
        message_vision("$N将一只小铁叉交给$n。\n", this_object(), who);
        command("say 好样的！凭这小铁叉你就可以去求见帮主了。\n");
        call_out("do_destroy", 1, ob);
        return 1;
}

void do_destory(object ob)
{
        if( ob ) destruct(ob);
}

string ask_join()
{
        object me  = this_player();

        if( me->query_temp("bangs/fam") == "铁叉帮" )
	        return "你无聊不无聊？！";

        if( (int)me->query("combat_exp") > 100000 ) 
                return "你莫非是开玩笑吧？！";

        if( me->query_temp("tc_wang") )
                return "我不是已经给你信物，让你去见帮主了吗？！";

        return "也不知道你胆子大不大，去杀个人弄具尸体来。";
}
