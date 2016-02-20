//Cracked by Roath
// /d/changbai/npc/mo-1.c

inherit NPC;

string ask_brother();

void create()
{
        set_name("滕一雷", ({ "teng yilei", "teng" }));
        set("nickname", "关东大魔");
        set("long",
"他就是关东大魔滕一雷。\n"
"辽东大豪，家资累万，开了不少参场、牧场和金矿。\n");
        set("gender", "男性");
        set("age", 45);
        set("attitude", "heroism");
        set("shen_type", -1);

        set("str", 35);
        set("int", 20);
        set("con", 30);
        set("dex", 20);

        set("max_qi", 900);
        set("max_jing", 600);
        set("neili", 900);
        set("max_neili", 900);
        set("jiali", 30);
        set("combat_exp", 400000);
        set("score", 20000);

        set_skill("force", 100);
        set_skill("dodge", 120);
        set_skill("parry", 120);
        set_skill("cuff", 120);
        set_skill("club", 150);
        set_skill("wuxingbu", 100);
        set_skill("wuxing-quan", 100);
        set_skill("weituo-gun", 150);
        set_skill("ding-force", 100);

        map_skill("force", "ding-force");
        map_skill("dodge", "wuxingbu");
        map_skill("parry", "weituo-gun");
        map_skill("club", "weituo-gun");
        map_skill("cuff", "wuxing-quan");

        prepare_skill("cuff", "wuxing-quan");

        set("chat_chance", 5);
        set("chat_msg", ({
"滕一雷叹道：听说三弟焦文期受托找寻一个被红花会拐去的贵公子而突然失踪了。\n",
        }));

        set("inquiry", ([
                "焦文期" : "我也不知道他到底是不是死了。",
                "红花会" : "我正想找红花会打听三弟的消息。",
        ]));

        setup();

        carry_object("/d/changbai/obj/tongren")->wield();
        carry_object("/d/xingxiu/obj/diaoqiu")->wear();
}

int accept_object(object who, object ob)
{
        object *obs, obj;

        if( base_name(ob) != "/d/changbai/obj/tiepai" )
                return 0;

        say("滕一雷大叫道：这是我三弟焦文期的兵器。\n");
        command("cry");

        obs = filter_array(children(__DIR__"club_book"), (: clonep :));
        if( !sizeof(obs) )
                obj = new(__DIR__"club_book");
        else    obj = new(DRUG_D("cb_renshen"));

        obj->move(this_player());

        message_vision("滕一雷从怀里拿出一" + obj->query("unit") + obj->query("name") + "交给$N。\n", this_player());

        say("滕一雷说道：多谢你给了我三弟的消息。\n");
        call_out("do_destroy", 1, ob);
        return 1;
}        

void do_destroy(object ob)
{
        destruct(ob);
}
