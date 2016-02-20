//Cracked by Roath
// Carriage2: /clone/obj/car2.c 大马车里
// Date: xbc /04/14/97

inherit ITEM;

void create()
{
        set_name("大马车里", ({ "da che", "che", "carriage" }) );
        set_weight(3000000);
        set_max_encumbrance(5000000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "个");
                set("long", @LONG

大车里 - 
　　车里陈设富丽，脚下铺着厚厚的地毯，一只小桌上摆满茶果细点。一张
舒服的大床，上面放了一床红绸面的被子。窗帘拉了下来，阳光从缝隙中透
进来，不知道车子走到哪里了，你们只盼这辆大车如此不停行走，走到天涯
海角，回过头来，又到彼端的天涯海角，天下的道路永远行走不完，就算走
完了，老路再走几遍又有何妨？
　　如此天天行了又宿，宿了又行，只怕车夫忽然说已经到了。身处温柔乡
中，迷迷糊糊的不知时日之过，道路之遥。

LONG
	);

                set("amount",30);
        }
        setup();
}

int is_container() { return 1; }

