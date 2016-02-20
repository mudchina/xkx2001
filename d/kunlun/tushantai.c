//Cracked by Roath
// room: /mingjiao/tushantai.c

inherit ROOM;

void create()
{
        set("short", "土山台");
        set("long", @LONG
起伏的山间，排列着数个烽火台，有的已经残缺不堪，甚至坍塌了半
边。汉唐两朝鼎盛之时，此地均曾有驻军把守，现在是今非昔比了。林中
不时响起几声呜呜的狼嗥，令人毛骨悚然。
LONG );

        set("exits", ([
                "southup" : __DIR__"monan",
                "north" : __DIR__"yinshandao",
        ]));

        set("outdoors", "mingjiao" );
	set("resource/grass", 1);
	set("cost", 1);

        setup();
        replace_program(ROOM);
}