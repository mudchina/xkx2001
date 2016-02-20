//Cracked by Roath
inherit NPC;

void create()
{
        set_name("族头人", ({ "zu touren", "offial" }));
        set("long", 
"这位是白尼的族头人，源于皇族乃是白尼，白尼官员虽不居高位，\n"
"却掌握着大理的命脉实权。这名官员衣着与大土司相较下，大为逊色，\n"
"不外乎只是一身白色对襟衣及黑领褂，和一头颇为显眼的白包头。他 \n"
"坐在大土司的左下首，对来人喊开话来。\n");
        set("gender", "男性");
        set("age",50 );
        set("attitude", "peaceful");
        set("shen_type", 1);
        set("str", 26);
        set("int", 16);
        set("con", 22);
        set("dex", 24);

        set("combat_exp", 7000+random(2300));

        set_skill("force", 40);
        set_skill("dodge", 35);
        set_skill("unarmed", 50);
        set_skill("parry", 60);
        setup();


	 carry_object("/u/dali/npc/obj/baicloth")->wear();

}


