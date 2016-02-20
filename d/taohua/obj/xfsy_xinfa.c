//Cracked by Roath
inherit ITEM;

void create()
{
        set_name("旋风扫叶腿心法", ({"xin fa", "book", "fa"}));
        set_weight(100);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "张");
                set("long",
"一张薄纸，上面密密麻麻写满了蝇头小楷。\n");
                set("material", "paper");
                set("skill", ([
                        "name": "kick", // name of the skill
                        "exp_required": 0,      // minimum combat
                        "jing_cost": 10,        // jing cost every time
                        "difficulty":   20,     // the base int to learn
                        "max_skill":    30,    // the maximum level you
                ]) );
        }
}

