//Cracked by Roath
// Jay 8/9/96

inherit NPC;

void create()
{
        set_name("锺小二", ({ "zhong xiaoer", "zhong", "xiaoer" }) );
        set("gender", "男性" );
        set("age", 13);
        set("long", 
	     "这是个十二三岁的孩子，赤着双足，衣裤已被恶狗的爪牙撕得稀烂，身后一路滴着鲜血。\n");
        set("shen_type", 1);

        set("combat_exp", 100);

        set("attitude", "friendly");

        setup();
        carry_object("/clone/armor/cloth")->wear();
}
