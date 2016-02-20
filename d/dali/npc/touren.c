//Cracked by Roath
// touren.c 族头人

inherit NPC;

void create()
{
	set_name("族头人", ({ "zu touren", "tou ren", "offical" }));
	set("long", "　　这位是哈尼的族头人，哈尼是大理国的第三大族，大多聚在大都附近。此人\n貌甚精明，身穿对襟衣，亦是白布包头。他坐在大土司的右下首，对来人细细打\n量着。\n");
	set("gender", "男性");
	set("age", 48);
	set("attitude", "peaceful");
	set("shen_type", 1);
	set("str", 26);
	set("int", 16);
	set("con", 22);
	set("dex", 24);
	set("combat_exp", 6000);
	set_skill("force", 30);
	set_skill("dodge", 30);
	set_skill("unarmed", 30);
	set_skill("parry", 30);
	setup();
	carry_object("/clone/armor/cloth")->wear();
}
