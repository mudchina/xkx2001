//Cracked by Roath
// room: /mingjiao/xingzi.c
// Zhangchi 3/00

inherit ROOM;

void create()
{
        set("short", "星子山");
        set("long", @LONG
地上渐渐有了终年不化的积雪，阳光照耀之下，十分刺眼。强风吹过，
已经颇有寒意。不知为何，你开始感到有些心慌气喘，头晕目眩，每走几
步就不得不停下来休息。周围已经没有树木，脚下都是一些贴地生长的小
草。
LONG );

        set("exits", ([
                "southdown" : __DIR__"longquangu",
                "westdown" : __DIR__"xinkaiquan",
                "northup" : __DIR__"badake",
        ]));

        set("outdoors", "mingjiao" );
	set("resource/grass", 1);
	set("cost", 2);

        setup();
        replace_program(ROOM);
}