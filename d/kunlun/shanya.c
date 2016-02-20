//Cracked by Roath
// room: /mingjiao/shanya.c
// Zhangchi 3/00

inherit ROOM;

void create()
{
        set("short", "山崖");
        set("long", @LONG
一道陡峭的悬崖拦住了你的去路，对山约在五十丈开外。低头向下一
望，深谷中却无云雾，只是一片黑沉沉地，深不见底，令人不禁头晕目眩。
LONG );

        set("exits", ([
                "southwest"   : __DIR__"shanlu4",
        ]));

        set("outdoors", "mingjiao" );
	set("cost", 2);

        setup();
        replace_program(ROOM);
}
