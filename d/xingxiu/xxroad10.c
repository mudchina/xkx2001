//Cracked by Roath
// Room: /d/xingxiu/xxroad10.c

inherit ROOM;

void create()
{
        set("short", "山谷深处");
        set("long", @LONG
山谷深处，人迹罕见，到处是荒草枯树乱石，朔风萧杀，令人心惊胆颤。
南边是山间荒地，西北边黑黝黝好象有一个山洞。
LONG
        );

        set("resource/water", 1);
	set("bing_can", 3);

        set("exits", ([
  "northwest" : __DIR__"xxcave",
  "southup" : __DIR__"xxroad9",
]));

        set("no_clean_up", 0);
        set("outdoors", "xingxiuhai");

	set("cost", 2);
        setup();
        replace_program(ROOM);
}
