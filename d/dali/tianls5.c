//Cracked by Kafei
inherit ROOM;

void create()
{
        set("short", "斗母宫");
        set("long", @LONG
斗母宫占地宽大，殿周立有十二支柱，相征十二节气，木柱一丈来粗，
柱上涂的是泛着朱色的大紫，大殿无梁。整座大殿金壁辉煌，四周佛像多为
镀金，光轮上嵌了若干宝石。价值连城。殿门前的台阶也甚奇特，虽说一共
只有三三得九级，只有五尺高，九尺长，九尺宽，却是从一整块大理石雕凿
出的。
LONG
        );
        set("exits", ([
		"north" : __DIR__"tianls6.c",
        "southdown" : __DIR__"tianls4.c",		]));
set("no_clean_up", 0);
        set("cost", 2);
        setup();
        replace_program(ROOM);
}

