//Cracked by Kafei
inherit ROOM;

void create()
{
        set("short", "小路");
        set("long", @LONG
过海洋般的茶树林，可以远远地望见一排苍绿的松柏，参天而
立。走近些，一股清爽之意扑面而至，树阴挡炎，轻风挲挲。再走近
些，就可以嗅到寺院惯有的松香，松柏丛间，露出一角飞筵，精雕细
琢，共具天竺与中原的特征。
LONG
        );
        set("exits", ([
		"out" : __DIR__"tianls1.c",
        "enter" : __DIR__"tianls2.c",		]));
set("no_clean_up", 0);
        set("cost", 3);
        setup();
        replace_program(ROOM);
}

