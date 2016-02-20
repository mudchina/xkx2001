//Cracked by Roath
// room: /mingjiao/lingjia.c

inherit ROOM;

void create()
{
        set("short", "陵伽山");
        set("long", @LONG
周围的树林东一丛，西一丛，甚是杂乱。脚下一条窄窄的小路蜿蜒曲
折地向前延伸，大概是往来的樵夫或商旅踩出的。仔细看还能发现一些牲
畜的粪便，却是驼队过后的痕迹。西面山势较为平缓，北面则甚是陡峭。
LONG );

        set("exits", ([
                "eastup" : __DIR__"zishan",
                "northup" : __DIR__"jishi",
                "westdown" : __DIR__"yananshan",
        ]));

        set("outdoors", "mingjiao" );
	set("resource/grass", 1);
	set("cost", 1);

        setup();
        replace_program(ROOM);
}