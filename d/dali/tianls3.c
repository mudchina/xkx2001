//Cracked by Kafei
inherit ROOM;

void create()
{
        set("short", "幌天门");
        set("long", @LONG
这里是天龙寺的前庭，向北是清都瑶台。青石道俩旁耸立了两颗齐天梧桐，
绿叶幽幽，整个庭院清爽无比。碎石铺路，黄土奠基。院内没有五艳六色的花
卉，没有渲闹的人群，甚至没有僧人们朗朗的念经声，只有一片寂静。然而在
这片寂静中，却有隐藏着一种强烈的生命力。
LONG
        );
        set("no_clean_up", 0);
        set("exits", ([
		"northup" : __DIR__"tianls4.c",
        "westdown" : __DIR__"tianls2.c",		]));
 set("cost", 3);
        setup();
        replace_program(ROOM);
}

