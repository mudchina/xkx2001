//Cracked by Roath
// yellowdog.c

inherit NPC_TRAINEE;

void create()
{
        set_name("小黄狗", ({ "dog" }) );
        set("race", "野兽");
        set("age", 3);
        set("long", "一只极可爱的小黄狗。\n");
        
        set("str", 32);
        set("dex", 36);
        set("wildness", 2);

        set("limbs", ({ "头部", "身体", "前脚", "後脚", "尾巴" }) );
        set("verbs", ({ "bite", "claw" }) );

        set("chat_chance", 6);
        set("chat_msg", ({
                (: this_object(), "random_move" :),
                "小黄狗用鼻子闻了闻你的脚。\n",
                "小黄狗对著你摇了摇尾巴。\n" }) );
                
        set_temp("apply/attack", 10);
        set_temp("apply/armor", 3);

        setup();
}

int accept_object(object who, object ob)
{
        if( ob->id("bone") ) {
                set_leader(who);
                message("vision", name() + "高兴地汪汪叫了起来。\n", environment());
                return 1;
        }
}
