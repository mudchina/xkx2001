//Cracked by Roath
// bypanguan.c 摆夷判官

inherit NPC;

void create()
{
	set_name("摆夷判官", ({ "pan guan", "pan" }));
	set("long", "　　定安府五大判官之一，官服打扮与中原甚有渊源，唯独颇为洒脱，与中原官\n场人氏之淤昵不清不可相提并论。摆夷判官是定安府第二把手，处理百姓纠纷，\n盘问审讯，颇为老成。只见他头带青冠，身袭长衫，脚蹬布履，精明之色顿显脸\n上。\n");
	set("gender", "男性");
	set("age", 50+random(10));
	set("attitude", "peaceful");
	set("shen_type", 1);
	set("str", 26);
	set("int", 16);
	set("con", 22);
	set("dex", 24);
	set("combat_exp", 70000+random(20000));
	set("dalinpc",1);
	set_skill("force", 60);
	set_skill("dodge", 60);
	set_skill("unarmed", 60);
	set_skill("parry", 60);
	setup();
	carry_object("/clone/armor/cloth")->wear();
}
