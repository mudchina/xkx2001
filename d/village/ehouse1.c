//Cracked by Roath
// Room: /d/village/shack.c

inherit ROOM;

void create()
{
        set("short", "草棚");
        set("long", @LONG
这是一个简单的草棚，地上摆著一堆堆的货物，上山的游客可以在这买些上山
用品。草棚的墙上贴着个牌子，是个价目表(sign)。
LONG
        );
        set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"eroad1",
]));
        set("objects", ([
                __DIR__"npc/seller": 1 ]) );
        set("item_desc", ([ /* sizeof() == 1 */
"sign" : "牌子上写道：
        木棒(stick)             一两白银
        麻鞋(shoes)             一百五十文
        水壶(bottle)            一两白银
        五香茶叶蛋(Spicy egg)   五十文铜板
        火折(fire)              一两白银
        绳子(sheng zi)          二两白银
        烤玉米(corn)            五十文铜板

        兼售 皮蛋(egg) 五十文，茶水(not yet) xx。 \n"
]));
        set("no_clean_up", 0);

        set("cost", 0);
        setup();
        replace_program(ROOM);
}
