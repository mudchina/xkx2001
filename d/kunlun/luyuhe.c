//Cracked by Roath
// room: /mingjiao/luyuhe.c

inherit ROOM;

void create()
{
        set("short", "绿玉河");
        set("long", @LONG
地势一转，现出一条纵贯南北的的河流。但见那河水也不甚急，清可
见底，一群群小鱼穿急而过。两岸树木多低垂入水，也有不少枝叶随水飘
浮，映得整条河都呈现碧绿之色。岸边道路十分泥泞，想必河水泛滥之故。
LONG );

        set("exits", ([
                "westup" : __DIR__"daqing",
                "north" : __DIR__"yanrandu",
        ]));

        set("outdoors", "mingjiao" );
	set("resource/water", 1);
	set("cost", 1);

        setup();
        replace_program(ROOM);
}