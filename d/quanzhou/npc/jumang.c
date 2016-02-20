//Cracked by Roath
// animal: jumang.c

inherit NPC;

void create()
{
        set_name("巨蟒", ({ "ju mang", "she", "mang", "ju mang" }) );
        set("race", "蛇类");
        set("age", 100);
        set("long", "一条碗口粗细的三角头巨蟒，有两丈多长。\n");
        set("attitude", "peaceful");

        set("str", 32);
        set("cor", 36);
	set("max_jing", 1000);
	set("max_qi", 2000);

        set("limbs", ({ "头部", "身体", "七寸", "尾巴" }) );
        set("verbs", ({ "bite" }) );

        set("combat_exp", 500000);

        set_temp("apply/attack", 120);
        set_temp("apply/damage", 120);
        set_temp("apply/dodge", 100);
        set_temp("apply/armor", 100);

        setup();
}

void die()
{
        object ob;
        message_vision("$N全身扭曲，翻腾挥舞，终於僵直而死了。\n", this_object());
        ob = new(__DIR__"obj/shedan");
        ob->move(environment(this_object()));
        destruct(this_object());
}
