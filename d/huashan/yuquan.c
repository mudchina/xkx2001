//Cracked by Roath
// yuquan.c

inherit ROOM;

void create()
{
        set("short", "玉泉院");
	set("long", @LONG
这里因屋后的玉泉而得名，是宋代陈希夷隐居的地方。周围生着十二
株大龙藤，夭矫多姿，枝干中空，就如飞龙相似，相传是希夷先生陈抟老
祖所植。
LONG
        );
        set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"path1",
]));
        set("no_clean_up", 0);
        set("objects", ([
                __DIR__"npc/teller": 1 ]) );

	set("cost", 1);
        setup();
        replace_program(ROOM);
}
 
