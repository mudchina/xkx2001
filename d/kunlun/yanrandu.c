//Cracked by Roath
// room: /mingjiao/yanrandu.c

inherit ROOM;

void create()
{
        set("short", "燕然渡");
        set("long", @LONG
这里河面不宽，地势也较为平稳，好象是一个渡口，可是看上去已经
破旧不堪。岸边有一些踏板木桩之类，采上去吱吱嘎噶地作响。在岸边一
站，半晌也不见一个船影。
LONG );

        set("exits", ([
                "north" : __DIR__"tongtianhe",
                "east" : __DIR__"luobuyi",
                "south" : __DIR__"luyuhe",
        ]));

        set("outdoors", "mingjiao" );
	set("cost", 1);

        setup();
        replace_program(ROOM);
}