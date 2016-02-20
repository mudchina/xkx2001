//Cracked by Roath
// qianting.c
// qfy July 30, 1996.

inherit ROOM;

void create()
{
        set("short", "前厅");
	set("long", @LONG
前厅是供前来投师的子弟们登记所用。摆设仍然不俗。东西两排各摆着两
张红檀木的椅子和茶几，正中主人座位后更放有一面玉理石雕的屏风，刻着一
龙一虎，威猛已极。墙上又挂有几幅风水丹青，似乎是在显式主人并非纯是一
介武夫。拜师学艺的子弟们在此付过学费后便可进入后堂学习自己所感兴趣的
功夫。
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
            "west" : __DIR__"zoulang1",
            "east" : __DIR__"kaojiao",
	]));

        set("objects", ([ 
	    __DIR__"npc/mawude" : 1,	
        ]));

        set("no_clean_up", 0);
	set("valid_startroom",1);

	set("cost", 1);
        setup();

	"/clone/board/wuguan_b"->foo();
}
