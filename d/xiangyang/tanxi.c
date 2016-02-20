//Cracked by Roath
// Room: /d/xiangyang/tanxi.c

inherit ROOM;

void create()
{
        set("short", "马越檀溪处");
        set("long", @LONG
相传东汉末年，蔡瑁与蒯越合谋欲杀刘备。有人告知，刘备不辞而别，逃至
溪边，无人摆渡，马蹄陷入泥中。追兵将至，刘备鞭骑大呼，的卢一跃而起飞过
溪去，在岩石上留下一深深的蹄窝，至今仍清晰可见。
LONG
        );
        set("outdoors", "xiangyang");
        set("no_clean_up", 0);
        set("coordinates", ([ "x" : -10, "y" : 0 ]) );
        set("exits", ([ /* sizeof() == 2 */
  "eastdown" : __DIR__"tulu3",
  "west" : __DIR__"diluqiao",
]));

        setup();
        replace_program(ROOM);
}
