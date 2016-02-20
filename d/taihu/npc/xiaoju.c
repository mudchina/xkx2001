//Cracked by Roath
// xiaolan.c

inherit NPC;

void create()
{
	set_name("小菊",({ "xiao ju", "ju" }) );
        set("gender", "女性" );
        set("age", 18);
        set("long", "一个模样乖巧的小丫环，瓜子脸，肤色白晰。细看时，嘴角有一颗小痣。\n");

//      set("shen", -100);
        set("shen_type", 1);
        set("str", 20);
        set("dex", 20);
        set("con", 20);
        set("int", 20);
        set("combat_exp", 2000);
        set_temp("apply/attack", 5);
        set_temp("apply/defense", 10);
        set("attitude", "peaceful");
        setup();

        carry_object("/d/taihu/obj/red_cloth")->wear();
	add_money("coin", random(1000));
}

