//Cracked by Roath
// /d/emei/npc/cow.c
// Shan: 96/07/09

inherit NPC;

void create()
{
        set_name("大黄牛", ({ "cow", "niu", "huang niu" }) );
        set("race", "家畜");
        set("age", 11);
        set("long", "一头瘦骨嶙峋的大黄牛，不知是谁家的，正低头认真地吃着草。\n");

        set("str", 26);
        set("cor", 30);

        set("combat_exp", 1000);

//      set("chat_chance", 6);
//      set("chat_msg", ({
//              (: this_object(), "random_move" :),
//      }) );

        set_temp("apply/attack", 15);
        set_temp("apply/damage", 6);
        set_temp("apply/armor", 2);

        setup();
}

void die()
{
        object ob;
        message_vision("$N倒在地上，哼了几哼就死了！\n", this_object());
        ob = new(__DIR__"obj/beef");
        ob->move(environment(this_object()));
        ob = new(__DIR__"obj/niupi");
        ob->move(environment(this_object()));
        destruct(this_object());
}

