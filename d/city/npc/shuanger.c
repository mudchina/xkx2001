//Cracked by Roath
//  双儿
// kane

#include <ansi.h>
#include <dbase.h>
inherit NPC;

string ask_me();
int do_repair(string arg);

void create()
{
        set_name("双儿", ({ "shuang er", "shuanger", "shuang"}));
        set("title", "鹿鼎公夫人");
        set("long",
"她是当朝鹿鼎公韦公爷的七位夫人之一，是七位夫人中最温柔善良，\n"
"善解人意的一位。她看起来虽不大爱说话，但却武艺高强\n");
        set("gender", "女性");
        set("age", 20);
        set("attitude", "peaceful");
        set("shen_type", 1);
        set("str", 22);
        set("int", 26);
        set("con", 26);
        set("dex", 29);

        set("max_qi", 800);
        set("max_jing", 500);
        set("neili", 800);
        set("max_neili", 800);
        set("jiali", 30);
        set("combat_exp", 50000);
        set("score", 5000);

        set_skill("force", 80);
        set_skill("zixia-gong", 80);
        set_skill("dodge", 80);
        set_skill("parry", 80);
        set_skill("strike", 80);
        set_skill("hunyuan-zhang", 80);
        set_skill("huashan-shenfa", 80);
        set_skill("cuff", 80);
        set_skill("pishi-poyu", 80);

        map_skill("cuff", "pishi-poyu");
        map_skill("force", "zixia-gong");
        map_skill("parry", "huashan-jianfa");
        map_skill("strike", "hunyuan-zhang");
        map_skill("dodge", "huashan-shenfa");

        prepare_skill("strike", "hunyuan-zhang");
        prepare_skill("cuff", "pishi-poyu");

        set("inquiry", ([
                "修补"     : (: ask_me :),
                "缝补"     : (: ask_me :),
                "修理"   : (: ask_me :)
        ]));

        setup();
        carry_object("/d/city/obj/pink_cloth")->wear();
        carry_object("/d/city/obj/necklace")->wear();
}

void init()
{
        add_action("do_repair", "repair");
}

string ask_me()
{
        object me = this_player();

        if (query_temp("busy"))
                return "哟，抱歉啊，我这儿正忙着呢……您请稍候。\n";
        if (!me->query_temp("allow_repair"))
                return "这位"+RANK_D->query_respect(me)+"您请先付五两白银。\n";

        me->set_temp("pending/sewing", 1);
        return "不知道这位"+RANK_D->query_respect(me)+"需要我补(repair)些什麽？\n"; }

int do_repair(string arg)
{
        object obj,me;
        string file;

        me = this_player();

	if (!arg) return notify_fail("你要补什么东西？\n");        

	if( !objectp(obj = present(arg, me)) )
                return notify_fail("你要补什么东西？\n");

        if (!obj->query("armor_prop/armor") || obj->query("armor_prop/armor")<1)
                return notify_fail("这东西能补吗？\n");

        set_temp("busy",1);
        start_busy(2);
        file = resolve_path(this_object()->query("cwd"),arg);
        file = base_name(obj)+".c";

        remove_call_out("destroy_ob");
        call_out("destroy_ob", 1, obj);

        obj = new(file);
        write("双儿吁了一口长气，说道：“补好了，拿去吧，下次小心点哦。\n");
        obj->move(me);
	me->delete_temp("allow_repair");

        remove_call_out("enough_rest");
        call_out("enough_rest", 2);

        return 1;
}

void enough_rest()
{
        delete_temp("busy");
}

int accept_object(object me, object ob)
{
        command("smile");
	command("say 真是多谢" + RANK_D->query_respect(me) + "您了 ！");

        if(ob->query("money_id") && ob->value() >= 500)
                me->set_temp("allow_repair", 1);

        remove_call_out("destroy_ob");
        call_out("destroy_ob", 1, ob);

        return 1;
}

void destroy_ob(object ob)
{
        if (ob) destruct(ob);
}
