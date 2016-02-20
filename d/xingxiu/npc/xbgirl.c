//Cracked by Roath
// ryu

inherit NPC;

void create()
{
        set_name("锡伯少女", ({ "girl" }) );
        set("gender", "女性" );
        set("age", 18);
        set("long", "一个身姿婀娜的锡伯族少女。\n");
        set("shen", 1000);
        set("combat_exp", 300);
        set("str", 19);
        set("dex", 25);
        set("con", 18);
        set("int", 13);
        set("attitude", "friendly");
        setup();
        set("chat_chance", 2);
        set("chat_msg", ({
                "锡伯少女看着你笑了起来\n",
                "锡伯少女轻轻地唱道：在野云沟，库尔楚以南，骑骆驼要走两天的之遥的沙漠中，\n"
		"有个神秘去处，叫夏里苦岱克。\n",
        }) );
        carry_object(__DIR__"obj/chouqun")->wear();
	carry_object(__DIR__"obj/hulu");
}

