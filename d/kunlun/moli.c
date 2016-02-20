//Cracked by Roath
// room: /mingjiao/moli.c

inherit ROOM;

void create()
{
        set("short", "摩黎山");
        set("long", @LONG
山脚下一片黑压压的密林之中，几乎暗无天日。周围草木与中土大相
径庭，大都叫不上名字。耳边隐约传来咆哮之声，时远时近，加之阵阵腐
臭气味袭来，引得人烦恶欲吐。脚下十分松软，你凝神向地上观看时，竟
然发现几块埋在落叶中的白骨！
LONG );
        set("exits", ([
                "south" : __DIR__"suibei",
        ]));

	set("objects",([
		__DIR__"obj/xiaohuangshi" : 2,
]));
        set("outdoors", "mingjiao" );
	set("resource/grass", 3);
	set("cost", 3);

        setup();
        replace_program(ROOM);
}