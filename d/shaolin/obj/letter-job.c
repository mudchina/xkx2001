//Cracked by Roath
// letter-job.c 推荐信 

inherit ITEM;

void create()
{
        set_name("推荐信", ({"tuijian xin", "xin", "letter"}));
        set_weight(100);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "封");
                set("long", "这是一封玄慈方丈写给龙门镖局都总镖头的推荐信。\n");
                set("no_drop", "这样东西不能离开你。\n");
                set("material", "paper");
        }
}

