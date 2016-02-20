//Cracked by Roath
// shinu.c 白驼山庄舞女

inherit NPC;

void create()
{
        set_name("白衣舞姬", ({ "baiyi wuji","wuji","ji" }));
        set("long", "一个肤色白皙的西域女子，金发碧眼，高鼻深目，和中土女子大不相同，\n但容貌艳丽，姿态妖媚，亦自动人。\n");
        set("gender", "女性");
        set("age", 22);

        set_skill("hand", 10);
        set_skill("dodge", 10);
        set_skill("parry", 10);
        set_skill("force", 10);

        set("str", 20);
        set("int", 22);
        set("con", 20);
        set("dex", 20);

        set("max_neili", 200);
        set("combat_exp", 3000);

        set("attitude", "peaceful");
	set("chat_chance", 5);
        set("chat_msg", ({
	"白衣舞姬前伏后起，左回右旋，身子柔软已极，恍似一条长蛇。\n",
	"白衣舞姬双臂伸展，自左手指尖至右手指尖，扭扭曲曲，有如一条蜿蜒游动的蛇一般。\n",
	"白衣舞姬翩翩起舞，媚态百出，变幻多端，跟着双手虚抚胸臀，作出宽衣解带、投怀送抱的诸般姿态。\n",
	}) );
	setup();
	carry_object("/d/xingxiu/obj/wcloth")->wear();
}
