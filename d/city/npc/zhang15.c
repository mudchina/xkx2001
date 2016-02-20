//Cracked by Roath
// /d/city/npc/zhang15.c 

inherit NPC;

void create()
{
        set_name("张十五", ({"zhang shiwu","zhang"}) );
        set("title", "「说书先生」");
        set("gender", "男性" );
        set("age", 52);
        set("long", "此人手中两片梨花板碰了几下，左手中竹棒在一面小羯鼓上敲起得得连声。\n");
        set("combat_exp", 500);
        set("attitude", "heroism");
        set("chat_chance", 6);
        set("chat_msg", ({
       "张十五将木板敲了几下，说道：战国时，秦穆公讨伐晋国，来到河边，秦穆公打算犒劳将士，以鼓
舞将士，但酒醪却仅有一钟，有人说，即使只有一粒米，投入河中酿酒，也可使大家分享，于是秦穆
公将这一钟酒倒入河中，三军饮后都醉了。\n",

       "张十五说道：帝王因酒误事有时也是好事，如齐桓公因为醉酒，将帽子丢了，齐桓公为此事感到
羞耻，于是三天都不上朝，恰逢粮荒，管仲只好自作主张，打开公家的粮仓，救济灾民。灾民欣
喜若狂，当时流传的民谣说：为什么齐桓公不再丢一次帽子啊！所以酒这个东西啊，好的很！\n",

       "张十五叹道：“天生张十五，以酒为名，一饮一斛，五斗解酲。”\n",
	}) );
        setup();

        carry_object("/d/forest/npc/obj/gebu-changpao")->wear();
        add_money("coin", random(200));
}

